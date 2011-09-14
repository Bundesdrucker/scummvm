/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef 16COMP_H
#define 16COMP_H

Compact reactor_lower = {
	0,	// logic
	ST_BACKGROUND+ST_RECREATE,	// status
	0,	// sync
	16,	// screen
	0,	// place
	0,	// getToTable
	249,	// xcood
	226,	// ycood
	109*64,	// frame
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	{ 0, 0, 0 },
	0,
	0,
	0,
	0,
	0
};

uint16 foster2_die_seq[] = {
	32*64,
	237,
	242,
	0,
	237,
	242,
	1,
	235,
	242,
	2,
	235,
	242,
	3,
	234,
	242,
	4,
	233,
	242,
	5,
	232,
	242,
	6,
	233,
	242,
	5,
	232,
	242,
	6,
	233,
	242,
	5,
	232,
	242,
	7,
	233,
	242,
	8,
	232,
	243,
	9,
	233,
	243,
	10,
	232,
	243,
	11,
	233,
	242,
	5,
	232,
	242,
	6,
	234,
	242,
	12,
	234,
	242,
	13,
	238,
	242,
	14,
	236,
	241,
	15,
	236,
	241,
	16,
	237,
	241,
	17,
	233,
	241,
	18,
	228,
	241,
	19,
	226,
	241,
	20,
	215,
	246,
	21,
	198,
	258,
	22,
	185,
	273,
	23,
	184,
	273,
	24,
	184,
	273,
	25,
	184,
	273,
	26,
	184,
	273,
	27,
	0
};

Compact reactor_console = {
	L_SCRIPT,	// logic
	ST_MOUSE+ST_LOGIC+ST_BACKGROUND,	// status
	0,	// sync
	16,	// screen
	0,	// place
	0,	// getToTable
	65,	// xcood
	59,	// ycood
	31*64,	// frame
	8394,	// cursorText
	STD_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	386-365,	// mouseSize_x
	278-259,	// mouseSize_y
	REACTOR_PC_ACTION,	// actionScript
	0,	// upFlag
	0,	// downFlag
	0,	// getToFlag
	0,	// flag
	0,	// mood
	{ 0, 0, 0 },
	0,	// offset
	C_BASE_MODE,	// mode
	CONSOLE_16_LOGIC,	// baseSub
	0,	// baseSub_off
	0
};

uint32 *grid16 = 0;

uint16 s16_fast_list[] = {
	12,
	51,
	52,
	53,
	54,
	135,
	93+DISK_6,
	94+DISK_6,
	95+DISK_6,
	0
};

Compact entrance_exit = {
	0,	// logic
	ST_MOUSE,	// status
	0,	// sync
	16,	// screen
	0,	// place
	0,	// getToTable
	186,	// xcood
	220,	// ycood
	0,	// frame
	1+T7,	// cursorText
	STD_EXIT_LEFT_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	203-186,	// mouseSize_x
	294-220,	// mouseSize_y
	ENTRANCE_EXIT_ACTION,	// actionScript
	0,
	0,
	0,
	0,
	0,
	{ 0, 0, 0 },
	0,
	0,
	0,
	0,
	0
};

uint16 console_16_seq[] = {
	31*64,
	368,
	260,
	0,
	368,
	260,
	1,
	368,
	260,
	2,
	368,
	260,
	3,
	368,
	260,
	4,
	368,
	260,
	5,
	368,
	260,
	6,
	368,
	260,
	7,
	368,
	260,
	8,
	368,
	260,
	9,
	368,
	260,
	10,
	0
};

uint16 s16_floor_table[] = {
	ID_S16_FLOOR,
	RET_OK,
	ID_JOEY_PARK,
	GET_TO_JP2,
	0,
	S16_LEFT_ON,
	1,
	S16_CORE_ON,
	ID_ENTRANCE_EXIT,
	GT_ENTRANCE_EXIT,
	ID_REACTOR_PC,
	GT_REACTOR_CONSOLE,
	ID_REACTOR_DOOR,
	GT_REACTOR_DOOR,
	ID_STD_LEFT_TALK,
	GT_L_TALK_16,
	ID_STD_RIGHT_TALK,
	GT_R_TALK_16,
	65535
};

