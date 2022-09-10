#include <clarkmix.h>
#include <clarkmod.h>
#include <clarkfreqs.h>

#include "clarkdemo.h"
#include "clarkpic.h"
#include "clarkpal.h"
#include <gba.h>
#include <gfx.h>
#include <oam.h>
#include <dma.h>
#include "ascii.h"
#include "asciipal.h"

extern const s8 trump_data[];
extern const s32 trump_length;

const char* theString=
"                                       "
"BUT WHO IS THAT GUY ON THE SCREEN...   "
"         IS IT A BIRD...               "
"A PLANE... NO IT IS CLARKINOU !!!      "
"I FORGOT YOUR BIRTHDAY BECAUSE I WAS PROGRAMMING THIS MODPLAYER. "
"SO I GAVE IT YOUR NICKNAME IN HOMMAGE. "
"MY APOLOGIES !!!            "
"HAPPY BIRTHDAY MAN... EVEN IF IT IS THREE MONTHS LATE... "
"                                       "
"                                       ";

MULTIBOOT

u32 IntrTable[14];

#define putPixel(offX,offY,pixel,page) if (offX & 0xFE) reg16(page + offY * SCR_WIDTH + offX - 1) = (reg16(page + offY * SCR_WIDTH + offX - 1) & 0x00FF) | (pixel << 8); \
	else reg16(page + offY * SCR_WIDTH + offX) = (reg16(page + offY * SCR_WIDTH + offX) & 0xFF00) | pixel ;

s8 oAx[240];
s8 oAy[SCR_HEIGHT];

void initArrayY() {
	u8 i=0,j;
	s8 fact;
	for (j = 0 ; j < 6 ; j++) {
		oAy[i++] = -1;
		oAy[i++] = 0;
		oAy[i++] = -1;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 1;
		oAy[i++] = 0;
		oAy[i++] = 1;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 1;
		oAy[i++] = 0;
		oAy[i++] = 1;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = -1;
		oAy[i++] = 0;
		oAy[i++] = -1;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
		oAy[i++] = 0;
	}
}

void copyBuffer(u32 source, u32 destination) {
	reg32(DMA3_SAD) = source;
	reg32(DMA3_DAD) = destination;
	reg32(DMA3_SIZE) = 240*160/4;
	reg16(DMA3_CR) = DMA_ENABLE | DMA_32BIT;
}

void endEffect(u8 thevalue, u32 buffer) {
	u8 i;
	reg32(DMA3_SIZE) = 240 / 4;
	for (i = thevalue + 1; i < 160 ; i++) {
		reg32(DMA3_SAD) = buffer + thevalue * 240;
		reg32(DMA3_DAD) = buffer + i * 240;
		reg16(DMA3_CR) = DMA_ENABLE | DMA_32BIT;
	}
}

void shiftArrayY() {
	u8 i;
	s8 tmp = oAy[0];
	for (i = 0 ; i < 159 ; i++) {
		oAy[i] = oAy[i+1];
	}
	oAy[159] = tmp;
}

void incLoadPalette(const u16* pal, u16 nbCol) {
	u8 i;
	for (i = 0 ; i < nbCol ; i++) {
		if (reg16(GFX_PAL_BG + i*2) >> 10 < pal[i] >> 10) reg16(GFX_PAL_BG + i * 2) += 0x0400; 
		if (reg16(GFX_PAL_BG + i*2) << 5 >> 10 < pal[i] << 5 >> 10) reg16(GFX_PAL_BG + i * 2) += 0x0020;
		if (reg16(GFX_PAL_BG + i*2) << 10 >> 10 < pal[i] << 10 >> 10) reg16(GFX_PAL_BG + i*2) += 1;
	}
}

void incUnloadPalette(u16 nbCol) {
	u8 i;
	for (i = 0 ; i < nbCol ; i++) {
		if (reg16(GFX_PAL_BG + i*2) >> 10 > 0) reg16(GFX_PAL_BG + i * 2) -= 0x0400;
		if (reg16(GFX_PAL_BG + i*2) << 5 >> 10 > 0) reg16(GFX_PAL_BG + i * 2) -= 0x0020;
		if (reg16(GFX_PAL_BG + i*2) << 10 >> 10 > 0) reg16(GFX_PAL_BG + i*2) -= 1;
	}
}

