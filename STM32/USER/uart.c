/*
  ******************************************************************************
  * @file		abc.c                                                              *
  * @author	Nguyen Quang Bien                                                  *
  * @date		00/00/0000                                                         *
  ******************************************************************************
*/

#include "stm32f10x.h"             
           
#include "uart.h" 
#include "string.h"
#include "stdio.h"


char Flag1_Receive = 0;
char Array1_Receive[string_size];
char Count1_Data=0;

char Flag2_Receive = 0;
char Array2_Receive[string_size];
char Count2_Data=0;

char Flag3_Receive = 0;
char Array3_Receive[string_size];
char Count3_Data=0;


void INIT_UART(void)
{
	INIT_UART_1(UART1_BAUDRATE);
	INIT_UART_2(UART2_BAUDRATE);
	INIT_UART_3(UART3_BAUDRATE);
}

void INIT_UART_1(unsigned int BaudRates)
{
		RCC->APB2ENR |= 0x00000004;
	  GPIOA->CRH |=  0x000004B0;
		RCC->APB2ENR |= 0x00004000;
		USART1->BRR = ((((SystemCoreClock/(BaudRates))/16)<<4)+((SystemCoreClock/(BaudRates))%16));
		USART1->CR1 |= (USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE); 			 
		NVIC_EnableIRQ(USART1_IRQn);
		USART1->CR1 |= USART_CR1_UE;
}

void UART1_SendChar(char data)
{
	USART1->DR = (data & 0x00FF);
	while((USART1->SR & 0x0080)==RESET);
}

void UART1_SendString(char *data)
{
	while(*data)
	{
		UART1_SendChar(*data);
		data++;
	}
}

void UART1_SendByte(uint8_t *data, uint8_t sizes)
{
	uint8_t i;
	for(i=0; i<sizes; i++)
	{
		USART1->DR = (data[i] & 0x00FF);
		while((USART1->SR & 0x0080)==RESET);
	}
}

void INIT_UART_2(unsigned int BaudRates)
{
	
	RCC->APB2ENR |= 0x00000004;
	GPIOA->CRL	|= 0x00004B00;
	RCC->APB1ENR |= 0x00020000;
	USART2->BRR = ((((SystemCoreClock/(BaudRates*2))/16)<<4)+((SystemCoreClock/(BaudRates))%16));
	USART2->CR1 |= (USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE); 			 
	NVIC_EnableIRQ(USART2_IRQn);
	USART2->CR1 |= USART_CR1_UE;
}

void UART2_SendChar(char data)
{
USART2->DR = (data & (uint16_t)0x01FF);
	while((USART2->SR & 0x0080)==RESET);
}

void UART2_SendString(char *data)
{
	while(*data)
	{
		UART2_SendChar(*data);
		data++;
	}
}

void UART2_SendByte(uint8_t *data, uint8_t sizes)
{
	uint8_t i;
	for(i=0; i<sizes; i++)
	{
		USART2->DR = (data[i] & 0x00FF);
		while((USART2->SR & 0x0080)==RESET);
	}
}
	 
void INIT_UART_3(unsigned int BaudRates)
{
	RCC->APB2ENR |= 0x00000008;
	GPIOB->CRH	|= 0x00004B00;
	RCC->APB1ENR |= 0x00040000;
	USART3->BRR = ((((SystemCoreClock/(BaudRates*2))/16)<<4)+((SystemCoreClock/(BaudRates))%16));
	USART3->CR1 |= (USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE); 			 
	NVIC_EnableIRQ(USART3_IRQn);
	USART3->CR1 |= USART_CR1_UE;
}

void UART3_SendChar(char data)
{
	USART3->DR = (data & 0x00FF);
	while((USART3->SR & 0x0080)==RESET);
}

void UART3_SendString(char *data)
{
	while(*data)
	{
		UART3_SendChar(*data);
		data++;
	}
}

void USART1_IRQHandler(void) 
{
	char temp_data;
	if ((USART1->SR & USART_SR_RXNE) != 0) 
	{
		temp_data = USART1->DR;
		if(temp_data != '\n')
		{
			Array1_Receive[Count1_Data] = temp_data;
			Count1_Data++;
		}
		else
		{
			Array1_Receive[Count1_Data] = 0;
			Flag1_Receive = 1;
			Count1_Data = 0;
		}
	}
}

void USART2_IRQHandler(void) 
{
	char temp_data;
	if ((USART2->SR & USART_SR_RXNE) != 0) 
	{
		temp_data = USART2->DR;
		if(temp_data != '\n')
		{
			Array2_Receive[Count2_Data] = temp_data;
			Count2_Data++;
		}
		else
		{
			Array2_Receive[Count2_Data] = 0;
			Flag2_Receive = 1;
			Count2_Data = 0;
		}
	}
}

//void USART2_IRQHandler(void) {
//	char temp_data;
//	if ((USART2->SR & USART_SR_RXNE) != 0) 
//	{
//		temp_data = USART2->DR;
//		Array2_Receive[Count2_Data] = temp_data;
//		Count2_Data++;
//		
//		if(Count2_Data >= 9)
//		{
//			Array2_Receive[Count2_Data] = 0;
//			Flag2_Receive = 1;
//			Count2_Data = 0;
//		}
//	}
//}

void USART3_IRQHandler(void) 
{
	char temp_data;
	if ((USART3->SR & USART_SR_RXNE) != 0) 
	{
		temp_data = USART3->DR;
		if(temp_data != '\n')
		{
			Array3_Receive[Count3_Data] = temp_data;
			Count3_Data++;
		}
		else
		{
			Array3_Receive[Count3_Data] = 0;
			Flag3_Receive = 1;
			Count3_Data = 0;
		}
	}
}

struct __FILE {
 int dummy;
};
FILE __stdout;
int fputc(int ch, FILE *f) {
	UART1_SendChar(ch);
//	UART2_SendChar(ch);
//	UART3_SendChar(ch);
 return ch;
}


/********************************* END OF FILE ********************************/
/******************************************************************************/
