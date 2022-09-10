/* The Clarkinou Sound System module player header.
 * Copyright (C) 2003 by Mathieu Brethes
 *
 * Contact : thieumsweb@free.fr
 * Website : http://thieumsweb.free.fr/
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 */

#ifndef __CLARK_MOD__
#define __CLARK_MOD__

/* Function definitions of a MOD file in ClarkMix. */

#include "gba.h"

typedef struct {
	u32 data_begin, data_length, loop_begin, loop_length;
} samplElem;

#define FX_NOP      0
#define FX_CHVOL    1
#define FX_CHPAN    2
#define FX_CHPITCH  4
#define FX_CHSAMPLE 8

typedef struct {
	u8 FX; u8 index;
	u8 volume; s8 panning;
	u16 pitch;
} patElem;

#define REPEAT_TRUE 0xFF
#define REPEAT_FALSE 0x0

typedef struct {
	u32 tempo;    // tempo --> FFFFFFF=1/1 speed, 1 = 1/FFFFFFFF speed.
	u8 repeat;	// repeat after end ?
	u8 chanNum;	// number of channels (4 max)
	u8 sampNum;	// number of samples in sample array (255max).
	u32 patNum;	// number of pattern elements (counts ALL).
	const samplElem *sAr; // array with references to modules.
	const patElem *pAr;       // array with what to actually play.
} modData;

// main functions.

void mixMod();
void playMod(modData*);
void stopMod();

#endif
