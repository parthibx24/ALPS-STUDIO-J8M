#ifndef _CUST_BATTERY_METER_TABLE_H
#define _CUST_BATTERY_METER_TABLE_H

#include <mt-plat/battery_meter.h>
#define BAT_NTC_10 1
#define BAT_NTC_47 0

#if (BAT_NTC_10 == 1)
#define RBAT_PULL_UP_R             16900
#endif

#if (BAT_NTC_47 == 1)
#define RBAT_PULL_UP_R             61900
#endif

#define RBAT_PULL_UP_VOLT          1800

typedef struct _BATTERY_PROFILE_STRUCT {
	signed int percentage;
	signed int voltage;
} BATTERY_PROFILE_STRUCT, *BATTERY_PROFILE_STRUCT_P;

typedef struct _R_PROFILE_STRUCT {
	signed int resistance;
	signed int voltage;
} R_PROFILE_STRUCT, *R_PROFILE_STRUCT_P;

typedef enum {
	T1_0C,
	T2_25C,
	T3_50C
} PROFILE_TEMPERATURE;

#if (BAT_NTC_10 == 1)
BATT_TEMPERATURE Batt_Temperature_Table[] = {
	{-20, 68237},
	{-15, 53650},
	{-10, 42506},
	{ -5, 33892},
	{  0, 27219},
	{  5, 22021},
	{ 10, 17926},
	{ 15, 14674},
	{ 20, 12081},
	{ 25, 10000},
	{ 30, 8315},
	{ 35, 6948},
	{ 40, 5834},
	{ 45, 4917},
	{ 50, 4161},
	{ 55, 3535},
	{ 60, 3014}
};
#endif

#if (BAT_NTC_47 == 1)
	BATT_TEMPERATURE Batt_Temperature_Table[] = {
	{-20, 483954},
	{-15, 360850},
	{-10, 271697},
	{ -5, 206463},
	{  0, 158214},
	{  5, 122259},
	{ 10, 95227},
	{ 15, 74730},
	{ 20, 59065},
	{ 25, 47000},
	{ 30, 37643},
	{ 35, 30334},
	{ 40, 24591},
	{ 45, 20048},
	{ 50, 16433},
	{ 55, 13539},
	{ 60, 11210}
	};
#endif

// T0 -10C
BATTERY_PROFILE_STRUCT battery_profile_t0[] =
{
{0,4331},
{1,4292},
{3,4261},
{5,4234},
{7,4209},
{9,4186},
{11,4163},
{13,4140},
{15,4120},
{17,4103},
{19,4083},
{21,4059},
{23,4026},
{25,3996},
{27,3972},
{29,3953},
{31,3937},
{33,3924},
{35,3911},
{37,3898},
{39,3885},
{41,3874},
{43,3862},
{45,3851},
{47,3841},
{49,3832},
{51,3823},
{53,3816},
{55,3809},
{57,3803},
{59,3799},
{61,3794},
{63,3790},
{65,3786},
{67,3781},
{69,3777},
{71,3772},
{73,3767},
{75,3763},
{77,3756},
{79,3748},
{81,3740},
{83,3732},
{85,3722},
{87,3712},
{89,3701},
{91,3688},
{93,3673},
{95,3647},
{97,3586},
{99,3454},
{100,3400},
{100,3400},
{100,3400}
};      
        
// T1 0C 
BATTERY_PROFILE_STRUCT battery_profile_t1[] =
{
{0,4329},
{1,4295},
{3,4268},
{5,4244},
{7,4221},
{9,4200},
{11,4179},
{13,4158},
{15,4138},
{17,4117},
{19,4100},
{21,4085},
{23,4067},
{25,4040},
{27,4007},
{29,3980},
{31,3959},
{33,3942},
{35,3927},
{37,3913},
{39,3899},
{41,3885},
{43,3871},
{45,3860},
{47,3848},
{49,3838},
{51,3829},
{53,3820},
{55,3812},
{57,3805},
{59,3798},
{60,3793},
{62,3789},
{64,3786},
{66,3782},
{68,3779},
{70,3775},
{72,3771},
{74,3766},
{76,3760},
{78,3753},
{80,3745},
{82,3736},
{84,3725},
{86,3715},
{88,3704},
{90,3694},
{92,3687},
{94,3676},
{96,3646},
{98,3553},
{100,3400},
{100,3400},
{100,3400}
};           

// T2 25C
BATTERY_PROFILE_STRUCT battery_profile_t2[] =
{
{0,4328},
{1,4303},
{3,4281},
{5,4259},
{7,4238},
{9,4216},
{11,4195},
{13,4175},
{15,4154},
{17,4133},
{19,4113},
{21,4093},
{23,4077},
{25,4067},
{27,4042},
{29,4008},
{31,3986},
{33,3972},
{35,3965},
{37,3951},
{39,3934},
{41,3913},
{43,3893},
{45,3878},
{47,3865},
{49,3854},
{51,3843},
{53,3835},
{55,3826},
{57,3818},
{59,3811},
{61,3804},
{63,3798},
{65,3792},
{67,3787},
{69,3781},
{71,3775},
{73,3767},
{75,3760},
{77,3752},
{79,3745},
{81,3739},
{83,3730},
{85,3719},
{87,3708},
{89,3694},
{91,3691},
{93,3688},
{94,3682},
{96,3633},
{98,3522},
{100,3400},
{100,3400},
{100,3400}
};     

