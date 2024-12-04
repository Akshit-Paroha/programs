#include <stdio.h>
int main()
{
    int a[5] = {12, 54, 37, 15, 60};
    int i, j, temp;
    int n = 5;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Your sorted array is:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}