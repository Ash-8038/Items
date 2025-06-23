#include <stdio.h>
#include <stdlib.h>

int main()
{
     int der=0;
    int i=0;
    for(i=100;i<=200;i++)
   {

      int flag=1;
       for(der=2;der<=i-1;der++)
       {
           if(i%der==0)
            {
                flag=0;
           break;
            }
       }
       if(flag==1)
            printf("%d ",i);
   }
    return 0;
}
