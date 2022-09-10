/* The Clarkinou Sound System main mixer source code.
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

/*
	The Clarkinou Sound System, version 0.7

	03/10/06 :
		Lame modplaying implemented. No module conversion tool.
	03/10/04 :
		Frequency modulation (pitch) added, working on a 8.8
		fixed-point value.
		Maximal sample size is now 1 megabyte.
		Added a tool to generate a frequency table.
		First non-working modplaying function.
	03/10/02 :
		Several samples can now be mixed together. Some optimizing
		work to keep the stuff almost as fast as the original
		mono-sample version.
		buffer swap system was tuned.
	03/10/01 : 
		Loop function corrected.
	03/09/27 :
		Loop function added, permits to play samples with... A loop.
	03/07/24 :
		HUGE improvement of sound quality by increasing buffer size.
		DMA reset bug corrected, the sound now works on hardware.
		Volume management added (0 -> 255)
		Panning management added (-128 -> 127)
	03/07/23 :
		double-buffer system implemented, to be able to play any
		sample in stereo.
	03/07/22 : 
		First sound played !
*/

#include "gba.h"
#include "dma.h"
#include "dsound.h"
#include "timer.h"

#ifdef __MOD_PLAYER__
#include "clarkmod.h"
#endif

#define BUFFER_SIZE 640   // 1/25 sec buffer.
#define PLAYER_FREQ 0xFBFF // 16khz play back freq
#define SAMPLES_MIX  4

// External data used
extern u32 IntrTable[14];

s8 fifoAbuf0[BUFFER_SIZE];
s8 fifoAbuf1[BUFFER_SIZE];
s8 fifoBbuf0[BUFFER_SIZE];
s8 fifoBbuf1[BUFFER_SIZE];

s8* curBufA;
s8* curBufB;
s8* mixBufA;
s8* mixBufB;

// memory structure for a given sample.
struct sample {
    u32 data_begin;
    u32 data_end;
    u32 loop_begin;
    u32 loop_end;
    u8 volume_a; // internal use
    u8 volume_b; // internal use
    u8 volume;
    s8 panning;
    u8 in_loop;
    u16 pitch;   // used for FP 8.8 calculations. 0x100 is 1.
    u32 data_offset; // used for fixed-point 24.8 calculations.
};

struct sample toMix[SAMPLES_MIX];

u16 bufferSwitch;

// any easier way to do this ?
void InterruptProcess(void) __attribute__ ((section (".iwram")));
void mixBuffers(void) __attribute__ ((section (".iwram")));
void switchBuffers(void) __attribute__ ((section (".iwram")));
void playSample(u32, u32, u32, u32, u8, s8, u8, u16) __attribute__ ((section (".iwram")));
void setVolume(u8, u8) __attribute__ ((section (".iwram")));
void setPanning(s8, u8) __attribute__ ((section (".iwram")));
void setPitch(u16, u8) __attribute__ ((section (".iwram")));
void stopSample(u8) __attribute__ ((section (".iwram")));

//
void switchBuffers(void) {
    if (bufferSwitch == 0) {
        curBufA = fifoAbuf1;
        curBufB = fifoBbuf1;
        mixBufA = fifoAbuf0;
        mixBufB = fifoBbuf0;
        bufferSwitch = 1;
    } else {
        curBufA = fifoAbuf0;
        curBufB = fifoBbuf0;
        mixBufA = fifoAbuf1;
        mixBufB = fifoBbuf1;
        bufferSwitch = 0;
    }
}

void mixBuffers(void) {
	u16 i;
	u8 sampMixed;
	u8  curvolumea, curvolumeb, curinloop;
	u32 curdatabegin, curdataoffset;
	u32 currentptr;
	u32 curdataend, curloopend;
	u16 curpitch;

#ifdef __MOD_PLAYER__
	// mix the module-in-play.
	mixMod();
#endif
    
	// First initialize buffer to 0 - 32-bit operation is faster.
	for (i = 0 ; i < BUFFER_SIZE ; i+=4) {
		*(u32*)(mixBufA + i) = 0;
		*(u32*)(mixBufB + i) = 0;
	}

	for (sampMixed = 0 ; sampMixed < SAMPLES_MIX ; sampMixed ++) {
		// save values in local variables - seems to be faster
		curdatabegin = toMix[sampMixed].data_begin;
		curvolumea = toMix[sampMixed].volume_a;
		curvolumeb = toMix[sampMixed].volume_b;
		curdataend = toMix[sampMixed].data_end;
		curloopend = toMix[sampMixed].loop_end;
		curinloop = toMix[sampMixed].in_loop;
		curdataoffset = toMix[sampMixed].data_offset;
		curpitch = toMix[sampMixed].pitch;

		// FIFO A & B mixing...
		for (i = 0 ; i < BUFFER_SIZE ; i++) {
			currentptr = (curdatabegin + (curdataoffset >> 8));
			if ((currentptr >= curloopend) && curinloop) curdataoffset = toMix[sampMixed].loop_begin - curdatabegin;
			if (currentptr >= curdataend) break ;
			*(mixBufA + i) += (*(s8 *)currentptr * curvolumea) >> 8;
			*(mixBufB + i) += (*(s8 *)currentptr * curvolumeb) >> 8;
			curdataoffset += curpitch;			
		}

		// update the mix pointer.
		toMix[sampMixed].data_offset = curdataoffset;
	}

}

