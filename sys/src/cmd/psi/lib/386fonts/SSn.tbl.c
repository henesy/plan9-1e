int SSnfconst[]={44,37,34};
struct fonttab{
	int index, size, width, height, left;
	double fwid,basetotop;
}SSntbl[]={
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,2,1,2,0,8.333333,11.000000},	/*space*/
{1,24,8,24,4,11.100000,33.000000},	/*exclam*/
{7,75,23,25,0,23.766667,34.000000},	/*universal*/
{26,72,17,24,1,16.666667,33.000000},	/*numbersign*/
{44,50,16,25,1,18.300000,34.000000},	/*existential*/
{57,96,25,24,2,27.766667,32.000000},	/*percent*/
{81,96,25,24,1,25.933333,33.000000},	/*ampersand*/
{105,34,14,17,1,14.633333,26.000000},	/*suchthat*/
{114,62,10,31,2,11.100000,33.000000},	/*parenleft*/
{130,62,9,31,1,11.100000,33.000000},	/*parenright*/
{146,32,15,16,2,16.666667,29.000000},	/*asteriskmath*/
{154,57,18,19,0,18.300000,28.000000},	/*plus*/
{169,10,7,10,2,8.333333,14.000000},	/*comma*/
{172,9,18,3,0,18.300000,20.000000},	/*minus*/
{175,5,6,5,2,8.333333,14.000000},	/*period*/
{177,46,9,23,0,9.266667,32.000000},	/*slash*/
{189,48,16,24,1,16.666667,33.000000},	/*zero*/
{201,48,13,24,4,16.666667,33.000000},	/*one*/
{213,48,16,24,1,16.666667,33.000000},	/*two*/
{225,48,15,24,1,16.666667,33.000000},	/*three*/
{237,48,16,24,1,16.666667,33.000000},	/*four*/
{249,48,15,24,1,16.666667,33.000000},	/*five*/
{261,48,16,24,2,16.666667,33.000000},	/*six*/
{273,48,15,24,1,16.666667,33.000000},	/*seven*/
{285,48,15,24,2,16.666667,33.000000},	/*eight*/
{297,48,15,24,1,16.666667,33.000000},	/*nine*/
{309,15,7,15,3,9.266667,24.000000},	/*colon*/
{313,20,8,20,3,9.266667,24.000000},	/*semicolon*/
{318,54,17,18,1,18.300000,27.000000},	/*less*/
{332,27,18,9,0,18.300000,23.000000},	/*equal*/
{339,54,17,18,1,18.300000,27.000000},	/*greater*/
{353,48,14,24,2,14.800000,33.000000},	/*question*/
{365,51,18,17,0,18.300000,26.000000},	/*congruent*/
{378,72,23,24,0,24.066667,33.000000},	/*Alpha*/
{396,72,20,24,1,22.233333,33.000000},	/*Beta*/
{414,96,26,24,-1,24.066667,33.000000},	/*Chi*/
{438,72,21,24,0,20.400000,33.000000},	/*Delta*/
{456,72,21,24,1,20.366667,33.000000},	/*Epsilon*/
{474,96,25,24,1,25.433333,33.000000},	/*Phi*/
{498,72,21,24,1,20.100000,33.000000},	/*Gamma*/
{516,96,25,24,1,24.066667,33.000000},	/*Eta*/
{540,48,11,24,1,11.100000,33.000000},	/*Iota*/
{552,75,20,25,0,21.033333,34.000000},	/*theta1*/
{571,72,24,24,1,24.066667,33.000000},	/*Kappa*/
{589,72,23,24,0,22.866667,33.000000},	/*Lambda*/
{607,96,30,24,1,29.633333,33.000000},	/*Mu*/
{631,72,24,24,1,24.066667,33.000000},	/*Nu*/
{649,72,24,24,1,24.066667,33.000000},	/*Omicron*/
{667,96,25,24,1,25.600000,33.000000},	/*Pi*/
{691,72,24,24,1,24.700000,33.000000},	/*Theta*/
{709,72,19,24,1,18.533333,33.000000},	/*Rho*/
{727,72,20,24,0,19.733333,33.000000},	/*Sigma*/
{745,72,21,24,1,20.366667,33.000000},	/*Tau*/
{763,72,23,24,0,23.000000,33.000000},	/*Upsilon*/
{781,50,15,25,1,14.633333,27.000000},	/*sigma1*/
{794,96,25,24,1,25.600000,33.000000},	/*Omega*/
{818,72,20,24,1,21.500000,33.000000},	/*Xi*/
{836,96,26,24,0,26.500000,33.000000},	/*Psi*/
{860,72,22,24,1,20.366667,33.000000},	/*Zeta*/
{878,58,11,29,3,11.100000,33.000000},	/*bracketleft*/
{893,54,24,18,5,28.766667,27.000000},	/*therefore*/
{907,58,9,29,1,11.100000,33.000000},	/*bracketright*/
{922,72,22,24,0,21.933333,33.000000},	/*perpendicular*/
{940,9,17,3,0,16.666667,3.000000},	/*underscore*/
{943,10,37,2,16,16.666667,41.000000},	/*radicalex*/
{946,54,21,18,1,21.033333,27.000000},	/*alpha*/
{960,99,18,33,1,18.300000,35.000000},	/*beta*/
{985,78,17,26,0,18.300000,27.000000},	/*chi*/
{1005,52,16,26,1,16.466667,35.000000},	/*delta*/
{1018,36,15,18,1,14.633333,27.000000},	/*epsilon*/
{1027,64,16,32,1,17.366667,33.000000},	/*phi*/
{1043,52,16,26,0,13.700000,27.000000},	/*gamma*/
{1056,75,18,25,0,20.100000,27.000000},	/*eta*/
{1075,36,10,18,0,10.966667,27.000000},	/*iota*/
{1084,78,19,26,1,20.100000,27.000000},	/*phi1*/
{1104,54,19,18,1,18.300000,27.000000},	/*kappa*/
{1118,78,18,26,0,18.300000,35.000000},	/*lambda*/
{1138,75,19,25,1,19.200000,27.000000},	/*mu*/
{1157,36,16,18,0,17.366667,27.000000},	/*nu*/
{1166,54,17,18,1,18.300000,27.000000},	/*omicron*/
{1180,51,18,17,0,18.300000,26.000000},	/*pi*/
{1193,75,17,25,1,17.366667,34.000000},	/*theta*/
{1212,50,16,25,2,18.300000,27.000000},	/*rho*/
{1225,54,20,18,1,20.100000,27.000000},	/*sigma*/
{1239,36,14,18,0,14.633333,27.000000},	/*tau*/
{1248,54,18,18,0,19.200000,27.000000},	/*upsilon*/
{1262,63,22,21,0,23.766667,30.000000},	/*omega1*/
{1278,54,23,18,2,22.866667,27.000000},	/*omega*/
{1292,68,16,34,0,16.433333,36.000000},	/*xi*/
{1309,78,24,26,0,22.866667,27.000000},	/*psi*/
{1329,68,16,34,2,16.466667,36.000000},	/*zeta*/
{1346,60,13,30,2,16.000000,33.000000},	/*braceleft*/
{1361,30,5,30,2,6.666667,33.000000},	/*bar*/
{1369,60,14,30,3,16.000000,33.000000},	/*braceright*/
{1384,15,18,5,0,18.300000,21.000000},	/*similar*/
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{0,0,0,0,0,0.,0.},
{1388,72,21,24,0,20.666667,33.000000},	/*Upsilon1*/
{1406,11,8,11,1,8.233333,35.000000},	/*minute*/
{1409,66,18,22,1,18.300000,31.000000},	/*lessequal*/
{1426,72,24,24,-6,5.566667,33.000000},	/*fraction*/
{1444,30,23,10,0,23.766667,23.000000},	/*infinity*/
{1452,60,16,30,0,16.666667,33.000000},	/*florin*/
{1467,57,22,19,2,25.100000,28.000000},	/*club*/
{1482,60,20,20,5,25.100000,28.000000},	/*diamond*/
{1497,57,21,19,4,25.100000,28.000000},	/*heart*/
{1512,63,21,21,4,25.100000,29.000000},	/*spade*/
{1528,85,34,17,1,34.733333,26.000000},	/*arrowboth*/
{1550,68,32,17,1,32.900000,26.000000},	/*arrowleft*/
{1567,96,19,32,1,20.100000,41.000000},	/*arrowup*/
{1591,68,32,17,1,32.900000,26.000000},	/*arrowright*/
{1608,96,19,32,1,20.100000,41.000000},	/*arrowdown*/
{1632,24,12,12,1,13.333333,33.000000},	/*degree*/
{1638,69,18,23,0,18.300000,32.000000},	/*plusminus*/
{1656,22,14,11,1,13.700000,35.000000},	/*second*/
{1662,66,18,22,1,18.300000,31.000000},	/*greaterequal*/
{1679,54,18,18,1,18.300000,27.000000},	/*multiply*/
{1693,30,21,10,0,23.766667,23.000000},	/*proportional*/
{1701,52,16,26,1,16.466667,35.000000},	/*partialdiff*/
{1714,26,14,13,1,15.333333,26.000000},	/*bullet*/
{1721,45,18,15,0,18.300000,26.000000},	/*divide*/
{1733,57,18,19,0,18.300000,28.000000},	/*notequal*/
{1748,39,18,13,0,18.300000,25.000000},	/*equivalence*/
{1758,30,18,10,0,18.300000,23.000000},	/*approxequal*/
{1766,20,30,5,4,33.333333,14.000000},	/*ellipsis*/
{1771,78,11,39,9,20.100000,44.000000},	/*arrowvertex*/
{1791,15,39,3,-2,33.333333,19.000000},	/*arrowhorizex*/
{1795,66,20,22,0,21.933333,31.000000},	/*carriagereturn*/
{1812,69,22,23,5,27.433333,32.000000},	/*aleph*/
{1830,84,20,28,1,22.866667,35.000000},	/*Ifraktur*/
{1851,104,26,26,1,26.500000,35.000000},	/*Rfraktur*/
{1877,108,29,27,4,32.900000,29.000000},	/*weierstrass*/
{1904,96,25,24,1,25.600000,33.000000},	/*circlemultiply*/
{1928,96,25,24,1,25.600000,33.000000},	/*circleplus*/
{1952,100,26,25,1,27.433333,34.000000},	/*emptyset*/
{1977,72,25,18,1,25.600000,27.000000},	/*intersection*/
{1995,72,25,18,1,25.600000,27.000000},	/*union*/
{2013,51,22,17,0,23.766667,26.000000},	/*propersuperset*/
{2026,63,22,21,0,23.766667,26.000000},	/*reflexsuperset*/
{2042,60,23,20,1,23.766667,27.000000},	/*notsubset*/
{2057,51,23,17,1,23.766667,26.000000},	/*propersubset*/
{2070,63,23,21,1,23.766667,26.000000},	/*reflexsubset*/
{2086,51,17,17,2,23.766667,26.000000},	/*element*/
{2099,63,17,21,2,23.766667,28.000000},	/*notelement*/
{2115,96,25,24,1,25.600000,33.000000},	/*angle*/
{2139,75,23,25,1,23.766667,34.000000},	/*gradient*/
{2158,96,25,24,1,26.333333,33.000000},	/*registerserif*/
{2182,96,25,24,1,26.333333,33.000000},	/*copyrightserif*/
{2206,56,29,14,1,29.666667,33.000000},	/*trademarkserif*/
{2220,116,27,29,1,27.433333,35.000000},	/*product*/
{2249,99,18,33,0,18.300000,41.000000},	/*radical*/
{2274,5,6,5,2,8.333333,21.000000},	/*dotmath*/
{2276,33,23,11,0,23.766667,20.000000},	/*logicalnot*/
{2285,45,20,15,1,20.100000,24.000000},	/*logicaland*/
{2297,51,20,17,1,20.100000,26.000000},	/*logicalor*/
{2310,90,35,18,1,34.733333,27.000000},	/*arrowdblboth*/
{2333,72,32,18,1,32.900000,27.000000},	/*arrowdblleft*/
{2351,93,19,31,2,20.100000,40.000000},	/*arrowdblup*/
{2375,72,32,18,1,32.900000,27.000000},	/*arrowdblright*/
{2393,93,19,31,2,20.100000,40.000000},	/*arrowdbldown*/
{2417,52,16,26,1,16.466667,35.000000},	/*lozenge*/
{2430,60,10,30,1,10.966667,34.000000},	/*angleleft*/
{2445,96,25,24,1,26.333333,33.000000},	/*registersans*/
{2469,96,25,24,1,26.333333,33.000000},	/*copyrightsans*/
{2493,56,25,14,0,26.200000,33.000000},	/*trademarksans*/
{2507,90,23,30,0,23.766667,35.000000},	/*summation*/
{2530,84,15,41,1,12.800000,41.000000},	/*parenlefttp*/
{2551,35,3,35,1,12.800000,41.000000},	/*parenleftex*/
{2560,84,15,41,1,12.800000,41.000000},	/*parenleftbt*/
{2581,70,12,35,0,12.800000,41.000000},	/*bracketlefttp*/
{2599,35,2,35,0,12.800000,41.000000},	/*bracketleftex*/
{2608,70,12,35,0,12.800000,41.000000},	/*bracketleftbt*/
{2626,72,15,36,7,16.466667,42.000000},	/*bracelefttp*/
{2644,72,9,36,1,16.466667,42.000000},	/*braceleftmid*/
{2662,72,15,36,7,16.466667,42.000000},	/*braceleftbt*/
{2680,68,9,34,7,16.466667,41.000000},	/*braceex*/
{0,0,0,0,0,0.,0.},
{2697,60,10,30,1,10.966667,34.000000},	/*angleright*/
{2712,72,10,36,0,9.133333,41.000000},	/*integral*/
{2730,105,24,35,11,22.866667,41.000000},	/*integraltp*/
{2757,74,14,37,11,22.866667,43.000000},	/*integralex*/
{2776,70,14,35,1,22.866667,41.000000},	/*integralbt*/
{2794,84,15,41,2,12.800000,41.000000},	/*parenrighttp*/
{2815,70,15,35,13,12.800000,41.000000},	/*parenrightex*/
{2833,84,15,41,2,12.800000,41.000000},	/*parenrightbt*/
{2854,70,12,35,0,12.800000,41.000000},	/*bracketrighttp*/
{2872,70,12,35,10,12.800000,41.000000},	/*bracketrightex*/
{2890,70,12,35,0,12.800000,41.000000},	/*bracketrightbt*/
{2908,68,9,34,1,16.466667,41.000000},	/*bracerighttp*/
{2925,68,15,34,7,16.466667,41.000000},	/*bracerightmid*/
{2942,68,9,34,1,16.466667,41.000000},	/*bracerightbt*/
{0,0,0,0,0,0.,0.},
};