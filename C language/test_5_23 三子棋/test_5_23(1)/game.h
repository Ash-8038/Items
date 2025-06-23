#pragma once
#define Row 3//数组行的定义
#define Col 3//数组列的定义
#include<stdlib.h>
#include<time.h>
//初始化棋盘的声明
void initialize_board(int arr[Row][Col],int row,int col);
//打印棋盘
void print_board(char arr[Row][Col], int row, int col);
//玩家下棋
void player_board(char arr[Row][Col], int row, int col);
//电脑下棋
void computure_board(char arr[Row][Col], int row, int col);
//判断是否获胜
//玩家赢了return*
//电脑赢了return#
//平局return c
//继续return m
char is_win(char arr[Row][Col], int row, int col);