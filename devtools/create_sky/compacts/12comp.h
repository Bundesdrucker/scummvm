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

#ifndef SKY12COMP_H
#define SKY12COMP_H

uint16 botbelt_seq[] = {
	44*64,
	280,
	295,
	0,
	280,
	295,
	1,
	280,
	295,
	2,
	280,
	295,
	3,
	280,
	295,
	4,
	280,
	295,
	5,
	280,
	295,
	6,
	280,
	295,
	7,
	280,
	295,
	5,
	280,
	295,
	6,
	280,
	295,
	8,
	280,
	295,
	9,
	280,
	295,
	10,
	280,
	295,
	11,
	280,
	295,
	12,
	280,
	295,
	13,
	280,
	295,
	14,
	280,
	295,
	15,
	280,
	295,
	16,
	280,
	295,
	17,
	280,
	295,
	18,
	280,
	295,
	19,
	280,
	295,
	20,
	280,
	295,
	21,
	280,
	295,
	22,
	280,
	295,
	23,
	280,
	295,
	24,
	280,
	295,
	25,
	280,
	295,
	26,
	280,
	295,
	27,
	280,
	295,
	28,
	280,
	295,
	29,
	280,
	295,
	30,
	280,
	295,
	31,
	280,
	295,
	7,
	280,
	295,
	5,
	280,
	295,
	6,
	280,
	295,
	7,
	280,
	295,
	5,
	280,
	295,
	6,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	32,
	280,
	295,
	33,
	0
};

uint16 s12_floor_table[] = {
	ID_S12_FLOOR,
	RET_OK,
	ID_JOEY_PARK,
	GET_TO_JP2,
	0,
	S12_LEFT_ON,
	1,
	S12_RIGHT_ON,
	4,
	GT_TICK_OFF,
	5,
	GT_TOUR_1,
	ID_FACTORY_EXIT,
	GET_TO_FACTORY_EXIT,
	ID_FACT1_EXIT,
	GT_FACT1_EXIT,
	ID_ANITA,
	GT_ANITA,
	ID_WELDER,
	GT_WELDER,
	ID_STUMP,
	GT_STUMP,
	ID_CONSOLE_12,
	GT_CONSOLE_12,
	ID_STD_LEFT_TALK,
	GT_L_TALK_12,
	ID_STD_RIGHT_TALK,
	GT_R_TALK_12,
	65535
};

uint16 swap1_seq[] = {
	69*64,
	248,
	184,
	0,
	248,
	184,
	1,
	248,
	184,
	2,
	248,
	184,
	3,
	248,
	184,
	4,
	248,
	184,
	5,
	248,
	184,
	6,
	248,
	184,
	7,
	248,
	184,
	8,
	248,
	184,
	9,
	248,
	184,
	10,
	248,
	184,
	11,
	248,
	184,
	10,
	248,
	184,
	12,
	248,
	184,
	13,
	248,
	184,
	14,
	248,
	184,
	15,
	248,
	184,
	16,
	248,
	184,
	17,
	248,
	184,
	18,
	248,
	184,
	19,
	0
};

uint16 rs_joey_start_12[] = {
	C_XCOOD,
	256,
	C_YCOOD,
	264,
	C_PLACE,
	ID_S12_FLOOR,
	C_SCREEN,
	12,
	C_MODE,
	0,
	C_BASE_SUB,
	JOEY_LOGIC,
	C_BASE_SUB+2,
	0,
	C_STATUS,
	ST_SORT+ST_RECREATE+ST_LOGIC+ST_GRID_PLOT+ST_COLLISION+ST_MOUSE,
	C_DIR,
	RIGHT,
	65535
};

uint16 rs_lamb_start_fact[] = {
	C_XCOOD,
	336,
	C_YCOOD,
	224,
	C_SCREEN,
	12,
	C_PLACE,
	ID_S12_FLOOR,
	C_STATUS,
	ST_SORT+ST_RECREATE+ST_LOGIC+ST_GRID_PLOT+ST_COLLISION+ST_MOUSE,
	65535
};

uint16 welder_seq[] = {
	45*64,
	1,
	1,
	1,
	1,
	1,
	2,
	1,
	1,
	3,
	1,
	1,
	4,
	1,
	1,
	5,
	1,
	1,
	6,
	1,
	1,
	7,
	1,
	1,
	8,
	1,
	1,
	0,
	0
};

