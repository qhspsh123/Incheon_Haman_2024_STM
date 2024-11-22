/*
 * myLib.c
 *
 *  Created on: Nov 15, 2024
 *      Author: user
 */
#include "main.h"
#include "C:\Users\user\STM32Cube\Repository\STM32Cube_FW_F4_V1.28.1\Drivers\STM32F4xx_HAL_Driver\Inc\stm32f4xx_hal_i2c.h"
extern UART_HandleTypeDef huart2;



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





