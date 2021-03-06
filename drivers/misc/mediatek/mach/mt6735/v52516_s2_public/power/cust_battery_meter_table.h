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
 {0,4330},
{1,4277},
{2,4248},
{3,4223},
{4,4202},
{5,4182},
{6,4164},
{7,4147},
{8,4132},
{9,4118},
{10,4105},
{11,4092},
{12,4079},
{13,4064},
{14,4050},
{15,4034},
{16,4019},
{17,4005},
{18,3992},
{19,3979},
{20,3969},
{21,3959},
{22,3949},
{23,3941},
{24,3933},
{25,3925},
{26,3917},
{27,3909},
{28,3902},
{29,3894},
{30,3887},
{31,3880},
{32,3873},
{33,3866},
{34,3860},
{35,3854},
{36,3847},
{37,3841},
{38,3836},
{39,3830},
{40,3825},
{41,3820},
{42,3815},
{42,3811},
{43,3807},
{44,3803},
{45,3799},
{46,3795},
{47,3792},
{48,3789},
{49,3786},
{50,3783},
{51,3780},
{52,3778},
{53,3775},
{54,3772},
{55,3770},
{56,3767},
{57,3765},
{58,3762},
{59,3760},
{60,3757},
{61,3755},
{62,3752},
{63,3750},
{64,3748},
{65,3745},
{66,3743},
{67,3740},
{68,3738},
{69,3735},
{70,3732},
{71,3730},
{72,3727},
{73,3723},
{74,3721},
{75,3717},
{76,3714},
{77,3711},
{78,3708},
{79,3704},
{80,3700},
{81,3696},
{82,3692},
{83,3688},
{84,3683},
{85,3678},
{86,3673},
{87,3667},
{88,3661},
{89,3655},
{90,3646},
{91,3638},
{92,3628},
{93,3617},
{94,3603},
{95,3588},
{96,3568},
{97,3544},
{98,3513},
{99,3473},
{100,3400},
{100,3400}

};      
        
// T1 0C 
BATTERY_PROFILE_STRUCT battery_profile_t1[] =
{
 {0,4312},
{1,4277},
{2,4254},
{3,4235},
{4,4218},
{5,4203},
{6,4189},
{7,4174},
{8,4161},
{9,4148},
{10,4136},
{11,4123},
{12,4111},
{13,4100},
{14,4089},
{15,4079},
{16,4069},
{17,4058},
{18,4047},
{19,4034},
{20,4020},
{21,4006},
{22,3992},
{23,3979},
{24,3968},
{25,3957},
{26,3948},
{27,3940},
{28,3932},
{29,3925},
{30,3918},
{31,3910},
{32,3904},
{33,3896},
{34,3890},
{35,3883},
{36,3876},
{37,3870},
{38,3863},
{39,3857},
{40,3851},
{41,3845},
{42,3840},
{43,3834},
{44,3829},
{45,3823},
{46,3819},
{47,3814},
{48,3809},
{49,3804},
{50,3800},
{51,3796},
{52,3792},
{53,3789},
{54,3786},
{55,3783},
{56,3780},
{57,3777},
{58,3774},
{59,3772},
{60,3770},
{61,3767},
{62,3765},
{63,3762},
{64,3761},
{65,3758},
{66,3756},
{67,3753},
{68,3751},
{69,3749},
{70,3746},
{71,3744},
{72,3741},
{73,3738},
{74,3736},
{75,3732},
{76,3729},
{77,3726},
{78,3722},
{79,3719},
{80,3715},
{81,3711},
{82,3707},
{83,3703},
{84,3699},
{85,3694},
{86,3689},
{87,3683},
{88,3677},
{90,3668},
{91,3660},
{92,3649},
{93,3635},
{94,3619},
{95,3599},
{96,3575},
{97,3546},
{98,3512},
{99,3472},
{100,3400},
{100,3400},
{100,3400},
{100,3400}

};           

