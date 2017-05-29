/*
 * @brief Blinky example using sysTick
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include <stdio.h>

#include "chip.h" // Added by Djexon 25/5/2016 Test
#include "gpio_17xx_40xx.h"
#include "chip_lpc175x_6x.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

#define TICKRATE_HZ1 (10)	/* 10 ticks per second */

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */

/*
void SysTick_Handler(void)
{
	Board_LED_Toggle(0);
}
*/

static void Test_Diode_2(void)  // Test diode Setuje pinove kao izlazne, U zagradi se unose vrijednosti (Vrsta pina, port, pin, true)
{
	/* Pin PIO0_22 is configured as GPIO pin during SystemInit */
	/* Set the PIO_22 as output */
	Chip_GPIO_WriteDirBit(LPC_GPIO, 0, 3, true);
}

/**
 * @brief	main routine for systick example
 * @return	Function should not exit.
 */
int main(void)
{


	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
//	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);
    Test_Diode_2();

    // Force the counter to be placed into memory
    	volatile static  uint32_t i ;

    	while(1) {  // Za beskonacno vrtenje  u krug


    	for(int i = 0; i < 10000000 ; i++)
    					    {
    						Chip_GPIO_SetPinOutHigh(LPC_GPIO, 0, 3);  // Ova f-ja setuje pinove low ili high,
    					    }

    					    for(int i = 0; i < 10000000 ; i++)
    					    {
    						Chip_GPIO_SetPinOutLow(LPC_GPIO, 0, 3);
    					    }

    	} // Kraj beskonacne petlje xD

	/* LEDs toggle in interrupt handlers */
	while (1) {

		__WFI();
	}

	return 0;
}


