#pragma once
#define Row 3//�����еĶ���
#define Col 3//�����еĶ���
#include<stdlib.h>
#include<time.h>
//��ʼ�����̵�����
void initialize_board(int arr[Row][Col],int row,int col);
//��ӡ����
void print_board(char arr[Row][Col], int row, int col);
//�������
void player_board(char arr[Row][Col], int row, int col);
//��������
void computure_board(char arr[Row][Col], int row, int col);
//�ж��Ƿ��ʤ
//���Ӯ��return*
//����Ӯ��return#
//ƽ��return c
//����return m
char is_win(char arr[Row][Col], int row, int col);