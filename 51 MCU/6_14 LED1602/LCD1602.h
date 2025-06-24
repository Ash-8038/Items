#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_Write_INIT();
void LCD_ShowChar(unsigned char line,unsigned char low,unsigned char Char);
void LCD_ShowString(unsigned char line,unsigned char low,unsigned char* String);
void LCD_ShowNum(unsigned char line,unsigned char low,unsigned char Num,unsigned char length);
void LCD_SHOWsignedNum(unsigned char line,unsigned char low,int Num,unsigned char length);
#endif