/*
 * myLib.c
 *
 *  Created on: Nov 15, 2024
 *      Author: user
 */
#include "main.h"
#include <stdio.h>

extern UART_HandleTypeDef huart2;

int __io_getchar(void)
{
   char ch;
   while(HAL_UART_Receive(&huart2, &ch, 1, 10) != HAL_OK);
   HAL_UART_Transmit(&huart2, &ch, 1, 10);   //Echo
   if(ch == '\r')
      HAL_UART_Transmit(&huart2, "\n", 1, 10);
   return ch;

}

int __io_putchar (int ch)//lowest output function, 문자 ?��?�� ?�� 받음 그것?�� uart�??? 출력
{
  HAL_UART_Transmit (&huart2, &ch, 1, 10);
  //HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout)
  //					      ?��?�� usart?���???,      문자?��?�� ?��?�� 버퍼?�� ?��?��?��?���???, ?��료형 size, ?��?�� ?���???-보통 10ms?�� ?��걸림 9600 ~= 1k
  // 1ms sec but set roughly 10ms

  return ch;
}

void
StandBy ()
{
  while (HAL_GPIO_ReadPin (B1_GPIO_Port, B1_Pin));
}

void
ProgramStart (char *str)
{
  cls();
  Cursor(0, 0);
  printf ("Program Name - %s\r\n", str);
  printf ("Press Blue-button(B1) to Start...\r\n");
  StandBy ();
  setvbuf(stdin, NULL, _IONBF, 0);   //scanf buffer clear
}

void cls()
{
  printf("\033[2J");
}
void Cursor(int x, int y)
{
  char buf[20];
  sprintf(buf,"\033[%d;%dH", y, x);
  puts(buf);
}