void setupSprites() {
	u32 i;
	// first load ASCII data into sprite table...
	reg32(DMA3_SIZE) = ascii_nbtile * 64 / 2;
	reg32(DMA3_SAD) = (u32)ascii_data;
	// first sprite is space - so not use space.
	reg32(DMA3_DAD) = GFX_SPR + 257 * 64;
	reg16(DMA3_CR) = DMA_ENABLE ;

	// Okay, now load the sprite palette.
	for (i = 0 ; i < asciipal_nbcol ; i++)
		reg16(GFX_PAL_SPR + i *2) = asciipal_data[i];

	// now we need to setup OAM itself. We'll initialize all our sprites
	// out of screen.

	for (i = 0 ; i < 128*8 ; i+=8) reg16(OAM_RAM + i) = 160;

	// and last we can enable OAM...
	//reg16(REG_DISPCNT) |=  DCNT_SPR_1D | DCNT_OAM;
	reg16(REG_DISPCNT) |=  DCNT_OAM;
}

void printStuff(u8 startSprite, u8* data, u8 length, u8 x, u8 y) {
	u32 i;
	for (i = startSprite * 8 ; i < (startSprite + length) * 8 ; i+=8) {
		reg16(OAM_RAM + i) = OAM_256C | y;
		reg16(OAM_RAM + i + 2) = x;
		switch (data[(i - (startSprite * 8)) >> 3]) {
			case ' ':
			reg16(OAM_RAM + i + 4) = 512;
			break;
			case '.':
			reg16(OAM_RAM + i + 4) = 512 + 27*2;
			break;
			case '!':
			reg16(OAM_RAM + i + 4) = 512 + 28*2;
			break;
			default:
			reg16(OAM_RAM + i + 4) = 512 + (data[(i - (startSprite * 8)) >> 3] - 'A' + 1) * 2;
		}
		x += 8;
	}
}

extern const modData theMod;
char * strPtr;

