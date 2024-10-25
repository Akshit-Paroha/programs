#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Stack structure
int stack[STACK_SIZE];
int top = -1;

// Function prototypes
void insertAtEnd(struct Node **head, int data);
void displayHiddenList(struct Node *head);
void displayList(struct Node *head);
int pickCard(struct Node *head, int position);
void insertAtPosition(struct Node **head, int data, int position);
void deleteFromPosition(struct Node **head, int position);
int getListLength(struct Node *head);
void push(int data);
void displayStack();

int main()
{
    struct Node *head = NULL;
    int position1, position2, picked1, picked2;

    // Initialize the linked list with pairs of numbers (1-10, each number appears twice)
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Insert the numbers into the linked list
    for (int i = 0; i < n; i++)
    {
        insertAtEnd(&head, numbers[i]);
    }

    while (1)
    {
        printf("\nHidden List: ");
        displayHiddenList(head);

        printf("\nPick the position of the first card (1-%d): ", getListLength(head));
        scanf("%d", &position1);
        picked1 = pickCard(head, position1);

        printf("You picked: %d\n", picked1);

        printf("Pick the position of the second card (1-%d): ", getListLength(head));
        scanf("%d", &position2);
        picked2 = pickCard(head, position2);

        printf("You picked: %d\n", picked2);

        if (picked1 == picked2)
        {
            printf("\nMatched! Pushing %d onto the stack.\n", picked1);
            push(picked1);

            // Remove the matched pair from the linked list
            if (position1 > position2)
            {
                deleteFromPosition(&head, position1);
                deleteFromPosition(&head, position2);
            }
            else
            {
                deleteFromPosition(&head, position2);
                deleteFromPosition(&head, position1);
            }
        }
        else
        {
            printf("\nNot matched! The cards remain hidden.\n");
        }

        // Display the current stack
        printf("\nRevealed Stack: ");
        displayStack();

        if (getListLength(head) == 0)
        {
            printf("\nAll cards have been matched and revealed. Game over!\n");
            break;
        }
    }

    printf("\nFinal List: ");
    displayList(head);
    return 0;
}

// Function to insert a node at the end of the list
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

// Function to display the hidden state of the linked list
void displayHiddenList(struct Node *head)
{
    while (head != NULL)
    {
        printf("[*] -> ");
        head = head->next;
    }
    printf("NULL\n");
}

// Function to display the entire list (used for final output)
void displayList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to pick a card from a given position and return its value
int pickCard(struct Node *head, int position)
{
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < position; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return -1;
    }
    return temp->data;
}

// Function to insert a node at a specific position
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

// Function to delete a node from a specific position
void deleteFromPosition(struct Node **head, int position)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;

    if (position == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to push a value onto the stack
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

// Function to display the stack
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

// Function to get the length of the list
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