void InterruptProcess(void) {	
 	reg16(DMA1_CR) &= ~DMA_ENABLE;
	reg16(DMA2_CR) &= ~DMA_ENABLE;

	switchBuffers();
	reg32(DMA1_SAD) = (u32)curBufA;
	reg32(DMA2_SAD) = (u32)curBufB;
 
	reg16(DMA1_CR) = DMA_ENABLE | DMA_STAM_FIFO | DMA_32BIT | DMA_REPEAT ;
	reg16(DMA2_CR) = DMA_ENABLE | DMA_STAM_FIFO | DMA_32BIT | DMA_REPEAT ;
	mixBuffers();
        reg16(REG_IF) |= reg16(REG_IF);
}

void playSample(u32 data_begin, u32 data_end, u32 loop_begin, u32 loop_end, u8 volume, s8 panning, u8 bank, u16 pitch) {
    toMix[bank].data_begin = data_begin;
    toMix[bank].data_end = data_end;
    toMix[bank].volume_a = ((128 - panning) * volume) >> 8;
    toMix[bank].volume_b = ((128 + panning) * volume) >> 8;
    toMix[bank].volume = volume;
    toMix[bank].panning = panning;
    toMix[bank].loop_begin = loop_begin;
    toMix[bank].loop_end = loop_end;
    toMix[bank].in_loop = 1;
    toMix[bank].data_offset = 0;
    toMix[bank].pitch = pitch;
}

void stopSample(u8 bank) {
	toMix[bank].in_loop = 0;
}

void setVolume(u8 volume, u8 bank) {
	toMix[bank].volume_a = ((128 - toMix[bank].panning) * volume) >> 8 ;
	toMix[bank].volume_b = ((128 + toMix[bank].panning) * volume) >> 8;
	toMix[bank].volume = volume;
}

void setPanning(s8 panning, u8 bank) {
	toMix[bank].volume_a = ((128 - panning) * toMix[bank].volume) >> 8 ;
	toMix[bank].volume_b = ((128 + panning) * toMix[bank].volume) >> 8;
	toMix[bank].panning = panning;
}

void setPitch(u16 pitch, u8 bank) {
	toMix[bank].pitch = pitch;
}

void InitSystem(void) {
	u16 i;
	
	for (i = 0 ; i < BUFFER_SIZE ; i = i + 4) {
		(u32)fifoAbuf0[i] = 0;
		(u32)fifoAbuf1[i] = 0;
		(u32)fifoBbuf0[i] = 0;
		(u32)fifoBbuf1[i] = 0;
	}

	IntrTable[4] = (u32)InterruptProcess;

   // turn on the sound chip
   reg16(REG_SOUNDCNT_X) = ENABLE_SOUND;

   // make sure sound channels 1-4 are turned off
   reg16(REG_SOUNDCNT_L) = 0;

   reg16(TIM0_CR) = 0;
   reg16(DMA1_CR) = 0;
   reg16(DMA2_CR) = 0;
   
   reg16(TIM0_DATA) = PLAYER_FREQ;

   curBufA = fifoAbuf0;
   curBufB = fifoBbuf0;

   bufferSwitch = 0;
   reg32(DMA1_SAD) = (u32)curBufA;
   reg32(DMA1_DAD) = (u32)FIFO_A;
   reg32(DMA2_SAD) = (u32)curBufB;
   reg32(DMA2_DAD) = (u32)FIFO_B;

   // set the direct sound output control register
   reg16(REG_SOUNDCNT_H) = DSA_LEFT | DSA_TIMER_0 | DSA_RESET | DSB_RIGHT |DSB_TIMER_0 | DSB_RESET ;

   reg16(DMA1_CR) = DMA_ENABLE | DMA_STAM_FIFO | DMA_32BIT | DMA_REPEAT ;
   reg16(DMA2_CR) = DMA_ENABLE | DMA_STAM_FIFO | DMA_32BIT | DMA_REPEAT ;
  
   reg16(TIM0_CR) = TIM_ENABLE;
   
   reg16(TIM1_DATA) = 0xFFFF - (BUFFER_SIZE);
   reg16(TIM1_CR) = TIM_ENABLE | TIM_TRIG_IRQ | TIM_CASCADE;
  
   reg16(REG_IE) = IE_TIM1;
  
   reg16(REG_IME) = ENABLE_INTS;
} 

