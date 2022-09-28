/*
 * timer.h
 *
 *  Created on: Sep 28, 2022
 *      Author: DELL
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

void Set1SecTime(uint16_t duration);

void SetBlinkingLightTime(uint16_t duration);

void Set7SegTime(uint16_t duration);


uint8_t Timer1SecFlag();

uint8_t Timer7SegFlag();

uint8_t TimerLightFlag();

#endif /* INC_TIMER_H_ */
