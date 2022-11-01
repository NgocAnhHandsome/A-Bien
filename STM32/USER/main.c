#include "stm32f10x.h"                  // Device header
#include "uart.h" 
#include "device_command.h"

char Temp_data[60];
void delay(uint16_t i);

int main()
{
	INIT_UART_1(9600);
//	INIT_UART_2(9600);
//	_comm_data_struct_create_t test;
//	test.port_number = COMM_Port2;
//	test.type_msg    = COMM_AskType;
//	comm_create_command(&test);
//	UART2_SendString(test.datastr);
	while(1)
	{
		delay(500);
			UART1_SendString("**");
//		if(Flag2_Receive)
//		{
//			Flag2_Receive = 0;
//			UART1_SendString(Array2_Receive);
//			UART1_SendString("\n");
//		}
	}
}

void delay(uint16_t i)
{
	while(i--)
	{
		for(uint16_t j = 0; j < 0x2aff; j++);
	}
}
