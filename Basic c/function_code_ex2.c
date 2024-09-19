#include <stdio.h>
int sum(int a,int b)
{
    return a+b;
}

int main()
{
    int a=10,b=32,c;
    c = sum(a,b);
    printf("the value of c=%d",c)
    return 0;
}
