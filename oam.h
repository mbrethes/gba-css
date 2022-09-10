/* The Clarkinou Sound System sprite memory (OAM) interface header.
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

#ifndef __OAM_HEADER__
#define __OAM_HEADER__

#define OAM_RAM 0x07000000

// attribute 0 values
#define OAM_ROTSCALE 0x0100
#define OAM_DSIZE    0x0200
#define OAM_SEMTRANS 0x0400
#define OAM_OBJWIN   0x0800
#define OAM_MOSAIC   0x1000
#define OAM_256C     0x2000
#define OAM_HORIZ    0x4000
#define OAM_VERT     0x8000

// attribute 1
#define OAM_HFLIP    0x1000
#define OAM_VFLIP    0x2000
#define OAM_16x16    0x4000
#define OAM_32x32    0x8000
#define OAM_64x64    0xC000
#define OAM_8x32     0x4000
#define OAM_16x32    0x8000
#define OAM_32x64    0xC000
#define OAM_32x8     0x4000
#define OAM_32x16    0x8000
#define OAM_64x32    0xC000

// attribute 3
#define OAM_PRIO1    0x0400
#define OAM_PRIO2    0x0800
#define OAM_PRIO3    0x0C00
#define OAM_PAL(n)   n<<12

#endif
