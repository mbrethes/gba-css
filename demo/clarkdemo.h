#ifndef __CLARK_DEMO__
#define __CLARK_DEMO__
#include <gba.h>

void blitBlack(u32);
void recursiveHell(u8, u8, u8, u8, u8, u8, u8, u8, u8);
void shiftClark();
void vBlankInt();

extern u32 MAXDEPTH;
extern u32 curPage;
extern s8 oAy[];

#endif
