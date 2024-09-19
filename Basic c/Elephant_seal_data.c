#include <stdio.h>

#define SIZE 5

void getWeight(int Weight[])
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("Weight of the elephant seal %d:",i + 1);
        scanf("%d", &Weight[i]);
    }
    
}

int main (void)
{
    int Weight[SIZE];
    int sum = 0.0;
    int i;

    getWeight(Weight);

    printf("\n\n\nThe weight of the elephants seals are: ");
    for ( i = 0; i < SIZE; i++)
    {
        printf("\t%d",Weight[i]);
        sum += Weight[i];
    }

    printf("\n\n\nAverage Weight of the elephants seals is: %d\n",sum/SIZE);

    return 0;
}