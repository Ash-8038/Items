#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	scanf_s("%d %d", &a, &b);
	int max = 0;
	int min = 0;
	if (a >= b)
	{
		max = a;
		min = b;

	}
	else
	{
		max = b;
		min = a;
	}
		int i = 0;
	for (i = 1; i < max; i++)
	{
		if ((max % i == 0) &&( min % i == 0))
		{
			printf("%d", i);
			break;
		}
	}
	return 0;
}