/* The Clarkinou Sound System DMA access definitions header.
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

#ifndef __DMA_H__
#define __DMA_H__

#include "gba.h"

#define FIFO_A   REG_BASE + 0x0A0
#define FIFO_B   REG_BASE + 0x0A4

#define DMA0_SAD REG_BASE + 0x0B0
#define DMA1_SAD REG_BASE + 0x0BC
#define DMA2_SAD REG_BASE + 0x0C8
#define DMA3_SAD REG_BASE + 0x0D4
#define DMA0_DAD REG_BASE + 0x0B4
#define DMA1_DAD REG_BASE + 0x0C0
#define DMA2_DAD REG_BASE + 0x0CC
#define DMA3_DAD REG_BASE + 0x0D8

#define DMA0_SIZE REG_BASE + 0x0B8
#define DMA1_SIZE REG_BASE + 0x0C4
#define DMA2_SIZE REG_BASE + 0x0D0
#define DMA3_SIZE REG_BASE + 0x0DC

#define DMA0_CR REG_BASE + 0x0BA
#define DMA1_CR REG_BASE + 0x0C6
#define DMA2_CR REG_BASE + 0x0D2
#define DMA3_CR REG_BASE + 0x0DE

#define DMA_ENABLE     0x8000
#define DMA_DM_DEC_WB  0x0020
#define DMA_DM_FIXED   0x0040
#define DMA_DM_INC_RST 0x0060
#define DMA_SM_DEC_WB  0x0080
#define DMA_SM_FIXED   0x0100
#define DMA_REPEAT     0x0200
#define DMA_32BIT      0x0400
#define DMA_STAM_VBL   0x1000
#define DMA_STAM_HBL   0x2000
#define DMA_STAM_FIFO  0x3000
#define DMA_TRIG_IRQ   0x4000

#endif
  
