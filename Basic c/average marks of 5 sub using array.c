#include <stdio.h>

#define SIZE 5

void getGrades(float grades[]) 
{
    printf("Enter the value of 1st subject: ");
    scanf("%f", &grades[0]);

    printf("Enter the value of 2nd subject: ");
    scanf("%f", &grades[1]);

    printf("Enter the value of 3rd subject: ");
    scanf("%f", &grades[2]);

    printf("Enter the value of 4th subject: ");
    scanf("%f", &grades[3]);

    printf("Enter the value of 5th subject: ");
    scanf("%f", &grades[4]);
}

int main(void)
{
    float grades[SIZE];
    float sum = 0.0;
    int i;

    getGrades(grades);

    printf("\nYour grades are: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%.2f ", grades[i]);
        sum += grades[i]; 
    }

    printf("\n\n\nAverage grade is: %.2f\n", sum / SIZE);

    return 0;
}
