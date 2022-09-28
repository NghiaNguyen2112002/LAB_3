/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SEL_BUTTON_Pin GPIO_PIN_5
#define SEL_BUTTON_GPIO_Port GPIOA
#define MODI_BUTTON_Pin GPIO_PIN_6
#define MODI_BUTTON_GPIO_Port GPIOA
#define SET_BUTTON_Pin GPIO_PIN_7
#define SET_BUTTON_GPIO_Port GPIOA
#define seg_1_Pin GPIO_PIN_0
#define seg_1_GPIO_Port GPIOB
#define seg_2_Pin GPIO_PIN_1
#define seg_2_GPIO_Port GPIOB
#define seg_3_Pin GPIO_PIN_2
#define seg_3_GPIO_Port GPIOB
#define en3_Pin GPIO_PIN_10
#define en3_GPIO_Port GPIOB
#define en4_Pin GPIO_PIN_11
#define en4_GPIO_Port GPIOB
#define r1_Pin GPIO_PIN_10
#define r1_GPIO_Port GPIOA
#define a1_Pin GPIO_PIN_11
#define a1_GPIO_Port GPIOA
#define g1_Pin GPIO_PIN_12
#define g1_GPIO_Port GPIOA
#define r2_Pin GPIO_PIN_13
#define r2_GPIO_Port GPIOA
#define a2_Pin GPIO_PIN_14
#define a2_GPIO_Port GPIOA
#define g2_Pin GPIO_PIN_15
#define g2_GPIO_Port GPIOA
#define seg_4_Pin GPIO_PIN_3
#define seg_4_GPIO_Port GPIOB
#define seg_5_Pin GPIO_PIN_4
#define seg_5_GPIO_Port GPIOB
#define seg_6_Pin GPIO_PIN_5
#define seg_6_GPIO_Port GPIOB
#define seg_7_Pin GPIO_PIN_6
#define seg_7_GPIO_Port GPIOB
#define en1_Pin GPIO_PIN_8
#define en1_GPIO_Port GPIOB
#define en2_Pin GPIO_PIN_9
#define en2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
