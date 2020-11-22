/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdlib.h"
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
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */
uint8_t mode;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define loop_time	5

void LED_Reset(void);
void scan_led(int delay_time);
void shift(void);
void cube_data_reset(void);
void effect1(void);
void effect2(void);
void effect3(void);
void effect4(void);
void effect5(void);
void effect6(void);
void effect7(void);
void effect8(void);

uint8_t LAYER_Data[1] = {0xFF};
uint8_t LED_Data[8] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA};
uint8_t Matrix_Data[8] = {0x18, 0x3c, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66};
uint8_t cube_data[8][8];

//uint8_t LED_Reset_Data[8] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//uint8_t Side_Enable[8] = {0, 1, 0, 1, 0, 1, 0, 1};

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
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  LED_Reset();
  HAL_Delay(1000);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  switch(mode)
	  {
	  	  case 0:
	  	  {
//	  		  uint8_t count = 0;
//	  		  for(count = 0; count < loop_time; count++)
//	  		  {
//	  			  effect1();
//	  		  }
//	  		  for(count = 0; count < loop_time; count++)
//	  		  {
//	  			  effect2();
//	  		  }
//	  		  for(count = 0; count < loop_time; count++)
//	  		  {
//	  			  effect3();
//	  		  }
//	  		  for(count = 0; count < loop_time; count++)
//	  		  {
//	  			  effect4();
//	  		  }

	  		  effect8();

	  		  break;
	  	  }
	  	  case 1:
	  	  {
	  		  effect1();
	  		  break;
	  	  }
	  	  case 2:
	  	  {
	  		  effect2();
	  		  break;
	  	  }
	  	  case 3:
	  	  {
	  		  effect3();
	  		  break;
	  	  }
	  	  case 4:
	  	  {
	  		  effect4();
	  		  break;
	  	  }
	  	  case 5:
	  	  {
	  		  effect5();
	  		  break;
	  	  }
	  	  case 6:
	  	  {
	  		  effect6();
	  		  break;
	  	  }
	  	  case 7:
	  	  {
	  		  effect7();
	  		  break;
	  	  }
	  	  default:
	  	  {
	  		  effect1();
	  		  break;
	  	  }
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LayerLatch_Pin|DataLatch_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : Button_Pin */
  GPIO_InitStruct.Pin = Button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(Button_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LayerLatch_Pin DataLatch_Pin */
  GPIO_InitStruct.Pin = LayerLatch_Pin|DataLatch_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

}

/* USER CODE BEGIN 4 */
void LED_Reset(void)
{
	uint8_t temp = 0;

	LED_Data[0] = 0xFF;
	LED_Data[1] = 0xFF;
	LED_Data[2] = 0xFF;
	LED_Data[3] = 0xFF;
	LED_Data[4] = 0xFF;
	LED_Data[5] = 0xFF;
	LED_Data[6] = 0xFF;
	LED_Data[7] = 0xFF;

	LAYER_Data[0] = ~temp;

	HAL_GPIO_WritePin(DataLatch_GPIO_Port, DataLatch_Pin, GPIO_PIN_SET);
	HAL_SPI_Transmit(&hspi1, LED_Data, 8, 10);
	HAL_GPIO_WritePin(DataLatch_GPIO_Port, DataLatch_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LayerLatch_GPIO_Port, LayerLatch_Pin, GPIO_PIN_SET);
	HAL_SPI_Transmit(&hspi1, LAYER_Data, 1, 10);
	HAL_GPIO_WritePin(LayerLatch_GPIO_Port, LayerLatch_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LayerLatch_GPIO_Port, LayerLatch_Pin, GPIO_PIN_SET);
}

void scan_led(int delay_time)
{
	uint8_t temp=1;
	uint8_t i;
	uint8_t k;

	for(i=0;i<8;i++)
	{
		for(k=0; k<8; k++)
		{
			LED_Data[k] = cube_data[i][k];
		}

		LAYER_Data[0] = ~temp;

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, LED_Data, 8, 10);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, LAYER_Data, 1, 10);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

		temp = temp << 1;
		HAL_Delay(delay_time);
	}
}

void shift(void)
{
	uint8_t i;
	uint8_t j;
	for(i=7; i>0; i--)
	{
		for(j=0; j<8; j++)
		{
			cube_data[i][j] = cube_data[i-1][j];
		}
	}
}

void cube_data_reset(void)
{
	uint8_t i;
	uint8_t j;
	for(i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			cube_data[i][j] = 0xFF;
		}
	}
}

void effect1(void)
{
	uint8_t temp = 1;
	uint8_t i;
	uint8_t k;
	for(i=0;i<8;i++)
	{
		LAYER_Data[0] = ~temp;
		for(k=0;k<8;k++)
		{
			LED_Data[k] = 0xFF;
		}

		LED_Data[0] = ~Matrix_Data[i];

		HAL_GPIO_WritePin(DataLatch_GPIO_Port, DataLatch_Pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, LED_Data, 8, 10);
		HAL_GPIO_WritePin(DataLatch_GPIO_Port, DataLatch_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LayerLatch_GPIO_Port, LayerLatch_Pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, LAYER_Data, 1, 10);
		HAL_GPIO_WritePin(LayerLatch_GPIO_Port, LayerLatch_Pin, GPIO_PIN_SET);

		HAL_Delay(0);
		temp = temp << 1;
	}
}

