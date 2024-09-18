#include<stdio.h>

void enqueue();
void dequeue();
void display();

int front=-1,rear=-1,n,i,choice,x;
int Q[10];
int main()
{


    printf("Title: Circular queue (practical 10)\n");

    printf("Enter size for your queue:");
    scanf("%d",&n);
    int Q[n];

    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.display\n4.exit\n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;

        default:
            printf("Enter vaild choice!!");
            break;
        }   
    } while (choice != 4);   
}



void enqueue()
{
    
    if (front==(rear+1)%n)
    {
        printf("queue is overflow!!");
    }
    else
    {
        
        printf("Enter element to be enqueued:");
        scanf("%d",&x);
        rear=(rear+1)%n;
        Q[rear]=x;
    }
        if (front==-1)
        {
            front=0;
        }
        
    
    
}

void dequeue()
{
    
    if ((front==rear) && (rear==-1))
    {
        printf("Queue is underflow");
    }
    else
    {
        x=Q[front];
        if (front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%n;    
        }
        printf("Deleted %d",Q[front]);
    }
}

void display()
{
    
    if (front==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Your queue is:");
        for (i = front; i!=rear;i=((i+1)%n))
        {
            printf("\t%d",Q[i]);
        }
        printf("\t%d",Q[rear]);
       
    }
    
    
}