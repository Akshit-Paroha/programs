#include <stdio.h>

int main() 
{
    int number = 10;
    int *ptr; // Declare a pointer to an integer

    ptr = &number; // Assign the address of 'number' to the pointer

    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", &number);
    printf("Value stored in pointer ptr: %p\n", ptr);
    printf("Value pointed to by ptr: %d\n", *ptr);

    return 0;
}
