#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NAME 20
#define SEX 10
#define MAX 100
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

//通讯录
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


//初始化通讯录
void Init_contact(contact* pc);



//增加通讯录
void add_contact(contact* con);


//展示通讯录
void show_contact(contact* con);


//删除通讯录
void del_contact(contact* con);

//查找通讯录
void sear_contact(contact* con);


//修改通讯录
void mod_contact(contact* con);


//排序
void sort_contact(contact* con);
