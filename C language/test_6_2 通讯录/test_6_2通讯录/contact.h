#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NAME 20
#define SEX 10
#define MAX 100
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

//ͨѶ¼
struct peoinfo
{
	char name[NAME];
	int  age;
	char sex[SEX];
	int  high;
};

typedef struct contact
{
	struct peoinfo data[MAX];
	int count;
}contact;


//��ʼ��ͨѶ¼
void Init_contact(contact* pc);



//����ͨѶ¼
void add_contact(contact* con);


//չʾͨѶ¼
void show_contact(contact* con);


//ɾ��ͨѶ¼
void del_contact(contact* con);

//����ͨѶ¼
void sear_contact(contact* con);


//�޸�ͨѶ¼
void mod_contact(contact* con);


//����
void sort_contact(contact* con);
