#include <stdio.h>

#define DAYS_IN_WEEK 7

int main()
 {
    float temperatures[DAYS_IN_WEEK];

    printf("Enter the temperatures for the week:\n");
    for (int i = 0; i < DAYS_IN_WEEK; i++) 
    {
        printf("Enter temperature for day %d: ", i + 1);
        scanf("%f", &temperatures[i]);
    }

    printf("\nTemperatures for the week:\n");
    for (int i = 0; i < DAYS_IN_WEEK; i++) 
    {
        printf("Day %d: %.2f\n", i + 1, temperatures[i]);
    }

    return 0;
}
