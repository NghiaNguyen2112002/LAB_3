/*
 * output_display.c
 *
 *  Created on: Sep 21, 2022
 *      Author: DELL
 */

#include "main.h"
#include "output_display.h"

//PB0->PB6 led7Seg
//PB8->PB11 enable/
static uint32_t led7Seg[10] = { 0x003F0040, 0x00060079, 0x005B0024,
  								0x004F0030, 0x00660019, 0x006D0012,
  								0x007D0002, 0x00070078, 0x007F0000,
  								0x006F0010 };
static uint32_t led7SegEnable[4] 	= { 0x01000E00, 0x02000D00, 0x04000B00,
										0x08000700 };

static uint32_t lightCode[4]		= { 0xD8002400, 0xB4004800, 0x6C009000 };	//r, a, g

static uint32_t light_1_Code[3]		= { 0x18000400, 0x14000800, 0x0C001000 };  //r, a, g

static uint32_t light_2_Code[3]		= { 0xC0002000, 0xA0004000, 0x60008000 };  //r, a, g

static uint8_t led7SegBuffer[4]		= { 0, 0, 0, 0 };



void Enable7SEG(uint8_t index){
	GPIOB->BSRR = led7SegEnable[index];
}

void Display7SEG(uint8_t num){
	if(num >= 0 && num <= 9){
		GPIOB->BSRR = led7Seg[num];
	}
}

void DisplayLight(uint8_t code){
	GPIOA->BSRR = lightCode[code];
}

void DisplayLight1(uint8_t code){
	GPIOA->BSRR = light_1_Code[code];
}

void DisplayLight2(uint8_t code){
	GPIOA->BSRR = light_2_Code[code];
}

void LightOff(void){
	GPIOA->BSRR = 0xFC000000;
}

void UpdateLed7SegBuffer(uint8_t time1, uint8_t time2){
	if(time1 >= 1 && time1 <= 99){
		led7SegBuffer[0] = time1 / 10;
		led7SegBuffer[1] = time1 % 10;
	}

	if(time2 >= 1 && time2 <= 99){
		led7SegBuffer[2] = time2 / 10;
		led7SegBuffer[3] = time2 % 10;
	}
}

void Update7Seg(uint8_t indexLed7Seg){
	if(indexLed7Seg >= 0 && indexLed7Seg <= 3){
		Enable7SEG(indexLed7Seg);
		Display7SEG( led7SegBuffer[indexLed7Seg] );
	}
}
