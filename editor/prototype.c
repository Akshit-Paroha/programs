#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 52

struct Node
{
    int data;
    struct Node *next;
};

int stack[STACK_SIZE];
int top = -1;

void insertAtEnd(struct Node **head, int data);
void displayHiddenList(struct Node *head);
void displayList(struct Node *head);
int pickCardFromEnd(struct Node *head);
void insertAtPosition(struct Node **head, int data, int position);
void deleteFromEnd(struct Node **head);
int getListLength(struct Node *head);
void push(int data);
void displayStack();

int main()
{
    struct Node *head = NULL;
    int position1, position2, picked1, picked2;
    char choice;

    int numbers[] = {2, 2, 3, 4, 5, 6, 7, 9, 9, 11, 11, 12, 13,
                     1, 1, 3, 4, 5, 6, 7, 8, 8, 10, 10, 12, 13,
                     1, 3, 3, 5, 5, 6, 6, 8, 9, 11, 11, 12, 12,
                     1, 2, 2, 4, 4, 7, 7, 8, 9, 10, 10, 13, 13};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < n; i++)
    {
        insertAtEnd(&head, numbers[i]);
    }

    while (getListLength(head) > 0)
    {
        printf("\nHidden List: ");
        displayHiddenList(head);
        printf("Remaining cards: %d\n", getListLength(head));

        printf("\nDo you want to pick the first card from the end? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            picked1 = pickCardFromEnd(head);
            printf("You picked: %d\n", picked1);
            deleteFromEnd(&head);
        }
        else
        {
            printf("Skipping the pick.\n");
            continue;
        }

        printf("\nDo you want to pick the second card from the end? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            picked2 = pickCardFromEnd(head);
            printf("You picked: %d\n", picked2);
            deleteFromEnd(&head);
        }
        else
        {
            printf("Skipping the pick.\n");
            continue;
        }

        if (picked1 == picked2)
        {
            printf("\nMatched! Pushing %d onto the stack twice.\n", picked1);
            push(picked1);
            push(picked2);
        }
        else
        {
            printf("\nNot matched! Reinsert the cards back into the list.\n");
            printf("Enter the position to reinsert the first card (%d): ", picked1);
            scanf("%d", &position1);
            insertAtPosition(&head, picked1, position1);

            printf("Enter the position to reinsert the second card (%d): ", picked2);
            scanf("%d", &position2);
            insertAtPosition(&head, picked2, position2);
        }

        printf("\nRevealed Stack: ");
        displayStack();
    }

    printf("\nAll cards have been matched and revealed. Game over!\n");

    printf("\nFinal List: ");
    displayList(head);
    return 0;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayHiddenList(struct Node *head)
{
    while (head != NULL)
    {
        printf("[*] -> ");
        head = head->next;
    }
    printf("NULL\n");
}

void displayList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int pickCardFromEnd(struct Node *head)
{
    struct Node *temp = head;
    if (!temp)
        return -1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}

void insertAtPosition(struct Node **head, int data, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range. Inserting at the end.\n");
        insertAtEnd(head, data);
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;
    if (temp->next == NULL)
    {
        *head = NULL;
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void push(int data)
{
    if (top < STACK_SIZE - 1)
    {
        stack[++top] = data;
    }
    else
    {
        printf("Stack is full. Cannot push %d.\n", data);
    }
}

void displayStack()
{
    if (top == -1)
    {
        printf("Empty\n");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int getListLength(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}