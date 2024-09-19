#include<stdio.h>
void wrt_very(int count)
{
    while(count>0)
    {
        printf("very ");
        count=count-1;//count--
        
    };
    printf("strong");
}
int main(void)
{
    int repeat=0;
    printf("How strong are you 0-10:");
    scanf("%d",&repeat);
    printf("you are ");
    wrt_very(repeat);
    return 0;
    
}