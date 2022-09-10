/* The Clarkinou Sound System system timers interface header.
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

#ifndef __TIMER_DATA__
#define __TIMER_DATA__

#include "gba.h"

#define TIM0_DATA REG_BASE + 0x100
#define TIM1_DATA REG_BASE + 0x104
#define TIM2_DATA REG_BASE + 0x108
#define TIM3_DATA REG_BASE + 0x10C

#define TIM0_CR REG_BASE + 0x102
#define TIM1_CR REG_BASE + 0x106
#define TIM2_CR REG_BASE + 0x10A
#define TIM3_CR REG_BASE + 0x10E

#define TIM_FREQ_64   0x0001
#define TIM_FREQ_256  0x0002
#define TIM_FREQ_1024 0x0003
#define TIM_CASCADE   0x0004
#define TIM_TRIG_IRQ  0x0040
#define TIM_ENABLE    0x0080

#endif
