#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void begin_insert();
void last_insert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main()
{
    int choice;
    while (choice != 9)
    {
        printf("\n\n__Main Menu_\n");
        printf("\nChoose one option from the list !");
        printf("\n-------------------------------------------------");
        printf("\n1.Inserting at beginning");
        printf("\n2.Inserting at end");
        printf("\n3.Inserting at given position");
        printf("\n4.Deletion at beginning");
        printf("\n5.Deletion at end");
        printf("\n6.Deletion at given position");
        printf("\n7.Search for an element");
        printf("\n8.Display");
        printf("\n9.Exit\n");

        printf("\nEnter your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            begin_insert();
            break;
        case 2:
            last_insert();
            break;
        case 3:
            random_insert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            break;
        default:
            printf("\nPlease enter a valid choice!\n");
        }
    }
}

void begin_insert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node)); // Casting malloc to struct node*

    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode Inserted");
    }
}

void last_insert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node)); // Casting malloc to struct node*

    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Value: ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("\nNode Inserted");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNode Inserted");
        }
    }
}

void random_insert()
{
    int i, loc, item;
    struct node *ptr;
    struct node *temp = head;
    ptr = (struct node *)malloc(sizeof(struct node)); // Casting malloc to struct node*

    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Value: ");
        scanf("%d", &item);
        ptr->data = item;
        printf("\nEnter location to insert: ");
        scanf("%d", &loc);

        loc--;
        while (loc != 1)
        {
            temp = temp->next;
            loc--;
        }

        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode Inserted!!\n\n");
    }
}

void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode Deleted From The Beginning!!\n");
    }
}

void last_delete()
{
    struct node *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly Node Of List Deleted!!\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node From The Last\n");
    }
}

void random_delete()
{
    struct node *ptr, *ptr1;
    int loc, i;
    printf("\nEnter location after which you want to perform deletion: ");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("\nCan't Delete\n");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d\n", loc + 1);
}

void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nList is empty!!\n");
    }
    else
    {
        printf("\nEnter element which you want to search: ");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("Item found at location %d\n", i + 1);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Item not found!!\n");
        }
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nNothing to print\n");
    }
    else
    {
        printf("\nPrinting values ......\n");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}