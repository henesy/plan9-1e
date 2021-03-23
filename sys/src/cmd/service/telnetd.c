#include <u.h>
#include <libc.h>
#include <bio.h>
#include <auth.h>

#include "../ip/telnet.h"

/*  console state (for consctl) */
typedef struct Consstate	Consstate;
struct Consstate{
	int raw;
	int hold;
};
Consstate *cons;

int notefd;		/* for sending notes to the child */
int noproto;		/* true if we shouldn't be using the telnet protocol */
int trusted;		/* true if we need not authenticate - current user
				is ok */
int nonone;		/* don't allow none logins */

/* input and output buffers for network connection */
Biobuf	netib;
Biobuf	childib;

int	alnum(int);
int	conssim(void);
int	fromchild(char*, int);
int	fromnet(char*, int);
int	termchange(Biobuf*, int);
int	termsub(Biobuf*, uchar*, int);
int	xlocchange(Biobuf*, int);
int	xlocsub(Biobuf*, uchar*, int);
int	challuser(char*);
void*	share(int);


void
main(int argc, char *argv[])
{
	char buf[1024];
	int fd;
	char user[NAMELEN];
	int tries = 0;
	int childpid;
	int n;

	memset(user, 0, sizeof(user));
	ARGBEGIN {
	case 'n':
		opt[Echo].local = 1;
		noproto = 1;
		break;
	case 'N':
		nonone = 1;
		break;
	case 't':
		trusted = 1;
		strncpy(user, getuser(), NAMELEN-1);
		break;
	case 'u':
		strncpy(user, ARGF(), sizeof(user)-1);
		break;
	case 'D':
		debug = 1;
		break;
	} ARGEND
	USED(argc, argv);

	/* options we need routines for */
	opt[Term].change = termchange;
	opt[Term].sub = termsub;
	opt[Xloc].sub = xlocsub;

	/* setup default telnet options */
	if(!noproto){
		send3(1, Iac, Will, Echo);
		send3(1, Iac, Do, Term);
		send3(1, Iac, Do, Xloc);
	}

	/* shared data for console state */
	cons = share(sizeof(Consstate));
	if(cons == 0)
		fatal("shared memory", 0, 0);

	/* authenticate and create new name space */
	Binit(&netib, 0, OREAD);
	if (!trusted){
		while(challuser(user) < 0)
			if(++tries == 5)
				exits("authentication");
	}
	newns(user, 0);
	putenv("service", "con");

	/* simulate /dev/consctl and /dev/cons using pipes */
	fd = conssim();
	if(fd < 0)
		fatal("simulating", 0, 0);
	Binit(&childib, fd, OREAD);

	/* start a shell in a different process group */
	switch(childpid = rfork(RFPROC|RFNAMEG|RFFDG|RFNOTEG)){
	case -1:
		fatal("fork", 0, 0);
	case 0:
		fd = open("/dev/cons", OREAD);
		dup(fd, 0);
		close(fd);
		fd = open("/dev/cons", OWRITE);
		dup(fd, 1);
		dup(fd, 2);
		close(fd);
		segdetach(cons);
		execl("/bin/rc", "rc", "-il", 0);
		fatal("/bin/rc", 0, 0);
	default:
		sprint(buf, "/proc/%d/notepg", childpid);
		notefd = open(buf, OWRITE);
		if(notefd < 0)
			fatal(buf, 0, 0);
		break;
	}

	/* two processes to shuttle bytes twixt children and network */
	switch(fork()){
	case -1:
		fatal("fork", 0, 0);
	case 0:
		while((n = fromchild(buf, sizeof(buf))) >= 0)
			if(write(1, buf, n) != n)
				break;
		break;
	default:
		while((n = fromnet(buf, sizeof(buf))) >= 0)
			if(write(fd, buf, n) != n)
				break;
		break;
	}

	/* kill off all server processes */
	sprint(buf, "/proc/%d/notepg", getpid());
	fd = open(buf, OWRITE);
	write(fd, "die", 3);
	exits(0);
}

void
prompt(char *p, char *b, int n)
{
	char *e;
	int i;

	print("%s: ", p);
	for(e = b+n; b < e;){
		i = fromnet(b, e-b);
		if(i <= 0)
			exits("fromnet: hungup");
		b += i;
		if(*(b-1) == '\n'){
			*(b-1) = 0;
			return;
		}
	}
}

