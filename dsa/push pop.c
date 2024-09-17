#include<stdio.h>
int main()
{
    int i,choice,top,max,x,n,stack;
    top=-;
    printf("Enter stack size:")
    scanf("%d",&n);
    do{
    printf("Enter your choice:");
    scanf("%d",&choice);
    printf("1.Push the element\n2.pop the element\n3.Display\n4.exit");
    switch (choice)
    {
    case 1:
    {
        void push();
        break;
    }
    case 2:
    {
        void pop();
        break;
    }
    case 3:
    {
        void display();
        break;
    }
    case 4:
    {
        break;
    }

    
    default:
    {
        printf("ENTER PROPPER CHOICE!!!");
    }}
        break;
    }

}