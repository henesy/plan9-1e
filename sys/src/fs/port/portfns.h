void	accessdir(Iobuf*, Dentry*, int);
void	addfree(Device, long, Superb*);
Alarm*	alarm(int, void(*)(Alarm*, void*), void*);
void	alarminit(void);
void	arpstart(void);
int	authsrv(Chan*, char*, int);
void	authserver(Chan*);
void	arginit(void);
void	cdiag(char*, int);
int	cnumb(void);
Device	config(void);
int	rawchar(int);
long	bufalloc(Device, int, long);
void	buffree(Device, long, int);
int	byname(void*, void*);
int	byuid(void*, void*);
void	cancel(Alarm*);
int	canlock(Lock*);
int	canqlock(QLock*);
int	Cconv(Op*);
void	cfsdump(Filsys*);
Chan*	chaninit(int, int);
void	cmd_auth(int, char*[]);
void	cmd_check(int, char*[]);
void	cmd_users(int, char*[]);
void	cmd_newuser(int, char*[]);
void	cmd_netdb(int, char*[]);
void	cmd_passwd(int, char*[]);
int	chartoip(uchar *, char *);
int	checkname(char*);
int	checktag(Iobuf*, int, long);
int	cksum(void*, int, int);
int	cksum0(int, int);
void	clock(ulong, ulong);
void	clockinit(void);
void	clockreload(ulong);
void	cyclstart(void);
void	dotrace(int);
int	conschar(void);
void	consserve(void);
int	convD2M(Dentry*, char*);
int	convM2D(char*, Dentry*);
int	convM2S(char*, Fcall*, int);
int	convS2M(Fcall*, char*);
int	conslock(void);
int	con_attach(int, char*, char*);
int	con_clone(int, int);
int	con_create(int, char*, int, int, long, int);
int	con_clri(int);
int	con_open(int, int);
int	con_read(int, char*, long, int);
int	con_remove(int);
void	con_rintr(int);
int	con_session(void);
int	con_walk(int, char*);
int	con_write(int, char*, long, int);
int	cwgrow(Device, Superb*);
int	cwfree(Device, long);
void	cwinit(Device);
long	cwraddr(Device, int);
int	cwread(Device, long, void*);
void	cwream(Device);
void	cwrecover(Device);
long	cwsaddr(Device);
long	cwsize(Device);
void	dbufread(Iobuf*, Dentry*, long);
int	cwwrite(Device, long, void*);
void	datestr(char*, long);
int	Dconv(Op*);
void	delay(int);
int	devcmp(Device, Device);
void	devream(Device);
void	devrecover(Device);
void	devinit(Device);
int	devread(Device, long, void*);
long	devsize(Device);
int	devwrite(Device, long, void*);
void	dkstart(void);
Iobuf*	dnodebuf(Iobuf*, Dentry*, long, int);
void	dofilter(Filter*);
int	doremove(File*, int);
void	dtrunc(Iobuf*, Dentry*);
void	duartinit(void);
void	duartintr(void);
int	duartputc(int);
void	duartreset(void);
void	duartstart(int);
int	duartrecv(void);
void	duartxmit(int);
int	dumpblock(Device);
void	dumpregs(Ureg*);
void	dumpstack(User*);
void	exit(void);
ulong	fakeqid(Dentry*);
Float	famd(Float, int, int, int);
int	Fconv(Op*);
ulong	fdf(Float, int);
void	fileinit(Chan*);
File*	filep(Chan*, int, int);
void	firmware(void);
int	fname(char*);
int	fpair(char*, char*);
void	formatinit(void);
int	fread(void*, int);
void	freealarm(Alarm*);
void	freefp(File*);
void	freewp(Wpath*);
Filsys*	fsstr(char*);
long	fwormsize(Device);
void	fwormream(Device);
void	fworminit(Device);
int	fwormread(Device, long, void*);
int	fwormwrite(Device, long, void*);
void	f_attach(Chan*, Fcall*, Fcall*);
void	f_auth(Chan*, Fcall*, Fcall*);
void	f_clone(Chan*, Fcall*, Fcall*);
void	f_clunk(Chan*, Fcall*, Fcall*);
void	f_create(Chan*, Fcall*, Fcall*);
void	f_nop(Chan*, Fcall*, Fcall*);
void	f_flush(Chan*, Fcall*, Fcall*);
void	f_open(Chan*, Fcall*, Fcall*);
void	f_read(Chan*, Fcall*, Fcall*);
void	f_remove(Chan*, Fcall*, Fcall*);
void	f_session(Chan*, Fcall*, Fcall*);
void	f_stat(Chan*, Fcall*, Fcall*);
void	f_walk(Chan*, Fcall*, Fcall*);
void	f_clwalk(Chan*, Fcall*, Fcall*);
void	f_write(Chan*, Fcall*, Fcall*);
void	f_wstat(Chan*, Fcall*, Fcall*);
Iobuf*	getbuf(Device, long, int);
void*	getarg(void);
char*	getwd(char*, char*);
int	getc(void);
ulong	getcallerpc(void);
Dentry*	getdir(Iobuf*, int);
Chan*	getlcp(uchar*, long);
void	getpasswd(char*, int);
long	getraddr(Device);
void	gotolabel(Label*);
void	hexdump(void*, int);
int	iaccess(File*, Dentry*, int);
void*	ialloc(ulong, int);
void	ilauth(void);
long	indfetch(Iobuf*, Dentry*, long, long , int, int);
int	ingroup(int, int);
int	inh(int, uchar*);
void	init0(void);
void	iobufinit(void);
void*	iobufmap(Iobuf*);
void	iobufunmap(Iobuf*);
int	iobufql(QLock*);
void	kbdchar(int);
void	lights(int, int);
void	launchinit(void);
int	leadgroup(int, int);
void	lock(Lock*);
void	lockinit(void);
void	machinit(void);
Msgbuf*	mballoc(int, Chan*, int);
void	mbinit(void);
void	mbfree(Msgbuf*);
ulong	meminit(void);
Iobuf*	movebuf(Iobuf*);
void	mcatinit(Device);
int	mcatread(Device, long, void*);
long	mcatsize(Device);
int	mcatwrite(Device, long, void*);
void	partinit(Device);
int	partread(Device, long, void*);
long	partsize(Device);
int	partwrite(Device, long, void*);
void	mlevinit(Device);
int	mlevread(Device, long, void*);
long	mlevsize(Device);
int	mlevwrite(Device, long, void*);
int	nametokey(char*, char*);
Alarm*	newalarm(void);
File*	newfp(void);
User*	newproc(void);
Qid	newqid(Device);
Queue*	newqueue(int);
void	newstart(void);
Wpath*	newwp(void);
int	nvread(int, void*, int);
int	nvwrite(int, void*, int);
int	nzip(uchar ip[Pasize]);
int	walkto(char*);
int	no(void*);
long	number(char*, int, int);
void	online(void);
void	otherinit(void);
void	p9fcall(Chan*, Fcall*, Fcall*);
void	p9mcall(Chan*, char*, char*);
void	panic(char*, ...);
void	prdate(void);
void	preread(Device, long);
void	prflush(void);
int	prime(long);
void	printinit(void);
void	procinit(void);
void	putbuf(Iobuf*);
void	qlock(QLock*);
void	qunlock(QLock*);
void	rahead(void);
void	ready(User*);
void	ream(Filsys*);
void*	recv(Queue*, int);
void	restartprint(Alarm*);
void	rlock(RWlock*);
void	rootream(Device, long);
int	roread(Device, long, void*);
void	rstate(Chan*, int);
long	rtc2sec(Rtc *);
void	runlock(RWlock*);
User*	runproc(void);
void	sched(void);
void	schedinit(void);
int	scsiio(Device, int, uchar*, int, void*, int);
Drive*	scsidrive(Device);
void	sec2rtc(ulong, Rtc *);
void	send(Queue*, void*);
void	serve(void);
int	setlabel(Label*);
void	settag(Iobuf*, int, long);
void	settime(long);
void	sleep(Rendez*, int(*)(void*), void*);
int	splhi(void);
int	spllo(void);
void	splx(int);
void	startprint(void);
int	strtouid(char*, int);
long	superaddr(Device);
void	superream(Device, long);
void	sync(char*);
int	syncblock(void);
long	syscall(Ureg*);
void	sysinit(void);
int	Tconv(Op*);
long	time(void);
long	nextime(long, int, int);
Tlock*	tlocked(Iobuf*, Dentry*);
void	touser(void);
long	toytime(void);
long	rtctime(void);
void	setrtc(long);
void	uidtostr(char*, int, int);
Uid*	uidpstr(char*);
void	unlock(Lock*);
void	userinit(void(*)(void), void*, char*);
void	vecinit(void);
void	wakeup(Rendez*);
void	wbflush(void);
void	wlock(RWlock*);
void	wormcopy(void);
void	wormprobe(void);
int	dowcp(void);
int	dowcmp(void);
void	synccopy(void);
long	wormsearch(Device, int, long, long);
int	wormread(Device, long, void*);
long	wormsize(Device);
int	wormwrite(Device, long, void*);
void	wreninit(Device);
int	wrenread(Device, long, void*);
long	wrensize(Device);
int	wrenwrite(Device, long, void*);
void	wunlock(RWlock*);
void 	cmd_exec(char*);
void	cmd_install(char*, char*, void (*)(int, char*[]));
ulong	flag_install(char*, char*);

int	nhgets(uchar*);
long	nhgetl(uchar*);
void	hnputs(uchar*, int);
void	hnputl(uchar*, long);

int	hsvmeinit(Vmedevice*);
void	hsvmeintr(Vmedevice*);

int	cyclinit(Vmedevice*);
void	cyclintr(Vmedevice*);

int	bitinit(Vmedevice*);
void	bitintr(Vmedevice*);
void	bitstart(void);

int	eagleinit(Vmedevice*);
void	eagleintr(Vmedevice*);
void	eaglestart(void);

void	lanceintr(uchar);
void	lanceparity(void);
int	lanceinit(uchar);
void	lancestart(void);

void	arpreceive(Enpkt*, int, Ifc*);
void	ipreceive(Enpkt*, int, Ifc*);
void	ilrecv(Msgbuf*, Ifc*);

void	getipa(Ifc*);
int	ipforme(uchar*, Ifc*);
int	ipcsum(uchar*);

int	ptclcsum(uchar*, int);
void	ipsend(Msgbuf*);

int	authorise(File *f, Fcall *in);
void	pokewcp(void);