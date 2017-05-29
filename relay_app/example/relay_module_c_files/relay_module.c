/*
 * @brief Relay module functions.
 *
 * @note
 * Created on: 31.05.2016.
 *     Author: Nemanja Djekic
 *
 * @param
 * This part of software represent group of functions which are
 * used only to control relay click module. It is written for module
 * with 2 relays, but it is possible to upgrade it to modules with
 * more than 2 relays.
 *
 */

/* Includes */

#include "chip.h"
#include "gpio_17xx_40xx.h"

#include "board.h"
#include <stdio.h>
#include <string.h>
#include "app_usbd_cfg.h"
#include "cdc_vcom.h"
#include "stopwatch.h"

#include "relay_module.h"

/**
 *  Private variables
 */
int Relay_1_flag = FALSE;
int Relay_2_flag = FALSE;


/**
 *  Private functions
 */

/* Turning relay_1 on */
int Turn_Relay_1_on(void)
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO, Port_0, Pin_0_3);
}

/* Turning relay_1 off */
int Turn_Relay_1_off(void)
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO, Port_0, Pin_0_3);
}

/* Turning relay_2 on */
int Turn_Relay_2_on(void)
{
	Chip_GPIO_SetPinOutHigh(LPC_GPIO, Port_0, Pin_0_2);
}

/* Turning relay_2 off */
int Turn_Relay_2_off(void)
{
	Chip_GPIO_SetPinOutLow(LPC_GPIO, Port_0, Pin_0_2);
}

/* Function for printing relay status on VCOM */
int Status_function(void)
{
	if(Relay_1_flag == 1 && Relay_2_flag == 0)
	{
		vcom_write("Relay_1 is on and Relay_2 is off!\n",34);
	}
	else if (Relay_1_flag == 1 && Relay_2_flag == 1)
	{
		vcom_write("Relay_1 is on and Relay_2 is on!\n",34);
	}
	else if(Relay_1_flag == 0 && Relay_2_flag == 0)
	{
		vcom_write("Relay_1 is off and Relay_2 is off!\n",36);
	}
	else if(Relay_1_flag == 0 && Relay_2_flag == 1)
	{
		vcom_write("Relay_1 is off and Relay_2 is on!\n",34);
	}

}

/**
 *  Public functions
 */

/* System protection from random inputs. */
extern int Random_Buttons_Protection(uint8_t array_value, uint32_t counter)
{

	// Button m
	if((array_value == 'm') && counter == 1)
	{
		vcom_write("Relay_1 is on!\n",15);
		Turn_Relay_1_on();
		Relay_1_flag = TRUE;
	}

	// Button n
	else if((array_value == 'n')  && counter == 1)
	{
		vcom_write("Relay_1 is off!\n",16);
		Turn_Relay_1_off();
		Relay_1_flag = FALSE;
	}

	// Button p
	else if((array_value == 'p')  && counter == 1)
	{
		vcom_write("Relay_2 is on!\n",15);
	    Turn_Relay_2_on();
		Relay_2_flag = TRUE;

	}

	// Button o
	else if((array_value == 'o')  && counter == 1)
	{
		vcom_write("Relay_2 is off!\n",16);
		Turn_Relay_2_off();
		Relay_2_flag = FALSE;
	}

	// ASCII code control
	else if(((array_value > Null && array_value < Enter) || (array_value > Enter && array_value < 'm') || array_value > 'p' )&& counter == 1)
	{
		Status_function();
	}
	else if(counter > 1)
	{
		Status_function();
	}
}

/* Welcome function */
extern int Welcome(void)
{
	vcom_write("RM: Press m/p to turn Relay_1/2 ON, or n/o to turn OFF!\n",57);
}

/* Setting pins as output */
extern int  Set_Relay_Pins_As_Output(void)  // Test diode Setuje pinove kao izlazne, U zagradi se unose vrijednosti (Vrsta pina, port, pin, true)
{
	/* Pin PIO0_3 is configured as GPIO pin during SystemInit */
	/* Set the PIO_3 as output */
	/* Pin PIOX_Y is configured as GPIO pin during SystemInit */
	/* Set the PIX_Y as output */
	//	Chip_GPIO_WriteDirBit(LPC_GPIO, 0, 3, true);
	Chip_GPIO_WriteDirBit(LPC_GPIO,Port_0,Pin_0_2,true);
	Chip_GPIO_WriteDirBit(LPC_GPIO,Port_0,Pin_0_3,true);
}