Compact s16_floor = {
	0,	// logic
	ST_MOUSE,	// status
	0,	// sync
	16,	// screen
	0,	// place
	s16_floor_table,	// getToTable
	181,	// xcood
	277,	// ycood
	0,	// frame
	0,	// cursorText
	0,	// mouseOn
	0,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	416-181,	// mouseSize_x
	321-277,	// mouseSize_y
	FLOOR_ACTION,	// actionScript
	0,
	0,
	0,
	0,
	0,
	{ 0, 0, 0 },
	0,
	0,
	0,
	0,
	0
};

uint16 s16_pal[] = {
	0,
	1024,
	1028,
	1028,
	1542,
	1540,
	1542,
	1542,
	2054,
	1544,
	2054,
	2054,
	1546,
	2056,
	2056,
	2056,
	2058,
	3080,
	2058,
	2058,
	2570,
	2570,
	2568,
	3082,
	2574,
	3084,
	3084,
	3086,
	3594,
	3084,
	3598,
	3082,
	3598,
	3596,
	4112,
	3598,
	3602,
	4110,
	3600,
	4112,
	5136,
	2576,
	3608,
	5128,
	3088,
	4114,
	4112,
	4626,
	4628,
	5132,
	4624,
	5136,
	5142,
	3604,
	4632,
	5646,
	4626,
	5138,
	5652,
	5138,
	5142,
	6160,
	3604,
	5146,
	5134,
	5654,
	5656,
	6672,
	5142,
	6166,
	6678,
	4120,
	6168,
	6676,
	4632,
	5157,
	6154,
	6168,
	6678,
	7192,
	4634,
	6686,
	7186,
	4636,
	6691,
	9998,
	3096,
	6686,
	7702,
	6170,
	7198,
	6162,
	6686,
	6185,
	6668,
	6686,
	8474,
	7192,
	7198,
	7713,
	9492,
	5148,
	7713,
	8982,
	5150,
	8988,
	10520,
	5660,
	8990,
	8988,
	6689,
	8485,
	10008,
	5665,
	8995,
	9496,
	5667,
	8485,
	8988,
	5669,
	8997,
	11546,
	4129,
	7727,
	8468,
	6695,
	9507,
	12574,
	5150,
	10019,
	10524,
	6181,
	10025,
	9494,
	6185,
	10023,
	13084,
	5665,
	10025,
	9502,
	8489,
	10025,
	13089,
	6179,
	10537,
	9502,
	8491,
	10541,
	11032,
	6187,
	11561,
	11546,
	6187,
	11049,
	12581,
	7209,
	11051,
	14115,
	6695,
	12073,
	11036,
	9517,
	12079,
	12568,
	6191,
	12077,
	12577,
	6703,
	12079,
	14115,
	7723,
	13103,
	13086,
	8497,
	12593,
	13607,
	6707,
	13105,
	13605,
	6197,
	13109,
	14113,
	6711,
	13623,
	14629,
	8503,
	14649,
	14618,
	9015,
	15163,
	15642,
	7227,
	256,
	2,
	2823,
	3843,
	2068,
	7448,
	6922,
	3616,
	9247,
	8977,
	5672,
	11304,
	10777,
	7214,
	12589,
	12062,
	8499,
	13618,
	13348,
	10039,
	14647,
	14634,
	11835,
	15932,
	42,
	2816,
	2571,
	3341,
	4621,
	3343,
	4630,
	6925,
	5401,
	7200,
	16150,
	16191,
	11,
	3072,
	0,
	12,
	3328,
	0,
	13,
	3584,
	0,
	14,
	3840,
	0,
	15,
	4096,
	0,
	3084,
	4108,
	0,
	3084,
	2060,
	0,
	4116,
	2316,
	0,
	5144,
	5134,
	0,
	6168,
	2580,
	0,
	6686,
	2582,
	0,
	7713,
	5910,
	0,
	23,
	6144,
	0,
	24,
	6400,
	0,
	25,
	6656,
	0,
	26,
	6912,
	0,
	27,
	7168,
	0,
	28,
	7424,
	0,
	29,
	7680,
	0,
	30,
	7936,
	0,
	0,
	14336,
	13364,
	11569,
	9261,
	8481,
	6687,
	6681,
	4626,
	2578,
	1803,
	770,
	519,
	13571,
	9517,
	9778,
	11805,
	5151,
	5926,
	8205,
	1808,
	2586,
	11267,
	2056,
	8210,
	7441,
	6954,
	9494,
	4119,
	3866,
	4864,
	13316,
	13364,
	11563,
	8751,
	9506,
	10024,
	8242,
	10527,
	6174,
	5927,
	7698,
	3600,
	2325,
	2308,
	11573,
	12837,
	7462,
	7982,
	9748,
	3351,
	4128,
	6663,
	778,
	9533,
	13100,
	9244,
	5162,
	8476,
	5390,
	2072,
	3855,
	2308,
	2865,
	9995,
	1285,
	285,
	4865,
	0,
	11573,
	12837,
	7462,
	0,
	16128,
	0,
	16191,
	14655,
	0,
	58,
	14848,
	0,
	59,
	13824,
	13878,
	12077,
	8241,
	10527,
	5917,
	5925,
	7698,
	2865,
	9995,
	1285,
	285,
	16129,
	16191
};

