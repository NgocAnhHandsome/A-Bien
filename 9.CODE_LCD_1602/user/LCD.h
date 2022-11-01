/**
  ********************************************************************************
  * @file    stm8s_uart1.h
  * @author  Nguyen Quang Bien
  * @version 
  * @date    
  * @brief   
  *******************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LCD__
#define __LCD__

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "GPIO.h"   
 
#define LCD_RS      GPIO_PIN_4
#define LCD_RW      GPIO_PIN_2
#define LCD_EN      GPIO_PIN_5

#define LCD_D4      GPIO_PIN_4
#define LCD_D5      GPIO_PIN_5
#define LCD_D6      GPIO_PIN_6
#define LCD_D7      GPIO_PIN_7
    
#define PORTSET GPIOB
#define PORTDATA GPIOC

#define PINDATA (LCD_D4 | LCD_D5 | LCD_D6 | LCD_D7)
#define PINSET  (LCD_RS | LCD_RW | LCD_EN)
  
#define RS_Set   GPIO_WriteHigh(PORTSET,LCD_RS);
#define RS_ReSet GPIO_WriteLow(PORTSET,LCD_RS);

#define RW_Set   GPIO_WriteHigh(PORTSET,LCD_RW);
#define RW_ReSet GPIO_WriteLow(PORTSET,LCD_RW);

#define EN_Set   GPIO_WriteHigh(PORTSET,LCD_EN);
#define EN_ReSet GPIO_WriteLow(PORTSET,LCD_EN);
    
void GPIO_LCD_Config(void);
void LCD_Enable(void);
void LCD_Send4Bit(unsigned char Data);
void LCD_SendCommand(unsigned char command);
void LCD_Clear();
void LCD_Init();
void LCD_Gotoxy(unsigned char x, unsigned char y);
void LCD_PutChar(unsigned char Data);
void LCD_Puts(char *s);


#endif /* __STM8S_UART1_H */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/