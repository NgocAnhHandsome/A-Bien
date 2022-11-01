#include "stm8s.h"
#include "uart.h"
#include "LCD.h"


int main( void )
{
  LCD_Init();
  delay_ms(200);
  LCD_Gotoxy(0,0);
  LCD_Puts("KT VI XU LY-PTIT");
  LCD_Gotoxy(0,1);
  LCD_Puts("KT VI XU LY-PTIT");
  delay_ms(10);
  while (1)
  {

  }
}