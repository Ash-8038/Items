#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_ShowString(unsigned char line,unsigned char low,unsigned char* String);
void LCD_SHOWsignedNum(unsigned char line,unsigned char low,int Num,unsigned char length);
void LCD_Write_INIT();

#endif