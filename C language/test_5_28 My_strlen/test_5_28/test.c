#include<stdio.h>

int My_strlen(char* p)
{
	int count = 0;
	while (*p)
	{
		count++;
		p++;
		
	}
	return count;
}


int main()
{
	char arr[100];
	gets(arr);
	int ret=My_strlen(arr);
	printf("%d", ret);
	return 0;
}