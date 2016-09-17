/* Copyright 2016, Gerardo Puga (UNLP)
 *
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _OS_INTERNAL_ARCH_CPU_H_
#define _OS_INTERNAL_ARCH_CPU_H_

/** \brief FreeOSEK Internal Architecture Cpu Dependent Header File
 **
 ** \file sparc/leon3/Os_Internal_Arch_Cpu.h
 ** \arch sparc/leon3
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_Internal
 ** @{ */

/*==================[cpu macros]=============================================*/


/*==================[inclusions]=============================================*/


/*==================[macros]=================================================*/


/*==================[typedef]================================================*/


typedef uint32 sparcIrqNumber;

typedef void (*sparcIrqHandlerRef)();


/*==================[external data declaration]==============================*/


uint32 detected_sparc_register_windows;


/*==================[external functions declaration]=========================*/


void sparcRegisterISR1Handler(sparcIrqHandlerRef handler, sparcIrqNumber irq);

void sparcRegisterISR2Handler(sparcIrqHandlerRef handler, sparcIrqNumber irq);

void sparcClearInterrupt(sparcIrqNumber irq);

void sparcEnableAllInterrupts(void);

void sparcDisableAllInterrupts(void);

void sparcEnableISR2Interrupts(void);

void sparcDisableISR2Interrupts(void);

void StartOs_Arch_Cpu(void);

void sparcOsekPause();

void sparcCheckPendingTimerInterrupts();


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef _OS_INTERNAL_ARCH_CPU_H_ */

