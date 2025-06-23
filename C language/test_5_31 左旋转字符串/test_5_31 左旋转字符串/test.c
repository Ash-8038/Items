#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void left_rotate(char* arr, int i, int sz)
{
	int j = 0;
	for (j = 0; j < i; j++)
	{
		//Ðý×ªÒ»¸ö×Ö·û
		char temp = *arr;
		int num = 0;
		for (num = 0; num < sz-1; num++)
		{
			*(arr+num) = *(arr +num+1);
		}
		*(arr + sz - 1) = temp;


	}


	return 0;
}
int main()
{
	char arr[20];
	gets(arr);
	int i = 0;
	scanf("%d", &i);
	int sz = strlen(arr);
	left_rotate(arr, i, sz);
	printf("%s", arr);


	return 0;
}