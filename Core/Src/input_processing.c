/*
 * input_processing.c
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */


#include "main.h"
#include "input_reading.h"
#include "output_display.h"
#include "input_processing.h"
#include "timer.h"


#define 	NO_OF_LIGHTS	3
#define		NO_OF_MODES		4

#define		SET 			0
#define		MODI			1
#define		SEL				2


#define 	RED				0
#define		AMBER			1
#define		GREEN			2

static uint8_t	lightBufferModi[NO_OF_LIGHTS] 	= {1, 1, 1};
static uint8_t	lightBufferRun[NO_OF_LIGHTS]	= {1, 1, 1};

//static uint8_t 	indexLed7Seg 		= 0;

//1: SEL   2: MODI    3:SET
//mode 1 2 3 4
static uint8_t	mode;
static uint8_t	light1, light2;
static uint8_t	light1Time, light2Time;

static uint8_t	lightBlinkingOnFlag;
void INIT_INPUT_PROCESSING(void){
	lightBlinkingOnFlag = 1;

	mode = 1;
	light1 = RED;
	light2 = GREEN;
	light1Time = lightBufferRun[light1];
	light2Time = lightBufferRun[light2];
}

void CopyModiToRun(void){
	for(int i = 0; i < NO_OF_LIGHTS; i++){
		lightBufferRun[i] = lightBufferModi[i];
	}
}

void CopyRunToModi(void){
	for(int i = 0; i < NO_OF_LIGHTS; i++){
		lightBufferModi[i] = lightBufferRun[i];
	}
}

void IncreaseTime(uint8_t light){
	//0 red, 1 amber, 2 green
	HAL_Delay(50);
	lightBufferModi[light]++;
	if(lightBufferModi[light] > 99) lightBufferModi[light] = 1;
}


void UpdateMode(void){
	HAL_Delay(50);
	mode++;
	if(mode > NO_OF_MODES) mode = 1;
}

void UpdateLightPara(void){
	light1 = RED;
	light2 = GREEN;
	light1Time = lightBufferRun[light1];
	light2Time = lightBufferRun[light2];
}

void TrafficLightConvention(void){
	if(light1Time <= 0){
		if(light1 == RED){
			light1 = GREEN;
			light1Time = lightBufferRun[GREEN];
		}
		else if(light1 == GREEN){
			light1 = AMBER;
			light1Time = lightBufferRun[AMBER];
		}
		else if(light1 == AMBER){
			light1 = RED;
			light1Time = lightBufferRun[RED];
		}
	}

	if(light2Time <= 0){
		if(light2 == RED){
			light2 = GREEN;
			light2Time = lightBufferRun[GREEN];
		}
		else if(light2 == GREEN){
			light2 = AMBER;
			light2Time = lightBufferRun[AMBER];
		}
		else if(light2 == AMBER){
			light2 = RED;
			light2Time = lightBufferRun[RED];
		}
	}
}

void CountdownTime(void){
	if( (mode == 1) && (Timer1SecFlag() == 1) ){
		light1Time--; light2Time--;
		Set1SecTime(1000);
	}
}

void BlinkLed(uint8_t light){
	if(TimerLightFlag() == 1){
		if(lightBlinkingOnFlag == 1){
			DisplayLight(light);
			lightBlinkingOnFlag = 0;
		}
		else {
			LightOff();
			lightBlinkingOnFlag = 1;
		}

		SetBlinkingLightTime(500);
	}
}

void fsm_for_input_processing(void){
	if(is_button_pressed(SET)) {
		CopyRunToModi();
		UpdateMode();
		UpdateLightPara();
	}

	switch(mode){
	case 1:

		CountdownTime();
		UpdateLed7SegBuffer(light1Time, light2Time);

		TrafficLightConvention();
		DisplayLight1(light1);
		DisplayLight2(light2);

		break;
	case 2:
		UpdateLed7SegBuffer(lightBufferModi[RED], 22);
		BlinkLed(RED);

		if(is_button_pressed(MODI)) IncreaseTime(RED);
		if(is_button_pressed(SEL)) CopyModiToRun();
		break;
	case 3:
		UpdateLed7SegBuffer(lightBufferModi[AMBER], 33);
		BlinkLed(AMBER);

		if(is_button_pressed(MODI)) IncreaseTime(AMBER);
		if(is_button_pressed(SEL)) CopyModiToRun();
		break;
	case 4:
		UpdateLed7SegBuffer(lightBufferModi[GREEN], 44);
		BlinkLed(GREEN);

		if(is_button_pressed(MODI)) IncreaseTime(GREEN);
		if(is_button_pressed(SEL)) CopyModiToRun();
		break;
	default:
		break;
	}

//	if(Timer7SegFlag()) {
//		if(indexLed7Seg > 3) indexLed7Seg = 0;
//		Update7Seg( indexLed7Seg++ );
//		Set7SegTime(500);
//	}
}
