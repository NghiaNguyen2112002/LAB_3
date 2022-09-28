/*
 * input_processing.c
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */
#include "main.h"
#include "input_reading.h"

#define NO_OF_BUTTONS					3

#define BUTTON_IS_RELEASED				GPIO_PIN_SET
#define BUTTON_IS_PRESSED				GPIO_PIN_RESET


static GPIO_PinState					buttonBuffer[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};

static GPIO_PinState					debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState					debounceButtonBuffer2[NO_OF_BUTTONS];


static uint16_t			buttonAddress[NO_OF_BUTTONS] = {SEL_BUTTON_Pin,
													MODI_BUTTON_Pin, SET_BUTTON_Pin};
static GPIO_TypeDef*	buttonPort[NO_OF_BUTTONS] = {SEL_BUTTON_GPIO_Port,
													MODI_BUTTON_GPIO_Port, SET_BUTTON_GPIO_Port};

void button_reading(void){
	for(uint8_t i = 0; i < NO_OF_BUTTONS; i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(buttonPort[i], buttonAddress[i]);

		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
			buttonBuffer[i] = debounceButtonBuffer1[i];
	}
}

unsigned char is_button_pressed(uint8_t index){
	if(index >= NO_OF_BUTTONS) return 0;

	return ( buttonBuffer[index] == BUTTON_IS_PRESSED );
}

