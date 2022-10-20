#include "stm8s.h"
#include "uart.h"
#include "i2c.h"
#include "sht30.h"
#include "sys.h"
#include "device_command.h"

int i,j,k,n;

_comm_type_command_e Type_command_arr[] = {COMM_AskType, COMM_AnswerType, COMM_AskData, COMM_AnswerData};

_comm_port_number_e Port_number_arr[] = {COMM_Port1, COMM_Port2,COMM_Port3,COMM_Port4,
																		COMM_Port5, COMM_Port6,COMM_Port7,COMM_Port8};
_comm_type_sensor_e Type_sensor_arr[] = {Sensor_1,Sensor_2, Sensor_3};

_comm_data_sensor_t sensor = {1.2, 3.5, 2.6, 2.7, 3.6, 7.6, 2.1, 4.4, 5.6, 2.5, 3.7, 1.9, 7.5, 2.1, 5.7};

						
_comm_data_struct_create_t test;
_comm_data_struct_detect_t detect_test;



char Temp_data[100];
void delay(uint16_t i);

void Show_detect(_comm_data_struct_detect_t detect_test);

int main( void )
{
  UART_Init(9600);
  UART_Send_String("PTIT\n");

  for(i = 0; i < 4;i++)
  {
          for(j = 0; j < 8; j++)
          {
                  for(k = 0; k < 3; k++)
                  {
                          test.type_msg = Type_command_arr[i];
                          test.port_number = Port_number_arr[j];
                          test.type_sensor = Type_sensor_arr[k];
                          test.Sensor.Sensor_1      = 1.42;
                          if(comm_create_command(&test) == COMM_OK)
                          {
                                  UART_Send_String(test.datastr);
                          }
                          else
                          {
                                  UART_Send_String("Error\n");
                          }
                          delay(100);
                  }
          }
  }


  while (1)
  {
    
  }
}


void Show_detect(_comm_data_struct_detect_t detect_test)
{
	switch(detect_test.type_msg)
	{
		case COMM_AskType:
			UART_Send_String("COMM_AskType\n");
			break;
		case COMM_AnswerType:
			UART_Send_String("COMM_AnswerType\n");
			break;	
		case COMM_AskData:
			UART_Send_String("COMM_AskData\n");
			break;		
		case COMM_AnswerData:
			UART_Send_String("COMM_AnswerData\n");
			break;
		default:
			break;
	}
	switch(detect_test.port_number)
	{
		case COMM_Port1:
			UART_Send_String("COMM_Port1\n");
			break;
		case COMM_Port2:
			UART_Send_String("COMM_Port2\n");
			break;
		case COMM_Port3:
			UART_Send_String("COMM_Port3\n");
			break;
		case COMM_Port4:
			UART_Send_String("COMM_Port4\n");
			break;
		case COMM_Port5:
			UART_Send_String("COMM_Port5\n");
			break;
		case COMM_Port6:
			UART_Send_String("COMM_Port6\n");
			break;
		case COMM_Port7:
			UART_Send_String("COMM_Port7\n");
			break;
		case COMM_Port8:
			UART_Send_String("COMM_Port8\n");
			break;
		default:
			break;
	}
	switch(detect_test.type_sensor)
	{
		case Sensor_1:
			UART_Send_String("Sensor_1\n");
			break;
		case Sensor_2:
			UART_Send_String("Sensor_2\n");
			break;
		case Sensor_3:
			UART_Send_String("Sensor_3\n");
			break;
		default:
			break;
	}
        
//	UART_Send_String(conver_floatTostr(detect_test.Sensor.Sensor_1,4));
//        UART_Send_String("\n");
//	sprintf(s,"Sensor_2: %f\n", detect_test.Sensor.Sensor_2);
//	UART_Send_String(s);
//	sprintf(s,"Sensor_3: %f\n", detect_test.Sensor.Sensor_3);
//	UART_Send_String(s);
//	sprintf(s,"Sensor_4: %f\n", detect_test.Sensor.Sensor_4);
//	UART_Send_String(s);
//	sprintf(s,"Sensor_5: %f\n", detect_test.Sensor.Sensor_5);
//	UART_Send_String(s);
//	sprintf(s,"Sensor_5: %f\n", detect_test.Sensor.Sensor_6);
//	UART_Send_String(s);
//	sprintf(s,"Sensor_7: %f\n", detect_test.Sensor.Sensor_7);
//	UART_Send_String(s);
//	sprintf(s,"Sensor_8: %f\n", detect_test.Sensor.Sensor_8);
//	UART_Send_String(s);
//	sprintf(s,"Sensor_9: %f\n", detect_test.Sensor.Sensor_9);
//	UART_Send_String(s);
//	sprintf(s,"Sensor_10:%f\n", detect_test.Sensor.Sensor_10);
//	UART_Send_String(s);
//	sprintf(s,"Sensor_11:%f\n", detect_test.Sensor.Sensor_11);
//	UART_Send_String(s);	
//	sprintf(s,"Sensor_12:%f\n", detect_test.Sensor.Sensor_12);
//	UART_Send_String(s);	
//	sprintf(s,"Sensor_13:%f\n", detect_test.Sensor.Sensor_13);
//	UART_Send_String(s);
//	sprintf(s,"Sensor_14:%f\n", detect_test.Sensor.Sensor_14);
//	UART_Send_String(s);	
//	sprintf(s,"Sensor_15:%f\n", detect_test.Sensor.Sensor_15);
//	UART_Send_String(s);		
}

void delay_ms(int a)
{
  for (int i = 0; i < a; i++)
    for (int index = 0; index < 400; index++);
}