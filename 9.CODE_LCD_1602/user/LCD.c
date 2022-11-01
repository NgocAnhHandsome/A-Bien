#include "LCD.h"

void delay_ms(int a)
{
  for (int i = 0; i < a; i++)
    for (int index = 0; index < 400; index++);
}

void GPIO_LCD_Config(void)
{
  GPIO_Init(PORTSET, (GPIO_Pin_TypeDef)PINSET, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(PORTDATA, (GPIO_Pin_TypeDef)PINDATA, GPIO_MODE_OUT_PP_LOW_FAST);
}

void LCD_Enable(void)
{
  EN_Set;
  delay_ms(3);
  EN_ReSet;
  delay_ms(5); 
}

void LCD_Send4Bit(unsigned char Data)
{
  
  if((Data & 0x01))
  {
    GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
  }
  else
  {
    GPIO_WriteLow(GPIOC,GPIO_PIN_4);
  }
  
  if(((Data>>1) & 0x01))
  {
    GPIO_WriteHigh(GPIOC,GPIO_PIN_5);
  }
  else
  {
    GPIO_WriteLow(GPIOC,GPIO_PIN_5);
  }
  
  if(((Data>>2) & 0x01))
  {
    GPIO_WriteHigh(GPIOC,GPIO_PIN_6);
  }
  else
  {
    GPIO_WriteLow(GPIOC,GPIO_PIN_6);
  }
  
  if(((Data>>3) & 0x01))
  {
    GPIO_WriteHigh(GPIOC,GPIO_PIN_7);
  }
  else
  {
    GPIO_WriteLow(GPIOC,GPIO_PIN_7);
  }
  
  
  
}

void LCD_SendCommand(unsigned char command)
{
  LCD_Send4Bit(command >> 4);
  LCD_Enable();
  LCD_Send4Bit(command);
  LCD_Enable();
  
}

void LCD_Clear()
{
  LCD_SendCommand(0x01);
  delay_ms(10);
}

void LCD_Init()
{
  GPIO_LCD_Config();
  
  delay_ms(20);
  LCD_Send4Bit(0x00);
  delay_ms(20);
  RS_ReSet;
  RW_ReSet ;
  LCD_Send4Bit(0x03);
  LCD_Enable();
  delay_ms(5);
  LCD_Enable();
  delay_ms(1);
  LCD_Enable();
  LCD_Send4Bit(0x02);
  LCD_Enable();
  LCD_SendCommand( 0x28 ); // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
  LCD_SendCommand( 0x0c); // cho phep hien thi man hinh
  LCD_SendCommand( 0x06 ); // tang ID, khong dich khung hinh
  LCD_SendCommand(0x01); // xoa toan bo khung hinh
  
}

void LCD_Gotoxy(unsigned char x, unsigned char y)
{
  unsigned char address;
  if(y == 0)
    address=(0x80+x);
  else if(y == 1)
    address=(0xc0+x);
  delay_ms(1);
  LCD_SendCommand(address);
  delay_ms(50);
}

void LCD_PutChar(unsigned char Data)
{
  RS_Set;
  LCD_SendCommand(Data);
  RS_ReSet;
}

void LCD_Puts(char *s)
{
  while (*s)
  {
    LCD_PutChar(*s);
    s++;
  }
}
