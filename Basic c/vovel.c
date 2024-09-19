#include<stdio.h>
int main()
{
    char ch;
    printf("Please enter a letter:");
    scanf("%c",&ch);
    switch (ch)
    {
        case 'a':printf("a is a vovel");break;
        case 'e':printf("e is a vovel");break;
        case 'i':printf("i is a vovel");break;
        case 'o':printf("o is a vovel");break;
        case 'u':printf("u is a vovel");break;
        default :printf("%c is not a vovel",ch);break;
    }
    return 0;
    
}