//hinh vuong chay
void effect2(void)
{
	uint8_t temp=1;
	uint8_t i;

	LED_Data[0] = 0x00;
	LED_Data[1] = 0x7E;
	LED_Data[2] = 0x7E;
	LED_Data[3] = 0x7E;
	LED_Data[4] = 0x7E;
	LED_Data[5] = 0x7E;
	LED_Data[6] = 0x7E;
	LED_Data[7] = 0x00;

	for(i=0;i<8;i++)
	{
		LAYER_Data[0] = ~temp;

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, LED_Data, 8, 10);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, LAYER_Data, 1, 10);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

		temp = temp << 1;
		HAL_Delay(100);
	}
}

//rain fall 1
void effect3(void)
{
	uint8_t temp = 1;
	uint8_t i;
	uint8_t k;

	for(i=0;i<8;i++)
	{
		//random value from 1 to 8 by rand()%(maxN + 1 - minN)
		for(k=0; k<8; k++)
		{
			LED_Data[k] = 1;
			LED_Data[k] = LED_Data[k] << rand()%8;
			LED_Data[k] = ~LED_Data[k];
		}
		LAYER_Data[0] = ~temp;

		HAL_GPIO_WritePin(DataLatch_GPIO_Port, DataLatch_Pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, LED_Data, 8, 10);
		HAL_GPIO_WritePin(DataLatch_GPIO_Port, DataLatch_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LayerLatch_GPIO_Port, LayerLatch_Pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, LAYER_Data, 1, 10);
		HAL_GPIO_WritePin(LayerLatch_GPIO_Port, LayerLatch_Pin, GPIO_PIN_SET);

		HAL_Delay(100);
		temp = temp << 1;
	}
}

//rain fall 2
void effect4(void)
{
	uint8_t temp = 1;
	uint8_t i;
	uint8_t k;

	//random value from 1 to 8 by rand()%(maxN + 1 - minN)
	for(k=0; k<8; k++)
	{
		LED_Data[k] = 1;
		LED_Data[k] = LED_Data[k] << rand()%8;
		if(k>0)
		{
			while(LED_Data[k] == (~LED_Data[k-1]))
			{
				LED_Data[k] = 1;
				LED_Data[k] = LED_Data[k] << rand()%8;
			}
		}

		LED_Data[k] = ~LED_Data[k];
	}

	HAL_GPIO_WritePin(DataLatch_GPIO_Port, DataLatch_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, LED_Data, 8, 10);
	HAL_GPIO_WritePin(DataLatch_GPIO_Port, DataLatch_Pin, GPIO_PIN_SET);

	for(i=0;i<10;i++)
	{
		LAYER_Data[0] = ~temp;
		HAL_GPIO_WritePin(LayerLatch_GPIO_Port, LayerLatch_Pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, LAYER_Data, 1, 10);
		HAL_GPIO_WritePin(LayerLatch_GPIO_Port, LayerLatch_Pin, GPIO_PIN_SET);
		HAL_Delay(90);
		temp = temp << 1;
		if((i==0) | (i==1))	temp = temp|0x01;
	}
}

void effect5(void)
{
	uint8_t i;
	uint8_t j;

	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			if(((i==0) || (i==7)) && ((j==0) || (j==7)))	cube_data[i][j] = 0x00;
			else if ((i>0) && (i<7) && (j>0) && (j<7))	cube_data[i][j] = 0xFF;
			else cube_data[i][j] = 0x7E;
		}
	}
	scan_led(0);
}

void effect6(void)
{
	uint8_t i;
	uint8_t j;
	for(i=0;i<8;i++)
	{
		for(j=0; j<8; j++)
		{
			if(j==0 || j==7)		cube_data[i][j] = 0x00;
			else	cube_data[i][j] = 0x7E;
		}
	}
	scan_led(0);
}

//rain fall 3
void effect7(void)
{
	uint8_t count=20;
	uint8_t i;
	uint8_t k;
	LED_Reset();

	for(i=0; i<8; i++)
	{
		for(k=0; k<8; k++)
		{
			if(i==0)
			{
				cube_data[i][k] = 1;
				cube_data[i][k] = cube_data[i][k] << rand()%8;

				cube_data[i][k] = ~cube_data[i][k];
			}
//			else if(i>0 && i<4)	cube_data[i][k] = cube_data[i-1][k];
		}
	}
	while(count--)
	{
		scan_led(0);
	}
	shift();
}

void effect8(void)
{
	uint8_t i;
	uint8_t j;
	uint8_t delay;
	for(i=0; i<8; i++)
	{
		delay = 10;
		if(i<4) j=i;
		else	j=8-i;
		cube_data_reset();
		cube_data[0][j] = 0xFF;
		cube_data[1][j] = 0x93;
		cube_data[2][j] = 0x01;
		cube_data[3][j] = 0x01;
		cube_data[4][j] = 0x01;
		cube_data[5][j] = 0x83;
		cube_data[6][j] = 0xC7;
		cube_data[7][j] = 0xEF;

		while(delay--)
		{
			scan_led(0);
		}
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
