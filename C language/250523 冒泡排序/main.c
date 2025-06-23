#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[],int sze)
 {
     int i=0;
    for(i=0;i<sze-1;i++)
    {
        int j=0;
        for(j=0;j<sze-1-i;j++)
        {
            int mid=0;
            if(arr[j]>arr[j+1])
               {
                   mid=arr[j+1];
                   arr[j+1]=arr[j];
                   arr[j]=mid;
               }
        }
    }
}

int main()
{
   int arr[10]={2,3,5,3,4,6,7,8,9,1};
   int sze=sizeof(arr)/sizeof(arr[0]);
   bubble_sort(arr,sze);
   int i=0;
   for(i=0;i<sze;i++)
   {
      printf("%d",arr[i]);
   }


    return 0;
}
