#include<stdio.h>

int main()
{
    printf("Title: binary search(practical 3)\n\n");
    int low,high,mid,i,val,pos=-1,a[5];
    for ( i = 0; i < 5; i++)
    {
        printf("Enter your array element %d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nEnter element to search:");
    scanf("%d",&val);
    low=0,high=5-1;
    mid=(low+high)/2;
    while (low<high)
    {
        if (a[mid]<val)
        {
            low=mid+1;
        }
        else if(a[mid]==val)
        {
            pos=mid;
            printf("\nelement found at: %d",pos+1);
            break;
        }
        else
        {
            high=mid-1;
        }
        mid=(low+high)/2;  
    }
    if (pos==-1)
    {
        printf("\nelement not found in the array");
    }
    
    return 0;
    
}