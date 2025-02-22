/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

/* USER CODE BEGIN Private defines */
//typedef struct Y_File{
//	uint8_t SOH_STX;
//	uint8_t FN;
//	uint8_t XFN;
//	uint8_t FileName[512];

//	uint16_t Crc;
//}Ymodemdef;
//Ymodemdef Ymodem;
/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);

/* USER CODE BEGIN Prototypes */
#define USART_REC_LEN               1029   /* Ymodem一包最大1024 + 5字节 */
#define USART_EN_RX                 1           /* 使能（1）/禁止（0）串口1接收 */

#define RXBUFFERSIZE                200           /* 缓存大小 */
extern uint8_t g_rx_buffer[USART_REC_LEN];
extern uint8_t g_YmodemOnePackDone;
extern uint16_t g_YmodemOnePackSize;
extern uint8_t g_YmodemOnePackFN;
uint8_t Ymodem_Send_C(UART_HandleTypeDef *huart);
uint8_t Ymodem_Send_ACK(UART_HandleTypeDef *huart);
uint8_t Ymodem_Send_NAK(UART_HandleTypeDef *huart);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