/*
 *  challenge user
 */
int
challuser(char *user)
{
	char chall[NETCHLEN];
	char nchall[NETCHLEN+32];
	char response[NAMELEN];
	int fd;

	if(*user == 0)
		prompt("user", user, NAMELEN);
	if(nonone == 0 && strcmp(user, "none") == 0)
		return 0;
	fd = getchall(user, chall);
	if(fd < 0)
		return -1;
	sprint(nchall, "challenge: %s\r\nresponse", chall);
	prompt(nchall, response, sizeof response);
	if(challreply(fd, user, response) < 0)
		return -1;
	return 0;
}

/*
 *  Process some input from the child, add protocol if needed.  If
 *  the input buffer goes empty, return.
 */
int
fromchild(char *bp, int len)
{
	int c;
	char *start;

	for(start = bp; bp-start < len-1; ){
		c = Bgetc(&childib);
		if(c < 0){
			if(bp == start)
				return -1;
			else
				break;
		}
		if(cons->raw == 0 && c == '\n')
			*bp++ = '\r';
		*bp++ = c;
		if(Bbuffered(&childib) == 0)
			break;
	}
	return bp-start;
}

/*
 *  Read from the network up to a '\n' or some other break.
 *
 *  If in binary mode, buffer characters but don't 
 *
 *  The following characters are special:
 *	'\r\n's and '\r's get turned into '\n's.
 *	^H erases the last character buffered.
 *	^U kills the whole line buffered.
 *	^W erases the last word
 *	^D causes a 0-lenght line to be returned.
 *	Intr causes an "interrupt" note to be sent to the children.
 */
#define ECHO(c) { *ebp++ = (c); }
int
fromnet(char *bp, int len)
{
	int c;
	char echobuf[1024];
	char *ebp;
	char *start;
	static int crnl;
	static int doeof;


	/* simulate an EOF as a 0 length input */
	if(doeof){
		doeof = 0;
		return 0;
	}

	for(ebp = echobuf,start = bp; bp-start < len && ebp-echobuf < sizeof(echobuf); ){
		c = Bgetc(&netib);
		if(c < 0){
			if(bp == start)
				return -1;
			else
				break;
		}

		/* telnet protocol only */
		if(!noproto){
			/* protocol messages */
			switch(c){
			case Iac:
				crnl = 0;
				c = Bgetc(&netib);
				if(c == Iac)
					break;
				control(&netib, c);
				continue;
			}

		}

		/* \r\n or \n\r become \n  */
		if(c == '\r' || c == '\n'){
			if(crnl && crnl != c){
				crnl = 0;
				continue;
			}
			if(cons->raw == 0 && opt[Echo].local){
				ECHO('\r');
				ECHO('\n');
			}
			crnl = c;
			*bp++ = '\n';
			break;
		} else
			crnl = 0;

		/* raw processing (each character terminates */
		if(cons->raw){
			*bp++ = c;
			break;
		}

		/* in binary mode, there are no control characters */
		if(opt[Binary].local){
			if(opt[Echo].local)
				ECHO(c);
			*bp++ = c;
			continue;
		}

		/* cooked processing */
		switch(c){
		case 0x00:
			if(noproto)		/* telnet ignores nulls */
				*bp++ = c;
			continue;
		case 0x04:
			if(bp != start)
				doeof = 1;
			goto out;

		case 0x08:	/* ^H */
			if(start < bp)
				bp--;
			if(opt[Echo].local)
				ECHO(c);
			break;

		case 0x15:	/* ^U */
			bp = start;
			if(opt[Echo].local){
				ECHO('^');
				ECHO('U');
				ECHO('\r');
				ECHO('\n');
			}
			break;

		case 0x17:	/* ^W */
			if (opt[Echo].local) {
				while (--bp >= start && !alnum(*bp))
					ECHO('\b');
				while (bp >= start && alnum(*bp)) {
					ECHO('\b');
					bp--;
				}
				bp++;
			}
			break;

		case 0x7f:	/* Del */
			write(notefd, "interrupt", 9);
			break;

		default:
			if(opt[Echo].local)
				ECHO(c);
			*bp++ = c;
		}
		if(ebp != echobuf)
			write(1, echobuf, ebp-echobuf);
		ebp = echobuf;
	}
out:
	if(ebp != echobuf)
		write(1, echobuf, ebp-echobuf);
	return bp - start;
}