// T2 25C
BATTERY_PROFILE_STRUCT battery_profile_t2[] =
{
	{0,4315},
{1,4294},
{2,4280},
{3,4266},
{4,4254},
{5,4243},
{6,4231},
{7,4220},
{8,4209},
{9,4198},
{10,4187},
{11,4176},
{12,4166},
{13,4156},
{14,4145},
{15,4135},
{16,4124},
{17,4114},
{18,4104},
{19,4094},
{20,4083},
{21,4073},
{22,4063},
{23,4056},
{24,4049},
{25,4043},
{26,4031},
{27,4015},
{28,3998},
{28,3984},
{29,3973},
{30,3964},
{31,3957},
{32,3951},
{33,3946},
{34,3940},
{35,3933},
{36,3925},
{37,3916},
{38,3907},
{39,3899},
{40,3891},
{41,3883},
{42,3876},
{43,3868},
{44,3861},
{45,3854},
{46,3848},
{47,3842},
{48,3837},
{49,3831},
{50,3827},
{51,3822},
{52,3817},
{53,3813},
{54,3808},
{55,3804},
{56,3801},
{57,3797},
{58,3793},
{59,3789},
{60,3786},
{61,3783},
{62,3779},
{63,3776},
{64,3774},
{65,3771},
{66,3768},
{67,3766},
{68,3763},
{69,3760},
{70,3758},
{71,3756},
{72,3753},
{73,3751},
{74,3749},
{75,3746},
{76,3743},
{77,3740},
{78,3738},
{79,3734},
{80,3731},
{81,3728},
{82,3724},
{83,3720},
{84,3715},
{85,3710},
{86,3705},
{86,3699},
{87,3693},
{88,3685},
{89,3680},
{90,3676},
{91,3674},
{92,3672},
{93,3668},
{94,3664},
{95,3655},
{96,3636},
{97,3601},
{98,3548},
{99,3477},
{100,3400}

};     

// T3 50C
BATTERY_PROFILE_STRUCT battery_profile_t3[] =
{
	{0,4303},
{1,4286},
{2,4272},
{3,4260},
{4,4248},
{5,4236},
{6,4224},
{7,4213},
{8,4203},
{9,4191},
{10,4181},
{11,4170},
{12,4159},
{13,4149},
{14,4138},
{15,4128},
{16,4118},
{17,4107},
{18,4098},
{19,4087},
{20,4078},
{21,4068},
{22,4058},
{23,4049},
{24,4040},
{25,4030},
{26,4021},
{27,4012},
{28,4003},
{29,3994},
{30,3986},
{31,3978},
{32,3969},
{33,3961},
{34,3953},
{35,3946},
{36,3938},
{37,3930},
{38,3922},
{39,3914},
{40,3906},
{41,3898},
{42,3889},
{43,3880},
{44,3870},
{45,3862},
{46,3854},
{47,3846},
{48,3840},
{49,3834},
{50,3829},
{51,3824},
{51,3819},
{52,3814},
{53,3810},
{54,3806},
{55,3802},
{56,3798},
{57,3794},
{58,3791},
{59,3787},
{60,3784},
{61,3781},
{62,3777},
{63,3774},
{64,3771},
{65,3769},
{66,3766},
{67,3763},
{68,3760},
{69,3757},
{70,3754},
{71,3750},
{72,3746},
{73,3741},
{74,3737},
{75,3733},
{76,3729},
{77,3725},
{78,3721},
{79,3717},
{80,3714},
{81,3711},
{82,3708},
{83,3703},
{84,3698},
{85,3693},
{86,3687},
{87,3681},
{88,3675},
{89,3667},
{90,3664},
{91,3663},
{92,3661},
{93,3659},
{94,3657},
{95,3651},
{96,3638},
{97,3605},
{98,3557},
{99,3494},
{100,3400},
{100,3400}

};           

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUCT battery_profile_temperature[] =
{
    {0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},          
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0}, 
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0}, 
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},	       
	{0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0} 
};    

