#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0;
    int i=0;
   //提供一个1~100之间的数
    for(i=1;i<=100;i++)
    {
        a=i*3;
        printf("%d ",a);
    }
    return 0;
}