// T3 50C
BATTERY_PROFILE_STRUCT battery_profile_t3[] =
{
{0,4317},
{1,4293},
{3,4270},
{5,4248},
{7,4226},
{9,4205},
{11,4184},
{13,4163},
{15,4142},
{17,4122},
{19,4102},
{21,4082},
{23,4064},
{25,4046},
{27,4029},
{29,4005},
{31,3993},
{33,3977},
{35,3962},
{37,3947},
{39,3932},
{41,3914},
{43,3891},
{45,3873},
{47,3860},
{48,3848},
{50,3838},
{52,3829},
{54,3820},
{56,3812},
{58,3805},
{60,3798},
{62,3792},
{64,3786},
{66,3781},
{68,3776},
{70,3767},
{72,3754},
{74,3745},
{76,3736},
{78,3729},
{80,3722},
{82,3715},
{84,3705},
{86,3694},
{88,3681},
{90,3674},
{92,3672},
{94,3669},
{95,3644},
{97,3561},
{99,3415},
{100,3400},
{100,3400}
};           

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUCT battery_profile_temperature[] =
{
  {0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 }, 
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 }
};    

// ============================================================
// <Rbat, Battery_Voltage> Table
// ============================================================
// T0 -10C
R_PROFILE_STRUCT r_profile_t0[] =
{
{1461,4331},
{1461,4292},
{1408,4261},
{1385,4234},
{1328,4209},
{1315,4186},
{1272,4163},
{1241,4140},
{1222,4120},
{1210,4103},
{1188,4083},
{1157,4059},
{1109,4026},
{1069,3996},
{1044,3972},
{1036,3953},
{1037,3937},
{1038,3924},
{1044,3911},
{1043,3898},
{1041,3885},
{1048,3874},
{1038,3862},
{1036,3851},
{1038,3841},
{1040,3832},
{1042,3823},
{1048,3816},
{1054,3809},
{1061,3803},
{1075,3799},
{1078,3794},
{1089,3790},
{1133,3786},
{1148,3781},
{1137,3777},
{1148,3772},
{1173,3767},
{1232,3763},
{1253,3756},
{1257,3748},
{1237,3740},
{1275,3732},
{1306,3722},
{1341,3712},
{1372,3701},
{1403,3688},
{1434,3673},
{1454,3647},
{1496,3586},
{1309,3454},
{876,3400},
{1359,3400},
{1359,3400}
};      

// T1 0C
R_PROFILE_STRUCT r_profile_t1[] =
{
{884,4329},
{884,4295},
{888,4268},
{883,4244},
{879,4221},
{844,4200},
{818,4179},
{812,4158},
{804,4138},
{796,4117},
{795,4100},
{774,4085},
{754,4067},
{727,4040},
{696,4007},
{674,3980},
{671,3959},
{650,3942},
{639,3927},
{644,3913},
{645,3899},
{641,3885},
{635,3871},
{633,3860},
{630,3848},
{634,3838},
{637,3829},
{642,3820},
{648,3812},
{655,3805},
{663,3798},
{673,3793},
{685,3789},
{697,3786},
{709,3782},
{721,3779},
{732,3775},
{746,3771},
{760,3766},
{775,3760},
{788,3753},
{803,3745},
{793,3736},
{807,3725},
{832,3715},
{863,3704},
{959,3694},
{1112,3687},
{1293,3676},
{1564,3646},
{1921,3553},
{2267,3400},
{2733,3400},
{2733,3400}
};     

// T2 25C
R_PROFILE_STRUCT r_profile_t2[] =
{
{160,4328},
{160,4303},
{163,4281},
{162,4259},
{163,4238},
{165,4216},
{165,4195},
{169,4175},
{169,4154},
{173,4133},
{173,4113},
{176,4093},
{182,4077},
{195,4067},
{189,4042},
{182,4008},
{189,3986},
{191,3972},
{202,3965},
{197,3951},
{190,3934},
{175,3913},
{162,3893},
{155,3878},
{154,3865},
{153,3854},
{154,3843},
{156,3835},
{156,3826},
{159,3818},
{160,3811},
{163,3804},
{166,3798},
{167,3792},
{168,3787},
{170,3781},
{169,3775},
{162,3767},
{160,3760},
{157,3752},
{157,3745},
{162,3739},
{161,3730},
{162,3719},
{165,3708},
{160,3694},
{165,3691},
{176,3688},
{194,3682},
{194,3633},
{209,3522},
{302,3400},
{1547,3400},
{1547,3400}  
}; 

// T3 50C
R_PROFILE_STRUCT r_profile_t3[] =
{
{123,4317},
{123,4293},
{126,4270},
{127,4248},
{128,4226},
{130,4205},
{130,4184},
{132,4163},
{133,4142},
{135,4122},
{135,4102},
{137,4082},
{139,4064},
{142,4046},
{146,4029},
{145,4005},
{151,3993},
{151,3977},
{155,3962},
{159,3947},
{162,3932},
{160,3914},
{145,3891},
{137,3873},
{136,3860},
{134,3848},
{136,3838},
{136,3829},
{136,3820},
{139,3812},
{141,3805},
{143,3798},
{146,3792},
{148,3786},
{152,3781},
{155,3776},
{151,3767},
{140,3754},
{141,3745},
{141,3736},
{141,3729},
{143,3722},
{146,3715},
{145,3705},
{145,3694},
{144,3681},
{141,3674},
{150,3672},
{161,3669},
{161,3644},
{165,3561},
{195,3415},
{1534,3400},
{1395,3400}
}; 

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUCT r_profile_temperature[] =
{
  {0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 }, 
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 }
};    

/* ============================================================
// function prototype
// ============================================================*/
int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUCT_P fgauge_get_profile(unsigned int temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUCT_P fgauge_get_profile_r_table(unsigned int temperature);

#endif	/*#ifndef _CUST_BATTERY_METER_TABLE_H*/
