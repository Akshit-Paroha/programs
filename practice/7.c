#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    stack[top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("\t%d\n", stack[i]);
    }
}

int main()
{
    push(10);
    push(30);
    push(20);
    printf("Element popped is: %d\n", pop());
    display();
    return 0;
}
