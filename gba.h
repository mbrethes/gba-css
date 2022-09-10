/* The Clarkinou Sound System GBA interface header file.
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

#ifndef __GBA_MAIN__
#define __GBA_MAIN__

#define NULL 0

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed char s8;
typedef signed short s16;
typedef signed long  s32;

#define MULTIBOOT int __gba_multiboot;

#define REG_BASE       0x04000000


#define REG_IE  REG_BASE + 0x200
#define REG_IF  REG_BASE + 0x202
#define REG_IME REG_BASE + 0x208

#define ENABLE_INTS 0x1
#define IE_VBL   0x0001
#define IE_HBL   0x0002
#define IE_YTRIG 0x0004
#define IE_TIM0  0x0008
#define IE_TIM1  0x0010
#define IE_TIM2  0x0020
#define IE_TIM3  0x0040
#define IE_COMM  0x0080
#define IE_DMA0  0x0100
#define IE_DMA1  0x0200
#define IE_DMA2  0x0400
#define IE_DMA3  0x0800
#define IE_KEYP  0x1000
#define IE_CART  0x2000

#define reg32(addr) *(volatile u32 *)(addr)
#define reg16(addr) *(volatile u16 *)(addr)
#define reg8(addr)  *(volatile u8  *)(addr)

#endif