uint16 rs_foster_7_12[] = {
	C_XCOOD,
	144,
	C_YCOOD,
	240,
	C_SCREEN,
	12,
	C_PLACE,
	ID_S12_FLOOR,
	65535
};

uint16 factory_spanner_seq[] = {
	46*64,
	239,
	195,
	0,
	239,
	195,
	0,
	239,
	195,
	1,
	239,
	195,
	1,
	239,
	195,
	2,
	239,
	195,
	3,
	239,
	195,
	4,
	239,
	195,
	5,
	239,
	195,
	6,
	239,
	195,
	6,
	239,
	195,
	6,
	239,
	195,
	7,
	239,
	195,
	8,
	239,
	195,
	9,
	239,
	195,
	7,
	239,
	195,
	10,
	239,
	195,
	10,
	239,
	195,
	11,
	239,
	195,
	12,
	0
};

uint16 pipes_seq[] = {
	92*64,
	281,
	206,
	0,
	281,
	206,
	1,
	281,
	206,
	2,
	281,
	206,
	0,
	281,
	206,
	1,
	281,
	206,
	2,
	281,
	206,
	0,
	281,
	206,
	1,
	281,
	206,
	2,
	281,
	206,
	0,
	281,
	206,
	1,
	281,
	206,
	2,
	281,
	206,
	0,
	281,
	206,
	1,
	281,
	206,
	2,
	281,
	206,
	0,
	281,
	206,
	1,
	281,
	206,
	3,
	281,
	206,
	4,
	281,
	206,
	5,
	281,
	206,
	6,
	281,
	206,
	7,
	281,
	206,
	8,
	281,
	206,
	9,
	281,
	206,
	10,
	281,
	206,
	11,
	281,
	206,
	12,
	281,
	206,
	13,
	281,
	206,
	14,
	281,
	206,
	15,
	281,
	206,
	16,
	281,
	206,
	17,
	281,
	206,
	18,
	281,
	206,
	19,
	281,
	206,
	20,
	281,
	206,
	21,
	281,
	206,
	22,
	281,
	206,
	23,
	281,
	206,
	24,
	281,
	206,
	0,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	1,
	281,
	206,
	2,
	0
};

uint16 swap3_seq[] = {
	71*64,
	222,
	184,
	0,
	222,
	184,
	1,
	222,
	184,
	2,
	220,
	184,
	3,
	219,
	184,
	4,
	218,
	184,
	5,
	219,
	184,
	6,
	220,
	184,
	7,
	219,
	185,
	8,
	219,
	186,
	9,
	221,
	185,
	10,
	222,
	185,
	11,
	222,
	185,
	12,
	222,
	185,
	11,
	221,
	185,
	10,
	220,
	185,
	13,
	221,
	185,
	10,
	221,
	186,
	14,
	218,
	187,
	15,
	216,
	189,
	16,
	218,
	187,
	17,
	219,
	186,
	18,
	220,
	186,
	19,
	221,
	186,
	20,
	220,
	186,
	19,
	0
};

