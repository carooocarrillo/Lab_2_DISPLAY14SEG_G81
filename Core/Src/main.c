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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>
#include <string.h>
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
int numeroDisplays = 6;
int displayEncendido = 0;
char nombre1[] = "ANA CAROLINA CARRILLO LOMBANA ";
char nombre2[] = "MARIA JULIANA NIETO MORENO    ";
char nombre3[] = "LAURA ALEJANDRA PARADA GAMBOA ";

char *salidaNombre;

int estudiante = 0;
int longitud = 0;
int token = 0;

GPIO_PinState LastButtonState = GPIO_PIN_SET;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void definirLetras(void); //Define las letras en el vector
int getLetra(char letra);
int secuenciarTransitores(void);
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
    int displayActual = 0;
    int numRepe = 50;
    int aux = 0;
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

  salidaNombre = nombre1;
  longitud = strlen(salidaNombre);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		  GPIO_PinState buttonState = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

		  if(buttonState == GPIO_PIN_RESET && LastButtonState == GPIO_PIN_SET){
		  	  HAL_Delay(20);

		  	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET){
		  		  estudiante++;

		  		  if(estudiante > 2){
		  			  estudiante = 0;
		  		  }

		  		  if(estudiante == 0){
		  			salidaNombre = nombre1;
		  		  }

		  		  else if(estudiante == 1){
		  			salidaNombre = nombre2;
		  		  }

		  		  else if(estudiante == 2){
		  			salidaNombre = nombre3;
		  		  }

		  		  token = 0;
		  		  aux = 0;
		  		  longitud = strlen(salidaNombre);
		  	  }
		  }

		  LastButtonState = buttonState;

		  if(aux < numRepe){
			  aux++;
	  	  }

		  else{
			  aux=0;
			  if(token < longitud){
				  token++;
			  }

			  else{
		  			  token = 0;
		  		  }
		  	}

		  switch (displayActual) {
		        case 5:
		        	GPIOB->ODR = ~getLetra(salidaNombre[(token + 0) % longitud]);
		        break;
		        case 4:
		        	GPIOB->ODR = ~getLetra(salidaNombre[(token + 1) % longitud]);
		        break;
		        case 3:
		        	GPIOB->ODR = ~getLetra(salidaNombre[(token + 2) % longitud]);
		        break;
		        case 2:
		        	GPIOB->ODR = ~getLetra(salidaNombre[(token + 3) % longitud]);
		        break;
		        case 1:
		        	GPIOB->ODR = ~getLetra(salidaNombre[(token + 4) % longitud]);
		        break;
		        case 0:
		        	GPIOB->ODR = ~getLetra(salidaNombre[(token + 5) % longitud]);
		        break;
		        default:
		        	GPIOB->ODR = 0xFFFF;
		      }

		  HAL_Delay(1);

		  GPIOA->ODR = 0x00;
		  GPIOB->ODR = 0xFFFF;

		  HAL_Delay(1);

		  GPIOA->ODR = secuenciarTransitores() << 2;

		  displayActual++;
		  if(displayActual >= numeroDisplays){
			  displayActual=0;
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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA3 PA4 PA5 PA6
                           PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB12 PB13 PB14
                           PB15 PB3 PB4 PB5
                           PB6 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void definirLetras(void) {
	  letras[0]  = 35023;
	  letras[1]  = 10815;
	  letras[2]  = 243;
	  letras[3]  = 8767;
	  letras[4]  = 35059;
	  letras[5]  = 35011;
	  letras[6]  = 2299;
	  letras[7]  = 35020;
	  letras[8]  = 8755;
	  letras[9]  = 124;
	  letras[10] = 38080;
	  letras[11] = 240;
	  letras[12] = 1484;
	  letras[13] = 4556;
	  letras[14] = 255;
	  letras[15] = 35015;
	  letras[16] = 16639;
	  letras[17] = 39111;
	  letras[18] = 35003;
	  letras[19] = 8707;
	  letras[20] = 252;
	  letras[21] = 17600;
	  letras[22] = 20684;
	  letras[23] = 21760;
	  letras[24] = 9472;
	  letras[25] = 17459;
}

int getLetra(char letra){
    if(letra >= 'A' && letra <= 'Z'){
        return letras[(int)(letra - 'A')];
    } else {
        return 0; // Espacio o carácter inválido
    }
}

int secuenciarTransitores(){
	if(displayEncendido == 1) displayEncendido = pow(2, numeroDisplays);
	displayEncendido =  displayEncendido >> 1;
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
