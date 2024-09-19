/*The following program could be used to peform basic mathematical operations in C programming language
this code is developed by Akshit paroha
last date modified- 22/4/23 */
#include<stdio.h>
int main(int argc, char const *argv[])
{
    float a,b;
    printf("value of a:");
    scanf ("%f",&a);
    printf("value of b:");
    scanf ("%f",&b);
    printf("a+b=%f\n",a+b);
    printf("a-b=%f\n",a-b);
    printf("b-a=%f\n",b-a);
    printf("axb=%f\n",a*b);
    printf("a/b=%f\n",a/b);
    printf("b/a=%f\n",b/a);

    return 0;
}