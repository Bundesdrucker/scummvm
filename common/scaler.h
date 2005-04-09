/* ScummVM - Scumm Interpreter
 * Copyright (C) 2002-2005 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 */

#ifndef COMMON_SCALER_H
#define COMMON_SCALER_H

#include "common/stdafx.h"
#include "common/scummsys.h"

extern void InitScalers(uint32 BitFormat);

typedef void ScalerProc(const uint8 *srcPtr, uint32 srcPitch,
							uint8 *dstPtr, uint32 dstPitch, int width, int height);

#define DECLARE_SCALER(x)	\
	extern void x(const uint8 *srcPtr, uint32 srcPitch, uint8 *dstPtr, \
					uint32 dstPitch, int width, int height)

DECLARE_SCALER(_2xSaI);
DECLARE_SCALER(Super2xSaI);
DECLARE_SCALER(SuperEagle);
DECLARE_SCALER(AdvMame2x);
DECLARE_SCALER(AdvMame3x);
DECLARE_SCALER(Normal1x);
DECLARE_SCALER(Normal2x);
DECLARE_SCALER(Normal3x);
DECLARE_SCALER(Normal1o5x);
DECLARE_SCALER(TV2x);
DECLARE_SCALER(DotMatrix);
DECLARE_SCALER(HQ2x);
DECLARE_SCALER(HQ3x);

FORCEINLINE int real2Aspect(int y) {
	return y + (y + 1) / 5;
}

FORCEINLINE int aspect2Real(int y) {
	return (y * 5 + 4) / 6;
}

extern void makeRectStretchable(int &x, int &y, int &w, int &h);

extern int stretch200To240(uint8 *buf, uint32 pitch, int width, int height, int srcX, int srcY, int origSrcY);


#endif
