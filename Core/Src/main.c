/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <math.h>
#include <string.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
int letras[28];
int numeroDisplays=8;
int displayEncendido=0;
char nombre1[] = "ANA CAROLINA CARRILLO LOMBANA ";
char nombre2[] = "MARIA JULIANA NIETO MORENO    ";
char nombre3[] = "LAURA ALEJANDRA PARADA GAMBOA ";
char elegir_NOMBRE[30]; //-> aqui asigno el nombre que va
int longitud=0;
int token[7];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void definirLetras(); //Define las letras en el vector
int getLetra(char letra);
int secuenciarTransitores();
void select_NOMBRE();//-> crear una función que asigne el valor a elegir
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  int displayActual=0;
  int numRepe=50;
  int aux=0;
  int token=0;
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  definirLetras();
  displayEncendido = pow(2, numeroDisplays);
  longitud = strlen(elegir);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  switch(displayActual){
	  	  case 1:
	  		GPIOA->ODR=getLetra(elegir[token+0]);
	  	  break;
	  	  case 2:
	  		GPIOA->ODR=getLetra(elegir[token+1]);
	  	  break;
	  	  case 3:
	  		GPIOA->ODR=getLetra(elegir[token+2]);
	  	  break;
	  	  case 4:
	  		GPIOA->ODR=getLetra(elegir[token+3]);
	  	  break;
	  	  case 5:
	  		GPIOA->ODR=getLetra(elegir[token+4]);
	  	  break;
	  	  case 6:
	  		GPIOA->ODR=getLetra(elegir[token+5]);
	  	  break;
	  	  case 7:
	  		GPIOA->ODR=getLetra(elegir[token+6]);
	  	  break;
	  	  case 8:
	  		GPIOA->ODR=getLetra(elegir[token+7]);
	  	  break;
	  	  case 9:
	  		GPIOA->ODR=getLetra(elegir[token+8]);
	  	  break;
	  	  case 10:
	  		GPIOA->ODR=getLetra(elegir[token+9]);
	  	  break;
	  	  case 11:
	  		GPIOA->ODR=getLetra(elegir[token+10]);
	  	  break;
	  	  case 12:
	  		GPIOA->ODR=getLetra(elegir[token+11]);
	  	  break;
	  	  case 13:
	  		GPIOA->ODR=getLetra(elegir[token+12]);
	  	  break;
	  	  case 14:
	  		GPIOA->ODR=getLetra(elegir[token+13]);
	  	  break;
	  	  case 15:
	  		GPIOA->ODR=getLetra(elegir[token+14]);
	  	  break;
	  	  case 16:
	  		GPIOA->ODR=getLetra(elegir[token+15]);
	  	  break;
	  	  case 17:
	  		GPIOA->ODR=getLetra(elegir[token+16]);
	  	  break;
	  	  case 18:
	  		GPIOA->ODR=getLetra(elegir[token+17]);
	  	  break;
	  	  case 19:
	  		GPIOA->ODR=getLetra(elegir[token+18]);
	  	  break;
	  	  case 20:
	  		GPIOA->ODR=getLetra(elegir[token+19]);
	  	  break;
	  	  case 21:
	  		GPIOA->ODR=getLetra(elegir[token+20]);
	  	  break;
	  	  case 22:
	  		GPIOA->ODR=getLetra(elegir[token+21]);
	  	  break;
	  	  case 23:
	  		GPIOA->ODR=getLetra(elegir[token+22]);
	  	  break;
	  	  case 24:
	  		GPIOA->ODR=getLetra(elegir[token+23]);
	  	  break;
	  	  case 25:
	  		GPIOA->ODR=getLetra(elegir[token+24]);
	  	  break;
	  	  case 26:
	  		GPIOA->ODR=getLetra(elegir[token+25]);
	  	  break;
	  	  case 27:
	  		GPIOA->ODR=getLetra(elegir[token+26]);
	  	  break;
	  	  case 28:
	  		GPIOA->ODR=getLetra(elegir[token+27]);
	  	  break;
	  	  case 29:
	  		GPIOA->ODR=getLetra(elegir[token+28]);
	  	  break;
	  	  case 0:
	  		GPIOA->ODR=getLetra(elegir[token+29]);
	  	  break;
	  	  default:
	  		GPIOA->ODR=0;
	  }


	 // GPIOA->ODR=getLetra('A');
	  HAL_Delay(1);
	  GPIOB->ODR=0xFF;
	  GPIOA->ODR=0;
	  HAL_Delay(1);
	  GPIOB->ODR=~secuenciarTransitores();

	  displayActual++;
	  if(displayActual==numeroDisplays) {displayActual=0;}


	  if(aux < numRepe){
	  	     aux++;
	  	  }else{
	  		  aux=0;
	  		  if(token < longitud){
	  			  token++;
	  		  }else{
	  			  token=0;
	  		  }

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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 PA7
                           PA8 PA9 PA10 PA11
                           PA12 PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3
                           PB4 PB5 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void definirLetras(){
	letras[0]=62232;
	letras[1]=64586;
	letras[2]=52992;
	letras[3]=64578;
	letras[4]=53008;
	letras[5]=49936;
	letras[6]=57096;
	letras[7]=13080;
	letras[8]=52290;
	letras[9]=15872;
	letras[10]=817;
	letras[11]=3840;
	letras[12]=13216;
	letras[13]=13185;
	letras[14]=65280;
	letras[15]=58136;
	letras[16]=65281;
	letras[17]=58137;
	letras[18]=56600;
	letras[19]=49218;
	letras[20]=16128;
	letras[21]=804;
	letras[22]=13061;
	letras[23]=165;
	letras[24]=15640;
	letras[25]=52260;


}

int getLetra(char letra){
	int aux=0;
	if(letra==' '){
		return 0;
	}else{
		return letras[(int)(letra-65)];
	}

}

int secuenciarTransitores(){
	if(displayEncendido==1) displayEncendido=pow(2,numeroDisplays);
	displayEncendido=displayEncendido>>1;
	return displayEncendido;
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
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
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
