/*
 * timer.c
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */

#include "main.h"
#include "input_reading.h"
#include "output_display.h"
#include "timer.h"

static uint16_t		TIME_CYCLE			= 10;

static uint8_t		timer_1_sec_flag	= 0;
static uint8_t		timer_1_sec_counter = 0;

static uint8_t		timer_light_flag	= 0;   ///blink 2Hz in Modi Mode
static uint8_t		timer_7Seg_flag		= 0;   ///enable LED7Seg sequentially
static uint16_t		timer_light_counter = 0;
static uint16_t		timer_7Seg_counter  = 0;

///DEMO

uint8_t counter = 20;
uint8_t led_index = 0;
////
void Set1SecTime(uint16_t duration){
	timer_1_sec_counter = duration / TIME_CYCLE;
	timer_1_sec_flag = 0;
}

void SetBlinkingLightTime(uint16_t duration){
	timer_light_counter = duration / TIME_CYCLE;
	timer_light_flag = 0;
}

void Set7SegTime(uint16_t duration){
	timer_7Seg_counter = duration / TIME_CYCLE;
	timer_7Seg_flag = 0;
}


void RunTime(){
	if(timer_light_counter > 0){
		timer_light_counter--;
		if(timer_light_counter <= 0){
			timer_light_flag = 1;
		}
	}

	if(timer_7Seg_counter > 0){
		timer_light_counter--;
		if(timer_light_counter <= 0){
			timer_light_flag = 1;
		}
	}

	if(timer_1_sec_counter > 0){
		timer_1_sec_counter--;
		if(timer_1_sec_counter <= 0){
			timer_1_sec_flag = 1;
		}
	}
}

uint8_t Timer1SecFlag(){
	return timer_1_sec_flag;
}

uint8_t Timer7SegFlag(){
	return timer_7Seg_flag;
}

uint8_t TimerLightFlag(){
	return timer_light_flag;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	//DEMO
	counter--;
	if(counter <= 0){
		counter = 25;
		if(led_index > 3) led_index = 0;
		Update7Seg(led_index++);
	}
	//

	if(htim->Instance == TIM2){
		RunTime();
		button_reading();
	}
}
