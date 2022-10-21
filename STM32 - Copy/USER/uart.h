 
/*
  ******************************************************************************
  * @file		Uart.h                                                              *
  * @author	Nguyen Quang Bien                                                  *
  * @date		00/00/0000                                                         *
  ******************************************************************************
*/
	
#ifndef __UART__
#define __UART__





#ifdef __cplusplus
 extern "C" {
#endif
#include "stm32f10x.h"                  // Device header
#include "string.h"
#include "ringbuffer.h"
#include "stdio.h"

#define  TIME_OUT  0x016E1E90
#define  UART1_BAUDRATE (9600)
#define  UART2_BAUDRATE (9600)
#define  UART3_BAUDRATE (9600)
	 
#define string_size 20
	 
extern char Flag1_Receive;
extern char Array1_Receive[];
extern char Count1_Data;

extern volatile uint32_t TimeOut;
	 
extern char Flag2_Receive;
extern char Array2_Receive[];
extern char Count2_Data;

extern char Flag3_Receive;
extern char Array3_Receive[];
extern char Count3_Data;	
extern _ringbuffer_t ringbuffer_Test;	
	 
void INIT_UART(void);
void INIT_UART_1(unsigned int BaudRates);
void UART1_SendChar(char data);
void UART1_SendString(char *data);
void UART1_SendByte(uint8_t *data, uint8_t sizes); 

void INIT_UART_2(unsigned int BaudRates);
void UART2_SendChar(char data);
void UART2_SendString(char *data);
void UART2_SendByte(uint8_t *data, uint8_t sizes); 

void INIT_UART_3(unsigned int BaudRates);
void UART3_SendChar(char data);		 
void UART3_SendString(char *data);
char* RETURN_HI100(void);

#ifdef __cplusplus
}
#endif

#endif

