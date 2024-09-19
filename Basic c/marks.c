#include<stdio.h>
int main()
{
    int marks;
    printf("Please enter your marks:");
    scanf("%d",&marks);
    marks = (marks<=35)?(35):(marks<=50)?(50):(marks<=80)?(80):(marks<=90)?(90):(91);
    switch(marks)
    {
        case 35: printf("You Failed dumbass");break;
        case 50: printf("Passed");break;
        case 80: printf("Well Done");break;
        case 90: printf("excelent");break;
        case 91: printf("outstanding");break;
        default: printf("incorrect value");break;
        
    }
    return 0;
}