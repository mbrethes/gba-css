/* The Clarkinou Sound System module player source code.
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

#include "clarkmod.h"
#include "clarkmix.h"
#include "gba.h"

#define PLAY_SAMPLE(sa,pat,ba) playSample(sa.data_begin,sa.data_begin+sa.data_length,sa.loop_begin,sa.loop_begin+sa.loop_length,pat.volume,pat.panning,ba,pat.pitch)

/* mod player, using (and used by) the mixer. */

void mixMod() __attribute__ ((section (".iwram")));
void playMod(modData*) __attribute__ ((section (".iwram")));
void stopMod() __attribute__ ((section (".iwram")));

// Internal values
u32 patCounter=0;
u32 tempoCounter=0;

modData* curMod=NULL;

void mixMod() {
	u32 tempTempo;
	u8 i;

	if (curMod != NULL) {

		tempTempo = tempoCounter;
		tempoCounter += curMod->tempo;

		// if overflow, then we have to play a new note !
		if (tempTempo > tempoCounter) {
			// if past end of song ...
			if (patCounter > (curMod->patNum - 1)) {
				if (! curMod->repeat) {
					curMod=NULL;
					return;
				}
				else patCounter = 0;
			}

			// so, what to do now ?
			for (i = 0 ; i < curMod->chanNum ; i++ ) {
				// play a new sample ?
				if (curMod->pAr[patCounter].FX & FX_CHSAMPLE)
					PLAY_SAMPLE(curMod->sAr[curMod->pAr[patCounter].index],curMod->pAr[patCounter],i);
				else {
					// modify some stuff ?
					if (curMod->pAr[patCounter].FX & FX_CHVOL)
						setVolume(curMod->pAr[patCounter].volume, i);
					if (curMod->pAr[patCounter].FX & FX_CHPAN)
						setPanning(curMod->pAr[patCounter].panning, i);
					if (curMod->pAr[patCounter].FX & FX_CHPITCH)
						setPitch(curMod->pAr[patCounter].pitch, i);
				}			
				patCounter++;
			}
		}
	}
}

void playMod(modData *d) {
	patCounter = 0;
	tempoCounter = 0xFFFFFFFF;
	curMod = d;
}

void stopMod() {
	curMod=NULL;
}