Compact fact1_right_exit = {
	0,	// logic
	ST_MOUSE,	// status
	0,	// sync
	12,	// screen
	0,	// place
	0,	// getToTable
	432,	// xcood
	190,	// ycood
	0,	// frame
	1+T7,	// cursorText
	STD_EXIT_RIGHT_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	1000,	// mouseSize_x
	295-190,	// mouseSize_y
	FACT1_EXIT_ACTION,	// actionScript
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

Compact pipes = {
	L_SCRIPT,	// logic
	ST_BACKGROUND+ST_LOGIC,	// status
	0,	// sync
	12,	// screen
	0,	// place
	0,	// getToTable
	28,	// xcood
	36,	// ycood
	92*64,	// frame
	0,	// cursorText
	0,	// mouseOn
	0,	// mouseOff
	0,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	0,	// mouseSize_x
	0,	// mouseSize_y
	0,	// actionScript
	0,	// upFlag
	0,	// downFlag
	0,	// getToFlag
	0,	// flag
	0,	// mood
	{ 0, 0, 0 },
	0,	// offset
	C_BASE_MODE,	// mode
	STD_FACT_LOGIC,	// baseSub
	0,	// baseSub_off
	0
};

Compact botbelt = {
	L_SCRIPT,	// logic
	ST_BACKGROUND+ST_LOGIC,	// status
	0,	// sync
	12,	// screen
	0,	// place
	0,	// getToTable
	28,	// xcood
	36,	// ycood
	44*64,	// frame
	0,	// cursorText
	0,	// mouseOn
	0,	// mouseOff
	0,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	0,	// mouseSize_x
	0,	// mouseSize_y
	0,	// actionScript
	0,	// upFlag
	0,	// downFlag
	0,	// getToFlag
	0,	// flag
	0,	// mood
	{ 0, 0, 0 },
	0,	// offset
	C_BASE_MODE,	// mode
	BOTBELT_LOGIC,	// baseSub
	0,	// baseSub_off
	0
};

uint16 joey_list_12[] = {
	230,
	376,
	256,
	272,
	1,
	0
};

Compact welder = {
	L_SCRIPT,	// logic
	ST_BACKGROUND+ST_LOGIC+ST_RECREATE+ST_MOUSE,	// status
	0,	// sync
	12,	// screen
	0,	// place
	0,	// getToTable
	0XFB,	// xcood
	0XBB,	// ycood
	45*64,	// frame
	59,	// cursorText
	STD_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	8,	// mouseRel_x
	0,	// mouseRel_y
	24,	// mouseSize_x
	40,	// mouseSize_y
	WELDER_ACTION,	// actionScript
	0,	// upFlag
	0,	// downFlag
	0,	// getToFlag
	0,	// flag
	0,	// mood
	{ 0, 0, 0 },
	0,	// offset
	C_BASE_MODE,	// mode
	WELDER_LOGIC,	// baseSub
	0,	// baseSub_off
	0
};

Compact factory_exit = {
	0,	// logic
	ST_MOUSE,	// status
	0,	// sync
	12,	// screen
	0,	// place
	0,	// getToTable
	171,	// xcood
	190,	// ycood
	0,	// frame
	1+T7,	// cursorText
	STD_EXIT_LEFT_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	190-171,	// mouseSize_x
	248-190,	// mouseSize_y
	FACTORY_EXIT_ACTION,	// actionScript
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

uint32 *grid12 = 0;

uint16 s12_pal[] = {
	0,
	1024,
	516,
	1030,
	1540,
	1542,
	1544,
	2052,
	1542,
	2058,
	2566,
	2056,
	2060,
	3078,
	2570,
	2574,
	4106,
	2058,
	3084,
	3594,
	2572,
	2580,
	3590,
	3084,
	2580,
	3592,
	4110,
	3600,
	4622,
	3086,
	3096,
	3592,
	4112,
	4112,
	7184,
	2060,
	3608,
	6666,
	3086,
	4118,
	4622,
	4626,
	4628,
	8462,
	2572,
	4634,
	4616,
	4628,
	5138,
	6164,
	4114,
	5140,
	8980,
	3086,
	4131,
	6156,
	5140,
	4131,
	5646,
	5142,
	5654,
	5656,
	4632,
	5148,
	7698,
	3094,
	5150,
	7186,
	4630,
	6166,
	6170,
	6168,
	6170,
	6678,
	4122,
	6168,
	8474,
	5144,
	7706,
	10002,
	4630,
	6179,
	7188,
	6682,
	6686,
	9496,
	5144,
	6689,
	7190,
	3617,
	7196,
	7708,
	6684,
	7205,
	10510,
	3098,
	7205,
	9488,
	6170,
	7708,
	7710,
	5665,
	7205,
	7704,
	8478,
	8990,
	7700,
	6689,
	7713,
	7710,
	8993,
	8489,
	9998,
	6686,
	8483,
	10014,
	4131,
	8993,
	10531,
	6689,
	8993,
	10533,
	7201,
	10019,
	11032,
	7201,
	9517,
	9486,
	4649,
	9517,
	10512,
	7715,
	9507,
	10021,
	8485,
	10533,
	12058,
	3623,
	9511,
	9509,
	7209,
	9005,
	10526,
	5673,
	10021,
	9511,
	10535,
	9517,
	10017,
	10023,
	10545,
	12048,
	8485,
	11057,
	12560,
	4651,
	10031,
	10531,
	7213,
	11563,
	10524,
	9005,
	11049,
	10537,
	11051,
	10543,
	12581,
	9001,
	11051,
	12073,
	6703,
	12077,
	11041,
	9519,
	11059,
	11559,
	11567,
	12077,
	12591,
	7731,
	13103,
	12069,
	11057,
	12085,
	12585,
	11057,
	13105,
	13105,
	12083,
	13619,
	14129,
	13111,
	2829,
	3851,
	3341,
	3856,
	4367,
	4369,
	2111,
	6144,
	7193,
	6681,
	6941,
	7708,
	7452,
	12575,
	8,
	5663,
	8211,
	4887,
	6178,
	9237,
	5914,
	7207,
	10521,
	6686,
	3102,
	9482,
	3603,
	6439,
	10512,
	4638,
	9259,
	11540,
	5929,
	12079,
	6426,
	4891,
	7963,
	8211,
	5669,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
	16128,
	0,
	63,
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
	16191,
	63,
	16191,
	16128,
	63,
	16191,
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

uint16 cant_lift_seq[] = {
	69*64,
	1,
	1,
	0,
	1,
	1,
	1,
	1,
	1,
	2,
	1,
	1,
	3,
	1,
	1,
	4,
	1,
	1,
	5,
	1,
	1,
	6,
	1,
	1,
	5,
	1,
	1,
	7,
	1,
	1,
	8,
	1,
	1,
	9,
	1,
	1,
	10,
	1,
	1,
	9,
	1,
	1,
	11,
	1,
	1,
	12,
	1,
	1,
	13,
	1,
	1,
	14,
	1,
	1,
	15,
	1,
	1,
	5,
	1,
	1,
	3,
	1,
	1,
	1,
	0
};

Compact topbelt = {
	L_SCRIPT,	// logic
	ST_BACKGROUND+ST_LOGIC,	// status
	0,	// sync
	12,	// screen
	0,	// place
	0,	// getToTable
	28,	// xcood
	36,	// ycood
	91*64,	// frame
	0,	// cursorText
	0,	// mouseOn
	0,	// mouseOff
	0,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	0,	// mouseSize_x
	0,	// mouseSize_y
	0,	// actionScript
	0,	// upFlag
	0,	// downFlag
	0,	// getToFlag
	0,	// flag
	0,	// mood
	{ 0, 0, 0 },
	0,	// offset
	C_BASE_MODE,	// mode
	STD_FACT_LOGIC,	// baseSub
	0,	// baseSub_off
	0
};

uint16 s12_fast_list[] = {
	12,
	51,
	52,
	53,
	54,
	135,
	14+DISK_3,
	16+DISK_3,
	91+DISK_3,
	0
};

uint16 s12_new_chip[] = {
	173,
	111,
	136+DISK_2,
	137+DISK_2,
	131+DISK_2,
	132+DISK_2,
	44+DISK_3,
	45+DISK_3,
	46+DISK_3+0X8000,
	69+DISK_3+0X8000,
	70+DISK_3+0X8000,
	71+DISK_3+0X8000,
	15+DISK_3,
	92+DISK_3,
	0
};

Compact console_12 = {
	0,	// logic
	0,	// status
	0,	// sync
	12,	// screen
	0,	// place
	0,	// getToTable
	341,	// xcood
	197,	// ycood
	0,	// frame
	8371,	// cursorText
	STD_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	368-341,	// mouseSize_x
	6,	// mouseSize_y
	CONSOLE_12_ACTION,	// actionScript
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

uint16 anita_walk_seq[] = {
	90*64,
	352,
	181,
	0,
	352,
	184,
	1,
	351,
	185,
	2,
	351,
	187,
	3,
	351,
	189,
	4,
	351,
	192,
	5,
	351,
	193,
	6,
	352,
	195,
	7,
	352,
	197,
	0,
	352,
	200,
	1,
	351,
	201,
	2,
	351,
	203,
	3,
	351,
	205,
	4,
	351,
	208,
	5,
	351,
	209,
	6,
	352,
	211,
	7,
	352,
	211,
	8,
	352,
	211,
	9,
	351,
	211,
	10,
	355,
	212,
	11,
	363,
	211,
	12,
	368,
	211,
	13,
	367,
	211,
	14,
	371,
	212,
	15,
	380,
	211,
	16,
	384,
	211,
	9,
	383,
	211,
	10,
	387,
	212,
	11,
	395,
	211,
	12,
	400,
	211,
	13,
	399,
	211,
	14,
	403,
	212,
	15,
	412,
	211,
	16,
	416,
	211,
	9,
	415,
	211,
	10,
	419,
	212,
	11,
	425,
	211,
	17,
	425,
	211,
	18,
	425,
	211,
	19,
	425,
	212,
	20,
	425,
	215,
	21,
	0
};

uint16 anita_work_seq[] = {
	27*64,
	343,
	178,
	0,
	343,
	178,
	0,
	343,
	178,
	1,
	343,
	178,
	1,
	343,
	178,
	2,
	343,
	178,
	2,
	343,
	178,
	3,
	343,
	178,
	3,
	343,
	178,
	4,
	343,
	178,
	4,
	343,
	178,
	5,
	343,
	178,
	5,
	343,
	178,
	6,
	343,
	178,
	6,
	343,
	178,
	7,
	343,
	178,
	7,
	343,
	178,
	8,
	343,
	178,
	8,
	343,
	178,
	9,
	343,
	178,
	9,
	343,
	178,
	10,
	343,
	178,
	10,
	343,
	178,
	11,
	343,
	178,
	11,
	343,
	178,
	9,
	343,
	178,
	9,
	343,
	178,
	12,
	343,
	178,
	12,
	343,
	178,
	13,
	343,
	178,
	13,
	343,
	178,
	14,
	343,
	178,
	14,
	343,
	178,
	15,
	343,
	178,
	15,
	343,
	178,
	16,
	343,
	178,
	16,
	343,
	178,
	0,
	343,
	178,
	0,
	343,
	178,
	1,
	343,
	178,
	1,
	343,
	178,
	2,
	343,
	178,
	2,
	343,
	178,
	3,
	343,
	178,
	3,
	343,
	178,
	4,
	343,
	178,
	4,
	343,
	178,
	3,
	343,
	178,
	3,
	343,
	178,
	2,
	343,
	178,
	2,
	343,
	178,
	1,
	343,
	178,
	1,
	343,
	178,
	0,
	343,
	178,
	0,
	343,
	178,
	5,
	343,
	178,
	5,
	343,
	178,
	6,
	343,
	178,
	6,
	343,
	178,
	7,
	343,
	178,
	7,
	343,
	178,
	6,
	343,
	178,
	6,
	343,
	178,
	7,
	343,
	178,
	7,
	0X157,
	0XB3,
	0,
	0
};

uint16 anita_turn_seq[] = {
	29*64,
	343,
	178,
	0,
	343,
	178,
	1,
	343,
	178,
	2,
	343,
	178,
	3,
	343,
	178,
	4,
	343,
	178,
	5,
	0
};

uint16 anita_turn_back[] = {
	29*64,
	1,
	1,
	5,
	1,
	1,
	4,
	1,
	1,
	3,
	1,
	1,
	2,
	1,
	1,
	1,
	1,
	1,
	0,
	0
};

uint16 rs_foster_12_7[] = {
	C_XCOOD,
	376,
	C_YCOOD,
	240,
	C_SCREEN,
	7,
	C_PLACE,
	ID_S7_FLOOR,
	65535
};

uint16 s12_mouse[] = {
	ID_JOEY,
	ID_FACTORY_EXIT,
	ID_FACT1_EXIT,
	ID_ANITA,
	ID_LAMB,
	ID_STUMP,
	ID_CONSOLE_12,
	ID_S12_FLOOR,
	ID_ANITA_SPY,
	ID_WELDER,
	0XFFFF,
	ID_TEXT_MOUSE
};

uint16 s12_chip_list[] = {
	173,
	111,
	136+DISK_2,
	137+DISK_2,
	131+DISK_2,
	132+DISK_2,
	27+DISK_3,
	28+DISK_3+0X8000,
	29+DISK_3+0X8000,
	30+DISK_3+0X8000,
	44+DISK_3,
	45+DISK_3,
	46+DISK_3+0X8000,
	90+DISK_3+0X8000,
	15+DISK_3,
	92+DISK_3,
	0
};

Compact stump = {
	L_SCRIPT,	// logic
	0,	// status
	0,	// sync
	12,	// screen
	0,	// place
	0,	// getToTable
	249,	// xcood
	208,	// ycood
	0,	// frame
	9282,	// cursorText
	STD_ON,	// mouseOn
	STD_OFF,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	279-249,	// mouseSize_x
	230-208,	// mouseSize_y
	STUMP_ACTION,	// actionScript
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

uint16 swap2_seq[] = {
	70*64,
	252,
	183,
	0,
	251,
	183,
	1,
	250,
	183,
	2,
	248,
	183,
	3,
	249,
	183,
	4,
	248,
	183,
	5,
	248,
	183,
	6,
	247,
	183,
	7,
	244,
	183,
	8,
	241,
	183,
	9,
	237,
	183,
	10,
	235,
	183,
	11,
	0
};

Compact anita_spy = {
	L_SCRIPT,	// logic
	ST_LOGIC,	// status
	0,	// sync
	12,	// screen
	0,	// place
	0,	// getToTable
	375,	// xcood
	151,	// ycood
	0,	// frame
	0,	// cursorText
	0,	// mouseOn
	0,	// mouseOff
	0,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	1,	// mouseSize_x
	1,	// mouseSize_y
	0,	// actionScript
	0,	// upFlag
	0,	// downFlag
	0,	// getToFlag
	0,	// flag
	0,	// mood
	{ 0, 0, 0 },
	0,	// offset
	C_BASE_MODE,	// mode
	ANITA_SPY_LOGIC,	// baseSub
	0,	// baseSub_off
	0
};

Compact s12_floor = {
	0,	// logic
	ST_MOUSE,	// status
	0,	// sync
	12,	// screen
	0,	// place
	s12_floor_table,	// getToTable
	184,	// xcood
	216,	// ycood
	0,	// frame
	0,	// cursorText
	0,	// mouseOn
	0,	// mouseOff
	ADVISOR_188,	// mouseClick
	0,	// mouseRel_x
	0,	// mouseRel_y
	320,	// mouseSize_x
	79,	// mouseSize_y
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

uint16 s12_logic[] = {
	ID_FOSTER,
	ID_JOEY,
	ID_ANITA,
	ID_ANITA_SPY,
	ID_LAMB,
	ID_LIFT_S7,
	ID_LIFT7_LIGHT,
	ID_FOREMAN,
	ID_TOP_BELT,
	ID_PIPES,
	ID_BOT_BELT,
	ID_COGS,
	ID_GEARS,
	ID_BELT1,
	ID_BELT2,
	ID_PIPE1,
	ID_PIPE2,
	ID_PIPE3,
	ID_PIPE4,
	ID_WELDER,
	ID_CABLE_7,
	0XFFFF,
	ID_MENU_LOGIC
};

uint16 topbelt_seq[] = {
	91*64,
	222,
	180,
	0,
	222,
	180,
	1,
	222,
	180,
	2,
	222,
	180,
	3,
	222,
	180,
	4,
	222,
	180,
	5,
	222,
	180,
	6,
	222,
	180,
	7,
	222,
	180,
	8,
	222,
	180,
	9,
	222,
	180,
	10,
	222,
	180,
	11,
	222,
	180,
	12,
	222,
	180,
	13,
	222,
	180,
	14,
	222,
	180,
	15,
	222,
	180,
	16,
	222,
	180,
	17,
	222,
	180,
	18,
	222,
	180,
	19,
	222,
	180,
	20,
	222,
	180,
	21,
	222,
	180,
	22,
	222,
	180,
	23,
	222,
	180,
	24,
	222,
	180,
	25,
	222,
	180,
	26,
	222,
	180,
	27,
	222,
	180,
	28,
	222,
	180,
	29,
	222,
	180,
	30,
	222,
	180,
	31,
	222,
	180,
	32,
	222,
	180,
	33,
	222,
	180,
	34,
	222,
	180,
	35,
	222,
	180,
	36,
	222,
	180,
	37,
	222,
	180,
	38,
	222,
	180,
	39,
	222,
	180,
	40,
	222,
	180,
	40,
	222,
	180,
	41,
	222,
	180,
	41,
	222,
	180,
	41,
	222,
	180,
	40,
	222,
	180,
	40,
	222,
	180,
	40,
	222,
	180,
	41,
	222,
	180,
	41,
	222,
	180,
	41,
	222,
	180,
	40,
	222,
	180,
	40,
	222,
	180,
	40,
	222,
	180,
	41,
	222,
	180,
	41,
	222,
	180,
	41,
	222,
	180,
	40,
	222,
	180,
	40,
	222,
	180,
	40,
	222,
	180,
	41,
	222,
	180,
	42,
	0
};

#endif
