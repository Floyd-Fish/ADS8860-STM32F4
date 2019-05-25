#include "ads8860.h"


//    ADS8860-Test Project.
//    First using 3-Wire CS Mode Without a Busy Indicator
//    In this interface option, DIN is HIGH and CONVST functions as CS Pin
//    
//    Author: xxxxt
//	  Date: 2019-5-23
//	  Project Platform: CubeMX+Keil MDK5
//	  No further more informations provided.
//


static void DOUT_Reset(void) 
{ 
	HAL_GPIO_WritePin(DOUT_Port, DOUT_Pin, GPIO_PIN_RESET); 
}

static void DOUT_Set(void) 
{ 
	HAL_GPIO_WritePin(DOUT_Port, DOUT_Pin, GPIO_PIN_SET);
}

static void  DIN_Reset(void) 
{
	HAL_GPIO_WritePin(DIN_Port, DIN_Pin, GPIO_PIN_RESET);
}

static void DIN_Set(void) 
{
	HAL_GPIO_WritePin(DIN_Port, DIN_Pin, GPIO_PIN_SET);
}

static void CONVST_Reset(void) 
{ 
	HAL_GPIO_WritePin(CONVST_Port, CONVST_Pin, GPIO_PIN_RESET);
}

static void CONVST_Set(void) 
{ 
	HAL_GPIO_WritePin(CONVST_Port, CONVST_Pin, GPIO_PIN_SET);
}

uint16_t ADS8860_ReadValue(void)
{
	uint16_t adcReadBuffer = 0;
	uint8_t readBuffer = 0;

	DIN_Set();
	CONVST_Set();
	delay_600ns();
	CONVST_Reset();

	HAL_SPI_Receive(&ADS8860_SPI_Port, &readBuffer, 8, 0xFFFF);
	adcReadBuffer = readBuffer;
	readBuffer = 0;
	HAL_SPI_Receive(&ADS8860_SPI_Port, &readBuffer, 8, 0xFFFF);
	adcReadBuffer = adcReadBuffer << 8;
	adcReadBuffer |= readBuffer;

	return adcReadBuffer;
	HAL_GPIO_WritePin(SCLK_Port, SCLK_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DOUT_Port, DOUT_Pin, GPIO_PIN_RESET);
}

void delay_600ns(void)
{
	for (uint8_t i = 0; i < 100; i++)
		__nop();

}

void ads8860_Init(void)
{
	DIN_Set();
	CONVST_Reset();
}