// ============================================================
// <Rbat, Battery_Voltage> Table
// ============================================================
// T0 -10C
R_PROFILE_STRUCT r_profile_t0[] =
{
	{198,4330},
{198,4277},
{257,4248},
{268,4223},
{431,4202},
{871,4182},
{862,4164},
{855,4147},
{287,4132},
{290,4118},
{834,4105},
{829,4092},
{292,4079},
{288,4064},
{287,4050},
{284,4034},
{783,4019},
{431,4005},
{772,3992},
{767,3979},
{295,3969},
{296,3959},
{763,3949},
{298,3941},
{300,3933},
{756,3925},
{442,3917},
{753,3909},
{300,3902},
{301,3894},
{442,3887},
{301,3880},
{748,3873},
{301,3866},
{747,3860},
{302,3854},
{444,3847},
{750,3841},
{444,3836},
{751,3830},
{446,3825},
{754,3820},
{754,3815},
{757,3811},
{306,3807},
{307,3803},
{761,3799},
{306,3795},
{309,3792},
{770,3789},
{770,3786},
{450,3783},
{774,3780},
{309,3778},
{451,3775},
{309,3772},
{812,3770},
{819,3767},
{821,3765},
{825,3762},
{534,3760},
{829,3757},
{833,3755},
{536,3752},
{537,3750},
{536,3748},
{844,3745},
{846,3743},
{535,3740},
{852,3738},
{856,3735},
{535,3732},
{861,3730},
{535,3727},
{867,3723},
{533,3721},
{873,3717},
{533,3714},
{880,3711},
{879,3708},
{445,3704},
{531,3700},
{446,3696},
{891,3692},
{443,3688},
{894,3683},
{894,3678},
{896,3673},
{894,3667},
{897,3661},
{896,3655},
{894,3646},
{884,3638},
{888,3628},
{884,3617},
{880,3603},
{873,3588},
{861,3568},
{470,3544},
{834,3513},
{344,3473},
{773,3400},
{773,3400}

};      

// T1 0C
R_PROFILE_STRUCT r_profile_t1[] =
{
	{691,4312},
{691,4277},
{736,4254},
{741,4235},
{733,4218},
{727,4203},
{719,4189},
{708,4174},
{702,4161},
{694,4148},
{684,4136},
{679,4123},
{670,4111},
{663,4100},
{659,4089},
{657,4079},
{654,4069},
{650,4058},
{643,4047},
{636,4034},
{626,4020},
{615,4006},
{608,3992},
{599,3979},
{592,3968},
{589,3957},
{586,3948},
{584,3940},
{584,3932},
{585,3925},
{583,3918},
{581,3910},
{582,3904},
{578,3896},
{577,3890},
{577,3883},
{573,3876},
{573,3870},
{573,3863},
{571,3857},
{571,3851},
{570,3845},
{569,3840},
{569,3834},
{569,3829},
{569,3823},
{569,3819},
{568,3814},
{571,3809},
{570,3804},
{571,3800},
{571,3796},
{574,3792},
{575,3789},
{578,3786},
{579,3783},
{582,3780},
{585,3777},
{589,3774},
{592,3772},
{596,3770},
{598,3767},
{601,3765},
{605,3762},
{611,3761},
{614,3758},
{620,3756},
{627,3753},
{631,3751},
{637,3749},
{644,3746},
{651,3744},
{658,3741},
{665,3738},
{675,3736},
{682,3732},
{693,3729},
{702,3726},
{713,3722},
{727,3719},
{738,3715},
{753,3711},
{768,3707},
{785,3703},
{804,3699},
{822,3694},
{843,3689},
{865,3683},
{891,3677},
{916,3668},
{945,3660},
{979,3649},
{1009,3635},
{1048,3619},
{1084,3599},
{1119,3575},
{1150,3546},
{1173,3512},
{1198,3472},
{1230,3400},
{1230,3400},
{1230,3400},
{1230,3400}

};     

