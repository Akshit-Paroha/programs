#include <stdio.h>

int main()
{
    int key;
    int i = 0;
    int a[5] = {20, 50, 15, 10, 30};
    printf("Enter element to search:");
    scanf("%d", &key);
    while (a[i] != key)
    {
        i++;
    }
    printf("Your element was found at %d",i+1);
}