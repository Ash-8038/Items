#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define ROW  9
#define COL  9
#define ROWS ROW+2
#define COLS COL+2
#define boom 10
#include<stdlib.h>
#include<time.h>

#include<stdio.h>
//��ʼ������
void Init_board(char board[ROWS][COLS], int row, int col, char set);
//��ӡ����
void Display_board(char board[ROWS][COLS], int row, int col);
//����
void Make_boom(char board[ROWS][COLS], int row, int col);
//����
void Play_board(char mine[ROWS][COLS], char show [ROWS][COLS], int row, int col);