// T2 25C
R_PROFILE_STRUCT r_profile_t2[] =
{
	{233,4315},
{233,4294},
{233,4280},
{232,4266},
{232,4254},
{231,4243},
{231,4231},
{230,4220},
{230,4209},
{229,4198},
{230,4187},
{229,4176},
{230,4166},
{230,4156},
{229,4145},
{230,4135},
{229,4124},
{230,4114},
{231,4104},
{231,4094},
{231,4083},
{232,4073},
{231,4063},
{234,4056},
{235,4049},
{236,4043},
{236,4031},
{233,4015},
{232,3998},
{232,3984},
{230,3973},
{230,3964},
{232,3957},
{233,3951},
{233,3946},
{233,3940},
{230,3933},
{230,3925},
{226,3916},
{225,3907},
{224,3899},
{223,3891},
{221,3883},
{219,3876},
{218,3868},
{217,3861},
{216,3854},
{215,3848},
{215,3842},
{215,3837},
{214,3831},
{215,3827},
{215,3822},
{215,3817},
{214,3813},
{214,3808},
{215,3804},
{216,3801},
{215,3797},
{216,3793},
{216,3789},
{216,3786},
{216,3783},
{216,3779},
{216,3776},
{217,3774},
{217,3771},
{217,3768},
{218,3766},
{217,3763},
{216,3760},
{217,3758},
{218,3756},
{219,3753},
{218,3751},
{219,3749},
{218,3746},
{218,3743},
{219,3740},
{220,3738},
{220,3734},
{221,3731},
{221,3728},
{221,3724},
{222,3720},
{222,3715},
{224,3710},
{225,3705},
{226,3699},
{226,3693},
{227,3685},
{227,3680},
{229,3676},
{232,3674},
{235,3672},
{239,3668},
{244,3664},
{250,3655},
{255,3636},
{259,3601},
{265,3548},
{277,3477},
{299,3400}

}; 

// T3 50C
R_PROFILE_STRUCT r_profile_t3[] =
{
	{176,4303},
{176,4286},
{174,4272},
{174,4260},
{174,4248},
{174,4236},
{173,4224},
{173,4213},
{174,4203},
{174,4191},
{174,4181},
{174,4170},
{174,4159},
{174,4149},
{174,4138},
{174,4128},
{174,4118},
{175,4107},
{176,4098},
{176,4087},
{176,4078},
{176,4068},
{177,4058},
{177,4049},
{178,4040},
{178,4030},
{178,4021},
{178,4012},
{178,4003},
{178,3994},
{179,3986},
{180,3978},
{180,3969},
{182,3961},
{181,3953},
{182,3946},
{182,3938},
{183,3930},
{184,3922},
{183,3914},
{184,3906},
{182,3898},
{181,3889},
{180,3880},
{177,3870},
{175,3862},
{174,3854},
{172,3846},
{172,3840},
{170,3834},
{171,3829},
{171,3824},
{171,3819},
{170,3814},
{171,3810},
{172,3806},
{171,3802},
{171,3798},
{172,3794},
{172,3791},
{173,3787},
{174,3784},
{174,3781},
{173,3777},
{174,3774},
{174,3771},
{174,3769},
{175,3766},
{175,3763},
{174,3760},
{174,3757},
{175,3754},
{173,3750},
{173,3746},
{171,3741},
{171,3737},
{171,3733},
{170,3729},
{169,3725},
{169,3721},
{170,3717},
{171,3714},
{171,3711},
{173,3708},
{171,3703},
{171,3698},
{172,3693},
{171,3687},
{172,3681},
{173,3675},
{170,3667},
{171,3664},
{173,3663},
{175,3661},
{177,3659},
{178,3657},
{181,3651},
{180,3638},
{178,3605},
{179,3557},
{182,3494},
{185,3400},
{185,3400}

}; 

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUCT r_profile_temperature[] =
{
    {0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},         
	{0  , 0},          
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0}, 
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0}, 
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},
	{0  , 0},	       
	{0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0},
    {0  , 0}  
};    

/* ============================================================
// function prototype
// ============================================================*/
int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUCT_P fgauge_get_profile(unsigned int temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUCT_P fgauge_get_profile_r_table(unsigned int temperature);

#endif	/*#ifndef _CUST_BATTERY_METER_TABLE_H*/

