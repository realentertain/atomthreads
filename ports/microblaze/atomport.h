/*
 * Copyright (c) 2012, Kevin Pansky for Atomthreads Project. 
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. No personal names or organizations' names associated with the
 *    Atomthreads project may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE ATOMTHREADS PROJECT AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __ATOM_PORT_H
#define __ATOM_PORT_H

#include "mb_interface.h"

/* Required number of system ticks per second (normally 100 for 10ms tick) */
#define SYSTEM_TICKS_PER_SEC            100

/* Size of each stack entry / stack alignment size (8 bits on AVR) */
#define STACK_ALIGN_SIZE                sizeof(uint32_t)

/**
 * Architecture-specific types.
 */
#define uint8_t   unsigned char
#define uint16_t  unsigned short
#define uint32_t  unsigned long
#define uint64_t  unsigned long long
#define int8_t    char
#define int16_t   short
#define int32_t   long
#define int64_t   long long
#define POINTER   void *

/* Critical region protection */
#define CRITICAL_STORE      uint32_t __msr_reg
#define CRITICAL_START()    __msr_reg = mfmsr(); microblaze_disable_interrupts()
#define CRITICAL_END()      if (__msr_reg & 0x2) microblaze_enable_interrupts()


/* Uncomment to enable stack-checking */
#define ATOM_STACK_CHECKING


#endif /* __ATOM_PORT_H */
