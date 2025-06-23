#include<stdio.h>
int cmp(const void* e1,const void* e2)
{
	return(*(int*)e1 - *(int*)e2);
}

void Swap(char* buf1, char* buf2, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}

}

void My_qsort(void*base,int num,int width,int(*cmp)(const void*e1,const void*e2))
{
	int i = 0;
	for (i = 0; i < num-1; i++)
	{
		//Ò»ÌËÃ°ÅÝÅÅÐò
		int j = 0;
		for (j = 0; j < num-1-i; j++)
		{
			if (cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}

		}

	}

}




int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sze = sizeof(arr) / sizeof(arr[0]);
	My_qsort(arr, sze,sizeof(arr[0]),cmp);
	int i = 0;
	for (i = 0; i < sze; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}