uint16 s16_chip_list[] = {
	173,
	111,
	136+DISK_2,
	137+DISK_2,
	90+DISK_6,
	96+DISK_6,
	97+DISK_6,
	106+DISK_6,
	108+DISK_6,
	109+DISK_6,
	146+DISK_6,
	147+DISK_6,
	31+DISK_6,
	32+DISK_6,
	0
};

uint16 rad_con_look[] = {
	146*64,
	288,
	201,
	0,
	288,
	201,
	1,
	288,
	201,
	2,
	288,
	201,
	3,
	288,
	201,
	4,
	288,
	201,
	5,
	288,
	201,
	6,
	288,
	201,
	7,
	288,
	201,
	0,
	288,
	201,
	0,
	0
};

uint16 s16_logic[] = {
	ID_FOSTER,
	ID_JOEY,
	ID_RADMAN,
	ID_ANITA,
	ID_REACTOR_DOOR,
	ID_REACTOR_LOWER,
	ID_REACTOR_PC,
	0XFFFF,
	ID_MENU_LOGIC
};

uint16 foster_die_seq[] = {
	32*64,
	349,
	250,
	0,
	349,
	250,
	1,
	347,
	250,
	2,
	347,
	250,
	3,
	346,
	250,
	4,
	345,
	250,
	5,
	344,
	250,
	6,
	345,
	250,
	5,
	344,
	250,
	6,
	345,
	250,
	5,
	344,
	250,
	7,
	345,
	250,
	8,
	344,
	251,
	9,
	345,
	251,
	10,
	344,
	251,
	11,
	345,
	250,
	5,
	344,
	250,
	6,
	346,
	250,
	12,
	346,
	250,
	13,
	350,
	250,
	14,
	348,
	249,
	15,
	348,
	249,
	16,
	349,
	249,
	17,
	345,
	249,
	18,
	340,
	249,
	19,
	338,
	249,
	20,
	327,
	254,
	21,
	310,
	266,
	22,
	297,
	273,
	23,
	296,
	273,
	24,
	296,
	273,
	25,
	296,
	273,
	26,
	296,
	273,
	27,
	0
};

Compact reactor_door = {
	0,	// logic
	ST_RECREATE+ST_BACKGROUND+ST_MOUSE,	// status
	0,	// sync
	16,	// screen
	0,	// place
	0,	// getToTable
	249,	// xcood
	175,	// ycood
	108*64,	// frame
	9295,	// cursorText
	REACTOR_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	342-251,	// mouseSize_x
	266-176,	// mouseSize_y
	REACTOR_DOOR_ACTION,	// actionScript
	0,
	0,
	0,
	0,
	0,
	{ 0, 0, 0 },
	0,
	0,
	0,
	0,
	0
};

uint16 s16_mouse[] = {
	ID_JOEY,
	ID_RADMAN,
	ID_ENTRANCE_EXIT,
	ID_REACTOR_PC,
	ID_REACTOR_DOOR,
	ID_S16_FLOOR,
	0XFFFF,
	ID_TEXT_MOUSE
};

uint16 rs_foster_14_16[] = {
	C_XCOOD,
	160,
	C_YCOOD,
	288,
	C_SCREEN,
	16,
	C_PLACE,
	ID_S16_FLOOR,
	65535
};

uint16 fost_con_look[] = {
	147*64,
	264,
	214,
	0,
	264,
	214,
	1,
	264,
	214,
	2,
	264,
	214,
	2,
	264,
	214,
	2,
	264,
	214,
	2,
	264,
	214,
	2,
	264,
	214,
	2,
	264,
	214,
	1,
	264,
	214,
	3,
	0
};

#endif
