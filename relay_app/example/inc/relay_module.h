/*
 * relay_module.h
 *
 * @brief Relay module functions.
 *
 * @note
 * Created on: 31.05.2016.
 *      Author: Nemanja Djekic
 *
 * @param
 * This part of software represent group of functions which are
 * used only to control relay click module. It is written for module
 * with 2 relays, but it is possible to upgrade it to modules with
 * more than 2 relays.
 *
 */


#ifndef INC_RELAY_MODULE_H_
#define INC_RELAY_MODULE_H_

#include "app_usbd_cfg.h"
#include "cdc_vcom.h"

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * Relay module control data instance.
 */

/**
 * Defines
 */

//Ports and pins
#define Port_0    0
#define Pin_0_2   2
#define Pin_0_3   3


// ASCII code characters
#define  Null     0
//Carriage return
#define  Enter    13


/**
 * Private variables
 */
int Relay_1_flag;
int Relay_2_flag;

/* Private functions */

/**
 * @brief	Relay module turn on routine.
 * @param   P0.3 : Setting pin as High.
 */
int Turn_Relay_1_on(void);

/**
 * @brief	Relay module turn on routine.
 * @param   P0.3 : Setting pin as Low.
 */
int Turn_Relay_1_off(void);

/**
 * @brief	Relay module turn on routine.
 * @param   P0.3 : Setting pin as High
 */
int Turn_Relay_2_on(void);

/**
 * @brief	Relay module turn on routine.
 * @param   P0.3 : Setting pin as Low.
 */
int Turn_Relay_2_off(void);

/**
 * @brief Relay module status routine.
 * @param Relay_1_flag : Set 0 value when Relay_1 is off and 1 when Relay_1 is on.
 * @param Relay_2_flag : Set 0 value when Relay_2 is off and 1 when Relay_2 is on.
 */
int Status_function(void);



/* Public functions */

/**
 * @brief	Start programm routine.
 */
extern int Welcome(void);

/**
 * @brief	Pin configuration relay routine.
 * @param   P0.3  : Setting pin as output.
 * @param   PX.Y  : Setting pin as output.
 */
extern int Set_Relay_Pins_As_Output(void);


/**
 * @brief	Relay module input protection routine.
 * @param   array_value : First member buffer value.
 * @param   counter     : Pointer to buffer where read data should be copied.
 */
extern int Random_Buttons_Protection(uint8_t array_value, uint32_t counter);



#ifdef __cplusplus
}
#endif

#endif /* INC_RELAY_MODULE_H_ */
