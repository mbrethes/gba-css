/* The Clarkinou Sound System sound access definition header.
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

#ifndef __GBA_DSOUND__
#define __GBA_DSOUND__

#include "gba.h"

#define REG_SOUNDCNT_L REG_BASE + 0x080
#define REG_SOUNDCNT_H REG_BASE + 0x082
#define REG_SOUNDCNT_X REG_BASE + 0x084

#define ENABLE_SOUND 0x0080

#define SND_VOL_25   0x0001
#define SND_VOL_50   0x0002
#define SND_VOL_100  0x0003

#define DSA_VOL_100 0x0004
#define DSB_VOL_100 0x0008
#define DSA_RIGHT   0x0100
#define DSA_LEFT    0x0200
#define DSA_BOTH    0x0300
#define DSA_TIMER_0 0x0000
#define DSA_TIMER_1 0x0400
#define DSA_RESET   0x0800
#define DSB_RIGHT   0x1000
#define DSB_LEFT    0x2000
#define DSB_BOTH    0x3000
#define DSB_TIMER_0 0x0000
#define DSB_TIMER_1 0x4000
#define DSB_RESET   0x8000


#endif
