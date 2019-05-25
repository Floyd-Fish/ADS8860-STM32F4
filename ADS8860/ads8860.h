#ifndef __ADS8860_H
#define __ADS8860_H

#include "main.h"

#define SCLK_Pin GPIO_PIN_5
#define SCLK_Port GPIOA
#define DIN_Pin GPIO_PIN_7
#define DIN_Port GPIOA
#define DOUT_Pin GPIO_PIN_6
#define DOUT_Port GPIOA
#define CONVST_Pin GPIO_PIN_4
#define CONVST_Port GPIOA

#define ADS8860_SPI_Port hspi1
extern SPI_HandleTypeDef ADS8860_SPI_Port;

#define Conversation_Relay 100

uint16_t ADS8860_ReadValue(void);

void delay_600ns(void);
void ads8860_Init(void);

#endif
