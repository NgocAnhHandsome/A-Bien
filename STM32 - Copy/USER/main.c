#include "define.h"

_comm_type_command_e Type_command_arr[] = {COMM_AskType, COMM_AnswerType, COMM_AskData, COMM_AnswerData};

_comm_port_number_e Port_number_arr[] = {COMM_Port1, COMM_Port2,COMM_Port3,COMM_Port4,
																		COMM_Port5, COMM_Port6,COMM_Port7,COMM_Port8};
_comm_type_sensor_e Type_sensor_arr[] = {Sensor_1,Sensor_2, Sensor_3};

_comm_data_sensor_t sensor = {1.2, 3.5, 2.6, 2.7, 3.6, 7.6, 2.1, 4.4, 5.6, 2.5, 3.7, 1.9, 7.5, 2.1, 5.7};

						
_comm_data_struct_create_t test;
_comm_data_struct_detect_t detect_test;



char Temp_data[100];
void delay(uint16_t i);
void Config(void);
void Test_Input(void);

void Config(void);

int main()
{
	INIT_UART_2(9600);
	INIT_UART_1(9600);
	Config();
	UART1_SendString("TEST: \n");
	SET_GPIO_PORT_Init();
	GET_GPIO_PORT_Init();
//	GPIO_SetBits(GPIOB, SET_GPIO_PORTB_1);
//	GPIO_SetBits(GPIOB, SET_GPIO_PORTB_2);
//	GPIO_SetBits(GPIOB, SET_GPIO_PORTB_3);
//	GPIO_SetBits(GPIOB, SET_GPIO_PORTB_4);
//	GPIO_SetBits(GPIOA, SET_GPIO_PORTA_5);
//	GPIO_SetBits(GPIOA, SET_GPIO_PORTA_6);
	while(1)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		UART2_SendString("TEST: \n");
		delay(1000);
 	}
} 

void Test_Input(void)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
{
	char s[10];
	sprintf(s, "PORTB_1: %d\n", GPIO_ReadInputDataBit(GPIOB, GET_GPIO_PORTB_1));
	UART1_SendString(s);
	sprintf(s, "PORTB_2: %d\n", GPIO_ReadInputDataBit(GPIOB, GET_GPIO_PORTB_2));
	UART1_SendString(s);
	sprintf(s, "PORTB_3: %d\n", GPIO_ReadInputDataBit(GPIOB, GET_GPIO_PORTB_3));
	UART1_SendString(s);
	sprintf(s, "PORTB_4: %d\n", GPIO_ReadInputDataBit(GPIOB, GET_GPIO_PORTB_4));
	UART1_SendString(s);
	sprintf(s, "PORTB_5: %d\n", GPIO_ReadInputDataBit(GPIOB, GET_GPIO_PORTB_5));
	UART1_SendString(s);
	sprintf(s, "PORTB_5: %d\n", GPIO_ReadInputDataBit(GPIOB, GET_GPIO_PORTB_6));
	UART1_SendString(s);
}

void delay(uint16_t i)
{
	while(i--)
	{
		for(uint16_t j = 0; j < 0x2aff; j++);
	}
}


void Config(void)
{
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin  = GPIO_Pin_4;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio);
}

