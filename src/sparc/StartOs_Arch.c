/* Copyright 2016, Gerardo Puga (UNLP)
 * Copyright 2014, Pablo Ridolfi (UTN-FRBA)
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

/** \brief FreeOSEK Os StartOs Architecture Dependence Implementation File
 **
 ** This file implements the StartOs Arch API
 **
 ** \file sparc/StartOs_Arch.c
 ** \arch sparc
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_Internal
 ** @{ */

/*==================[inclusions]=============================================*/


#include "Os_Internal.h"
#include "Sparc_Arch.h"


/*==================[macros and definitions]=================================*/


/*==================[internal data declaration]==============================*/


/*==================[internal functions declaration]=========================*/


/*==================[internal data definition]===============================*/


/*==================[external data definition]===============================*/


/*==================[internal functions definition]==========================*/


sparcReplaceTrapTable()
{
   /* Replace the current trap base register value with the address of our new
    * system trap table. Disable trap while you are at it. Notice that calling
    * functions with traps disabled is usually a very bad idea, but in this case
    * both functions are leaf functions and therefore they can't cause any window
    * overflow or underflow traps. */

   sparcSystemServiceEnableTraps();

   __asm__ ("sethi %%hi(sparc_system_trap_table), %%l1\n\t"
            "or    %%l1, %%lo(sparc_system_trap_table), %%l1\n\t"
            "mov r %%l1, %%tbr\n\t"
            "nop\n\t"
            "nop\n\t"
            "nop\n\t"
            : /* no output registers */
            : /* no input registers */
            : "%l1" /* clobbered registers */
           );

   sparcSystemServiceDisableTraps();
}


/*==================[external functions definition]==========================*/


void StartOs_Arch(void)
{
   /* Perform any kind of CPU dependent initialization */
   StartOs_Arch_Cpu();

   /* Setup application interrupts. This routine is automatically generated by the OSEK
    * OS generator. */
   sparcSetupUserISRs();

   /* Setup the timer interrupt */
   sparcSetupSystemTimer();

   /* Replace the system trap table with our own */
   sparcReplaceTrapTable();
}


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

