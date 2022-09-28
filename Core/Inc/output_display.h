/*
 * output_display.h
 *
 *  Created on: Sep 21, 2022
 *      Author: DELL
 */

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

#define		RED			0
#define		AMBER		1
#define		GREEN		2
#define		LIGHT_OFF	4

void Enable7SEG(uint8_t index);

void Display7SEG(uint8_t num);

void DisplayLight(uint8_t code);

void DisplayLight1(uint8_t code);

void DisplayLight2(uint8_t code);

void LightOff(void);

void UpdateLed7SegBuffer(uint8_t time1, uint8_t time2);

void Update7Seg(uint8_t index);


#endif