void AgbMain() {
	s32 i,j, loop, jmax;

	strPtr = theString;
	// Initialize the sound system.

	InitSystem();

	// play a sound
	// playSample((u32)trump_data, (u32) trump_data + trump_length, (u32) trump_data, (u32) trump_data + trump_length, 255, 0, 0, E1);

	playMod(&theMod);

	// On charge

	// On passe en mode 4 / affiche la page 1...
	reg16(REG_DISPCNT) = DCNT_M4 | DCNT_BG2 | DCNT_P1;

	// et on teste ce super sprite-system.
	setupSprites();

	// on instale l'interruption VBL pour faire défiler le texte.
	IntrTable[0] = (u32)vBlankInt;
	reg16(REG_IE) |= IE_VBL;
	reg16(REG_DISPSTAT) |= DSTAT_VBLENABLE;

	//printStuff(0, theString++, 30, 0, 151);
	
	for (i = 0 ; i < SCR_HEIGHT ; i++)
		oAy[i]=0;

	initArrayY();

	curPage = GFX_P0;
	MAXDEPTH=1;
	recursiveHell(0, 0, 240, 160, 1,1,1,1,1);

	// show page 0 !
	reg16(REG_DISPCNT) &= ~ DCNT_P1;

	for (loop = 0 ; loop < 4 ; loop++) {
		i = 0;
		while (i++ < 32) {
			for (j = 0 ; j < 2 ; j++) {
				while(reg16(REG_VCOUNT) < 160) ;
				while(reg16(REG_VCOUNT) >= 160);
			}
			while(reg16(REG_VCOUNT) < 160) ;
			incLoadPalette(clarkpal_data, clarkpal_nbcol);
			while(reg16(REG_VCOUNT) >= 160);

			}
		i = 0;
		while (i++ < 32) {
			while(reg16(REG_VCOUNT) < 160) ;
			incUnloadPalette(clarkpal_nbcol);
			while(reg16(REG_VCOUNT) >= 160);
		}
	}

	i = 0;
	while (i++ < 32) {
		for (j = 0 ; j < 2 ; j++) {
			while(reg16(REG_VCOUNT) < 160) ;
			while(reg16(REG_VCOUNT) >= 160);
		}
		while(reg16(REG_VCOUNT) < 160) ;
		incLoadPalette(clarkpal_data, clarkpal_nbcol);
		while(reg16(REG_VCOUNT) >= 160);
	}

	curPage = GFX_P1;
	MAXDEPTH=2;
	recursiveHell(0, 0, 240, 160, 1,1,1,1,1);

	// show page 0 !
	reg16(REG_DISPCNT) |= DCNT_P1;
	
	i = 0;
	while (i++ < 200) {
		while(reg16(REG_VCOUNT) < 160) ;
		while(reg16(REG_VCOUNT) >= 160) ;
	}

	curPage = GFX_P0;
	MAXDEPTH=4;
	recursiveHell(0, 0, 240, 160, 1,1,1,1,1);

	// show page 0 !
	reg16(REG_DISPCNT) &= ~ DCNT_P1;

	i = 0;
	while (i++ < 180) {
		while(reg16(REG_VCOUNT) < 160) ;
		while(reg16(REG_VCOUNT) >= 160);
	}

	curPage = GFX_P1;
	MAXDEPTH=8;
	recursiveHell(0, 0, 240, 160, 1,1,1,1,1);

	// show page 1 !
	reg16(REG_DISPCNT) |=  DCNT_P1;

	i = 0;
	while (i++ < 170) {
		while(reg16(REG_VCOUNT) < 160) ;
		while(reg16(REG_VCOUNT) >= 160);
	}

	curPage = GFX_P0;

	i = 0;
	// value entered by HAND (tm)
	while (i++ < 185) {
		shiftArrayY();
		shiftClark();
		blitBlack(curPage);
		recursiveHell(0, 0, 240, 160, 1, 1, 1, 1, 1);
		// wait for vblank ?
		while(reg16(REG_VCOUNT) < 160) ;
		//reg16(GFX_PAL_BG) = ~ reg16(GFX_PAL_BG);
		if (curPage == GFX_P0) {
			curPage = GFX_P1;
			reg16(REG_DISPCNT) &= ~ DCNT_P1;
		} else {
			curPage = GFX_P0;
			reg16(REG_DISPCNT) |= DCNT_P1;
		}
	}

	copyBuffer((curPage == GFX_P0) ? GFX_P1 : GFX_P0, (curPage == GFX_P0) ? GFX_P0 : GFX_P1);

	curPage = GFX_P0;

	// we dont' put off the end - palette effect afterwards.
	for (i = 159 ; i > 0 ; i--) {
		endEffect(i, curPage);
		while(reg16(REG_VCOUNT) < 160) ;
		while(reg16(REG_VCOUNT) >= 160);
		while(reg16(REG_VCOUNT) < 160) ;
		while(reg16(REG_VCOUNT) >= 160);
		while(reg16(REG_VCOUNT) < 160) ;
		if (curPage == GFX_P0) {
			curPage = GFX_P1;
			reg16(REG_DISPCNT) &= ~ DCNT_P1;
		} else {
			curPage = GFX_P0;
			reg16(REG_DISPCNT) |= DCNT_P1;
		}
		while(reg16(REG_VCOUNT) >= 160);
	}

	while (i++ < 32) {
		while(reg16(REG_VCOUNT) < 160) ;
		incUnloadPalette(clarkpal_nbcol);
		while(reg16(REG_VCOUNT) >= 160);
	}
	
	reg16(REG_IE) &= ~ IE_VBL;

	printStuff(0, "END", 3, 107, 71);
	printStuff(3, "BY MATHIEU", 10, 79 ,79);

	while(1);
}
