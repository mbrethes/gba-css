#include "clarkdemo.h"
#include "clarkpic.h"
#include <gfx.h>
#include <dma.h>

void blitBlack(u32) __attribute__ ((section (".iwram")));
void recursiveHell(u8, u8, u8, u8, u8, u8, u8, u8, u8) __attribute__ ((section (".iwram")));
void shiftClark() __attribute__ ((section (".iwram")));
void vBlankInt()  __attribute__ ((section (".iwram")));

extern printStuff(u8, u8*, u8, u8, u8);
extern char* strPtr;

u32 vblcptr = 0;

void vBlankInt(void) {
	vblcptr++;

	if (vblcptr >= 8) {
		printStuff(0, strPtr++, 30, 0, 151);
		vblcptr = 0;
	}
}

void blitBlack(u32 page) {
	u32 i;
	for (i = 0 ; i < 240*160 ; i+=4) {
		reg32(page + i) = 0;
	}
}

u32 curPage=GFX_P0;
u32 MAXDEPTH=4;

// recursive hell - to be called with jumps = 1.
void recursiveHell(u8 offX, u8 offY, u8 sizeX, u8 sizeY, u8 t1, u8 t2, u8 t3, u8 t4, u8 jumps) {
	// terminal condition ?
	if (jumps < MAXDEPTH) {
		// no, call me again !
		// divide screen in 4, and hell inside.
		if (t1) recursiveHell(offX, offY, sizeX >> 1, sizeY >> 1, t1, t2, t3, 0, jumps << 1);
		if (t2) recursiveHell(offX + (sizeX >> 1), offY, sizeX >> 1, sizeY >> 1, t1, t2, 0, t4, jumps << 1);
		if (t3) recursiveHell(offX, offY + (sizeY >> 1), sizeX >> 1, sizeY >> 1, t1, 0, t3, t4, jumps << 1);
		if (t4) recursiveHell(offX + (sizeX >> 1), offY + (sizeY >> 1), sizeX >> 1, sizeY >> 1, 0, t2, t3, t4, jumps << 1);
	}
	// and we draw our picture.
	u32 i,j,tmp, offset, offsetY, scrOffY;
	
	for (j = offY ; j < offY + sizeY ; j++) {
		offsetY = (j - offY) * clarkpic_width;
		scrOffY = j*SCR_WIDTH;
		for (i = offX ; i < offX+sizeX ; i+=4) {
			offset = (i - offX + offsetY) * jumps;
			tmp = clarkpic_data[offset];
			tmp |= clarkpic_data[offset + jumps] << 8;
			tmp |= clarkpic_data[offset + (jumps << 1)] << 16;
			tmp |= clarkpic_data[offset + (jumps << 1) + jumps] << 24;
			if (tmp != 0) reg32(curPage + i + scrOffY) = tmp;
		}
	}
}

/* shifts the clarkent picture using the arrayY. */
void shiftClark() {
	u8 i;

	for (i = 0 ; i < SCR_HEIGHT ; i++) {
		// words to copy
		reg32(DMA3_SIZE) = (SCR_WIDTH - oAy[i]) >> 1;
		if (oAy[i] > 0) {
			reg32(DMA3_SAD) = (u32)clarkpic_data + (i + 1) * SCR_WIDTH - oAy[i];
			reg32(DMA3_DAD) = (u32)clarkpic_data + (i + 1) * SCR_WIDTH;
			reg16(DMA3_CR) = DMA_ENABLE | DMA_DM_DEC_WB | DMA_SM_DEC_WB;
		} else if (oAy[i] < 0) {
			reg32(DMA3_SAD) = (u32)clarkpic_data + i * SCR_WIDTH;
			reg32(DMA3_DAD) = (u32)clarkpic_data + i * SCR_WIDTH + oAy[i];
			reg16(DMA3_CR) = DMA_ENABLE ;
		}
	}
}
