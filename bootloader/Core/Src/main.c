/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "iap.h"
#include "stmflash.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint16_t g_buff_i,g_buff_m,g_buff_n;
uint8_t status_machine=0;
uint8_t status2_machine=0;
uint32_t g_FileSize=0;
uint16_t g_flash_wr = 0xFFFF;
uint16_t g_flash_rd = 0;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
	
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	stmflash_read(0x8005800, &g_flash_rd, 1);    /* 从指定地址开始读出指定长度的数据 */
	if(g_flash_rd == 0xFFFF)
	{
		if (((*(volatile uint32_t *)(FLASH_APP1_ADDR + 4)) & 0xFF000000) == 0x08000000) /* 判断FLASH里面是否有APP,有的话执行 */
		{
				printf("开始执行FLASH用户代码!!\r\n\r\n");
				HAL_Delay(10);
				iap_load_app(FLASH_APP1_ADDR);/* 执行FLASH APP代码 */

		}
	}
  while (1)
  {
    /* USER CODE END WHILE */
		
		
//		g_flash_wr[0] = 0xFFFF;
//		g_flash_wr[1] = 0xFFFF;
//		stmflash_write(0x8005800, g_flash_wr, 2); /* 写入一个半字 */
    /* USER CODE BEGIN 3 */

			switch(status_machine)
			{
				case 0:{
									g_buff_i = 3;
									if(g_YmodemOnePackDone==1)
									{
										g_YmodemOnePackDone = 0;
										if(g_YmodemOnePackSize==1 && g_rx_buffer[0]==0xEE)
										{
											while(g_buff_i>0)
											{
												printf("准备倒计时:%ds\r\n", g_buff_i--);
												HAL_Delay(1000);
											}
											while(g_YmodemOnePackDone==0)
											{
												Ymodem_Send_C(&huart1);
												HAL_Delay(1000);
											}
											status_machine = 1;
										}	
									}									
				}break;
				case 1:{//接收文件名和大小
									if(g_YmodemOnePackDone==1)
									{
										g_YmodemOnePackDone = 0;
										Ymodem_Send_ACK(&huart1);
										if(g_rx_buffer[0] == 0x01 || g_rx_buffer[0] == 0x02)//128字节帧 1024字节帧
										{
											g_buff_i = 3;//从第四个字节开始获取文件名
											g_buff_m = 0;
											g_buff_n = 0;
											/*file name*/
											while(g_rx_buffer[g_buff_i++]!=0x00);
											/*file size*/
											while(g_rx_buffer[g_buff_i]!=0x00)
											{
//												
												g_FileSize = g_FileSize*10;
//												
												g_FileSize = g_FileSize + (g_rx_buffer[g_buff_i] - 48);
												g_buff_m++;
												g_buff_i++;
											}
										}
										Ymodem_Send_C(&huart1);
										status_machine = 2;
									}
				}break;
				case 2:{//接收数据内容
					switch(status2_machine)
					{
						case 0:{
										if(g_YmodemOnePackDone==1)
										{
											g_YmodemOnePackDone = 0;
											if(g_rx_buffer[0] == 0x01 )//128字节帧 
											{
												if(g_FileSize>128)
												{
													/*第一包数据检查Reset_Handler地址*/
													if(((*(volatile uint32_t *)(0X20001000 + 7)) & 0xFF000000) == 0x08000000)
													{
														iap_write_appbin(FLASH_APP1_ADDR, g_rx_buffer+3, 128);
														g_FileSize = g_FileSize - 128;
													}
												}
												else
												{
													/*第一包数据检查Reset_Handler地址*/
													if(((*(volatile uint32_t *)(0X20001000 + 7)) & 0xFF000000) == 0x08000000)
													{
														iap_write_appbin(FLASH_APP1_ADDR, g_rx_buffer+3, g_FileSize);
														g_FileSize = 0;
													}
												}
												status2_machine = 1;
												Ymodem_Send_ACK(&huart1);
											}
											else if(g_rx_buffer[0] == 0x02 )//1024字节帧
											{
												if(g_FileSize>1024)
												{
													/*第一包数据检查Reset_Handler地址*/
													if(((*(volatile uint32_t *)(0X20001000 + 7)) & 0xFF000000) == 0x08000000)
													{
														iap_write_appbin(FLASH_APP1_ADDR, g_rx_buffer+3, 1024);
														g_FileSize = g_FileSize - 1024;
													}
												}
												else
												{
													/*第一包数据检查Reset_Handler地址*/
													if(((*(volatile uint32_t *)(0X20001000 + 7)) & 0xFF000000) == 0x08000000)
													{
														iap_write_appbin(FLASH_APP1_ADDR, g_rx_buffer+3, g_FileSize);
														g_FileSize = 0;
													}
												}
												status2_machine = 1;
												Ymodem_Send_ACK(&huart1);
											}
										}	
						}break;
						case 1:{
										if(g_YmodemOnePackDone==1)
										{
											g_YmodemOnePackDone = 0;
											if(g_rx_buffer[0] == 0x01 )//128字节帧 
											{
												if(g_FileSize>128)
												{
													iap_write_appbin(FLASH_APP1_ADDR+128*(g_YmodemOnePackFN-1), g_rx_buffer+3, 128);
													g_FileSize = g_FileSize - 128;
												}
												else
												{
													iap_write_appbin(FLASH_APP1_ADDR+128*(g_YmodemOnePackFN-1), g_rx_buffer+3, g_FileSize);
													g_FileSize = 0;
												}
												status2_machine = 1;
												Ymodem_Send_ACK(&huart1);
											}
											else if(g_rx_buffer[0] == 0x02 )// 1024字节帧
											{
												if(g_FileSize>1024)
												{
													iap_write_appbin(FLASH_APP1_ADDR+1024*(g_YmodemOnePackFN-1), g_rx_buffer+3, 1024);
													g_FileSize = g_FileSize - 1024;
												}
												else
												{
													iap_write_appbin(FLASH_APP1_ADDR+1024*(g_YmodemOnePackFN-1), g_rx_buffer+3, g_FileSize);
													g_FileSize = 0;
												}
												status2_machine = 1;
												Ymodem_Send_ACK(&huart1);
											}
											else if(g_rx_buffer[0] == 0x04)
											{
												Ymodem_Send_NAK(&huart1);
												while(g_YmodemOnePackDone==0);
												g_YmodemOnePackDone = 0;
												Ymodem_Send_ACK(&huart1);
												status_machine = 3;
											}	
										}	
						}break;
						default:;
					}					
				}break;
				case 3:{
									if (((*(volatile uint32_t *)(FLASH_APP1_ADDR + 4)) & 0xFF000000) == 0x08000000) /* 判断FLASH里面是否有APP,有的话执行 */
									{
											stmflash_write(0x8005800, &g_flash_wr, 1); /* 写入一个半字 */
											printf("开始执行FLASH用户代码!!\r\n\r\n");
											HAL_Delay(10);
											iap_load_app(FLASH_APP1_ADDR);/* 执行FLASH APP代码 */

									}
				}break;
			}
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* USART1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(USART1_IRQn);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