int
termchange(Biobuf *bp, int cmd)
{
	char buf[8];
	char *p = buf;

	if(cmd != Will)
		return 0;

	/* ask other side to send term type info */
	*p++ = Iac;
	*p++ = Sb;
	*p++ = opt[Term].code;
	*p++ = 1;
	*p++ = Iac;
	*p++ = Se;
	return iwrite(Bfildes(bp), buf, p-buf);
}

int
termsub(Biobuf *bp, uchar *sub, int n)
{
	char term[NAMELEN];

	USED(bp);
	if(n-- < 1 || sub[0] != 0)
		return 0;
	if(n >= sizeof term)
		n = sizeof term;
	strncpy(term, (char*)sub, n);
	putenv("TERM", term);
	return 0;
}

int
xlocchange(Biobuf *bp, int cmd)
{
	char buf[8];
	char *p = buf;

	if(cmd != Will)
		return 0;

	/* ask other side to send x display info */
	*p++ = Iac;
	*p++ = Sb;
	*p++ = opt[Xloc].code;
	*p++ = 1;
	*p++ = Iac;
	*p++ = Se;
	return iwrite(Bfildes(bp), buf, p-buf);
}

int
xlocsub(Biobuf *bp, uchar *sub, int n)
{
	char xloc[NAMELEN];

	USED(bp);
	if(n-- < 1 || sub[0] != 0)
		return 0;
	if(n >= sizeof xloc)
		n = sizeof xloc;
	strncpy(xloc, (char*)sub, n);
	putenv("DISPLAY", xloc);
	return 0;
}

/*
 *  create a shared segment.  Make is start 2 meg higher than the current
 *  end of process memory.
 */
void*
share(int len)
{
	ulong vastart;

	vastart = ((ulong)sbrk(0)) + 2*1024*1024;

	if(segattach(0, "shared", (void *)vastart, len) < 0)
		return 0;

	return (void*)vastart;
}

/*
 *  bind a pipe onto consctl and keep reading it to
 *  get changes to console state.
 */
int
conssim(void)
{
	int i, n;
	int fd;
	int tries;
	char buf[128];
	char *field[10];

	/* a pipe to simulate the /dev/cons */
	if(bind("#|", "/mnt/cons/cons", MREPL) < 0
	|| bind("/mnt/cons/cons/data1", "/dev/cons", MREPL) < 0)
		fatal("/dev/cons", 0, 0);

	/* a pipe to simulate consctl */
	if(bind("#|", "/mnt/cons/consctl", MBEFORE) < 0
	|| bind("/mnt/cons/consctl/data1", "/dev/consctl", MREPL) < 0)
		fatal("/dev/consctl", 0, 0);

	/* a process to read /dev/consctl and set the state in cons */
	switch(fork()){
	case -1:
		fatal("forking", 0, 0);
	case 0:
		break;
	default:
		return open("/mnt/cons/cons/data", ORDWR);
	}

	setfields(" ");
	for(tries = 0; tries < 100; tries++){
		cons->raw = 0;
		cons->hold = 0;
		fd = open("/mnt/cons/consctl/data", OREAD);
		if(fd < 0)
			continue;
		tries = 0;
		for(;;){
			n = read(fd, buf, sizeof(buf)-1);
			if(n <= 0)
				break;
			buf[n] = 0;
			n = getmfields(buf, field, 10);
			for(i = 0; i < n; i++){
				if(strcmp(field[i], "rawon") == 0)
					cons->raw = 1;
				else if(strcmp(field[i], "rawoff") == 0)
					cons->raw = 0;
				else if(strcmp(field[i], "holdon") == 0)
					cons->hold = 1;
				else if(strcmp(field[i], "holdoff") == 0)
					cons->hold = 0;
			}
		}
		close(fd);
	}
	exits(0);
	return -1;
}

int
alnum(int c)
{
	/*
	 * Hard to get absolutely right.  Use what we know about ASCII
	 * and assume anything above the Latin control characters is
	 * potentially an alphanumeric.
	 */
	if(c <= ' ')
		return 0;
	if(0x7F<=c && c<=0xA0)
		return 0;
	if(strchr("!\"#$%&'()*+,-./:;<=>?@`[\\]^{|}~", c))
		return 0;
	return 1;
}