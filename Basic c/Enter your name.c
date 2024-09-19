#include<stdio.h>
int main(int argc, char const *argv[])
{
    char str[50];
    printf("Please enter your name:");
    gets(str);
    printf("\n\n\t\t Welcome %s ",str);
    return 0;
}
