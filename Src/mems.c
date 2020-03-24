/**
 ******************************************************************************
 * @file    BSP/Src/mems.c
 * @author  MCD Application Team
 * @brief   This example code shows how to use MEMS features.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "mems.h"
#include "stm32f3_discovery_accelerometer.h"
#include "stm32f3_discovery_gyroscope.h"

/** @addtogroup BSP_Examples
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern __IO uint8_t UserPressButton;
/* Init af threahold to detect acceleration on MEMS */
int16_t ThresholdHigh = 1000;
int16_t ThresholdLow = -1000;
/* Private function prototypes -----------------------------------------------*/
static void ACCELERO_ReadAcc(void);
static void GYRO_ReadAng(void);
/* Private functions ---------------------------------------------------------*/
/**
 * @brief Test ACCELERATOR MEMS Hardware.
 *   The main objective of this test is to check acceleration on 2 axis X and Y
 * @param  None
 * @retval None
 */
void ACCELERO_MEMS_Test(void)
{
	/* Init Accelerometer Mems */
	if(BSP_ACCELERO_Init() != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

	UserPressButton = 0;
	while(!UserPressButton)
	{
		ACCELERO_ReadAcc();
		HAL_Delay(100);
	}
}

void InitAccelero(void) {
	/* Init Accelerometer Mems */
	if(BSP_ACCELERO_Init() != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}
}

void SetAccelero(int16_t *x, int16_t *y, int16_t *z) {
	int16_t buffer[3] = {0};
	BSP_ACCELERO_GetXYZ(buffer);
	*x=buffer[0];
	*y=buffer[1];
	*z=buffer[2];
	HAL_Delay(10);
}

void SetAccF(float *x, float *y, float *z) {
	int16_t buffer[3] = {0};
	BSP_ACCELERO_GetXYZ(buffer);

	/*
	 * G = 9.81
   Scale = 2.0
	it's in millie g i.e.
	x = buffer[0]/9.81*2*1000
	=> 19613.3
	but it seems app doesn't want div by 1000
	 * */

	*x=((float)buffer[0])/9.81f;
	*y=((float)buffer[1])/-9.81f;
	*z=((float)buffer[2])/9.81f;

	/*	*x = (float) (last_x - buffer[0]);
	 *y = (float) (last_y - buffer[1]);
	 *z = (float) (last_z - buffer[2]);

	last_x = buffer[0];
	last_y = buffer[1];
	last_z = buffer[2]; */
	//	*x=((float)buffer[0]);
	//	*y=((float)buffer[1]);
	//	*z=((float)buffer[2]);
	// KTargetHz = 25
	// however this seem to take too long time to gat all the data
	// Maybe fill up with zero then sample 100 at higher rate
	//HAL_Delay(40);
	HAL_Delay(40);
}

void initGyro(){
	if(BSP_GYRO_Init() != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

}

void SetGyro(float *x, float *y, float *z) {
	float buffer[3] = {0.0};
	BSP_GYRO_GetXYZ(buffer);
	*x=buffer[0]/98.f;
	*y=buffer[1]/98.f;
	*z=buffer[2]/98.f;
}
static void ACCELERO_ReadAcc(void)
{
	int16_t buffer[3] = {0};
	int16_t xval, yval = 0x00;

	/* Read Acceleration*/
	BSP_ACCELERO_GetXYZ(buffer);

	/* Update autoreload and capture compare registers value*/
	xval = buffer[0];
	yval = buffer[1];

	if((ABS(xval))>(ABS(yval)))
	{
		if(xval > ThresholdHigh)
		{
			/* LED10 On */
			//  BSP_LED_On(LED10);
			HAL_Delay(10);
		}
		else if(xval < ThresholdLow)
		{
			/* LED3 On */
			//  BSP_LED_On(LED3);
			HAL_Delay(10);
		}
		else
		{
			HAL_Delay(10);
		}
	}
	else
	{
		if(yval < ThresholdLow)
		{
			/* LED6 On */
			// BSP_LED_On(LED6);
			HAL_Delay(10);
		}
		else if(yval > ThresholdHigh)
		{
			/* LED7 On */
			// BSP_LED_On(LED7);
			HAL_Delay(10);
		}
		else
		{
			HAL_Delay(10);
		}
	}

	/*   BSP_LED_Off(LED3);
     BSP_LED_Off(LED6);
     BSP_LED_Off(LED7);
     BSP_LED_Off(LED4);
     BSP_LED_Off(LED10);
     BSP_LED_Off(LED8);
     BSP_LED_Off(LED9);
     BSP_LED_Off(LED5); */
}

/**
 * @brief Test GYROSCOPE MEMS Hardware.
 *   The main objectif of this test is to check the hardware connection of the
 *   MEMS peripheral.
 * @param None
 * @retval None
 */
void GYRO_MEMS_Test(void)
{
	/* Init Accelerometer Mems */
	if(BSP_ACCELERO_Init() != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

	UserPressButton = 0;
	while(!UserPressButton)
	{
		GYRO_ReadAng();
	}
}  

static void GYRO_ReadAng(void)
{
	/* Gyroscope variable */
	float Buffer[3];
	float Xval,Yval = 0x00;

	/* Init Gyroscope Mems */
	if(BSP_GYRO_Init() != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

	/* Read Gyro Angular data */
	BSP_GYRO_GetXYZ(Buffer);

	/* Update autoreload and capture compare registers value*/
	Xval = ABS((Buffer[0]));
	Yval = ABS((Buffer[1]));

	if(Xval>Yval)
	{
		if(Buffer[0] > 5000.0f)
		{
			/* LD10 On */
			// BSP_LED_On(LED10);
			HAL_Delay(10);
		}
		else if(Buffer[0] < -5000.0f)
		{
			/* LED3 On */
			//BSP_LED_On(LED3);
			HAL_Delay(10);
		}
		else
		{
			HAL_Delay(10);
		}
	}
	else
	{
		if(Buffer[1] < -5000.0f)
		{
			/* LD6 on */
			//BSP_LED_On(LED6);
			HAL_Delay(10);
		}
		else if(Buffer[1] > 5000.0f)
		{
			/* LD7 On */
			//BSP_LED_On(LED7);
			HAL_Delay(10);
		}
		else
		{
			HAL_Delay(10);
		}
	}
	/*BSP_LED_Off(LED3);
    BSP_LED_Off(LED6);
    BSP_LED_Off(LED7);
    BSP_LED_Off(LED4);
    BSP_LED_Off(LED10);
    BSP_LED_Off(LED8);
    BSP_LED_Off(LED9);
    BSP_LED_Off(LED5);*/
}
/**
 * @}
 */


/**
 * @}
 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
