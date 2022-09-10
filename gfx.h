/* The Clarkinou Sound System video memory interface header.
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

#ifndef __GBA_GFX__
#define __GBA_GFX__

#include "gba.h"

#define SCR_WIDTH 240
#define SCR_HEIGHT 160

#define GFX_P0  0x06000000
#define GFX_P1  0x0600A000
#define GFX_SPR 0x06010000
#define GFX_PAL_BG  0x05000000
#define GFX_PAL_SPR 0x05000200

#define REG_VCOUNT REG_BASE + 0x006

#define REG_DISPSTAT REG_BASE + 0x004
#define DSTAT_VBL 0x1
#define DSTAT_HBL 0x2
#define DSTAT_VBLENABLE 0x8
#define DSTAT_HBLENABLE 0x10

#define REG_DISPCNT REG_BASE
#define DCNT_M0  0
#define DCNT_M1  0x1
#define DCNT_M2  0x2
#define DCNT_M3  0x3
#define DCNT_M4  0x4
#define DCNT_M5  0x5
#define DCNT_P1     0x10
#define DCNT_SPR_1D 0x40
#define DCNT_FBLANK 0x80
#define DCNT_BG0    0x100
#define DCNT_BG1    0x200
#define DCNT_BG2    0x400
#define DCNT_BG3    0x800
#define DCNT_OAM   0x1000
#define DCNT_W0    0x2000
#define DCNT_W1    0x4000
#define DCNT_SWIN  0x8000

#endif
