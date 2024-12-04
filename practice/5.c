#include<stdio.h>
int main()
{
    int a[5]={12,57,34,10,50};
    int i,j,min,temp;

    for (i = 0; i < 5; i++)
    {
        min = i;
        for(j=i+1;j<5;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("Your sorted array is:");
    for (i = 0; i < 5; i++)
    {
        printf("%d\t", a[i]);
    }
}