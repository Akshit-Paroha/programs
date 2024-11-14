#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function to traverse and print the linked list
void traverseList(Node *head)
{
    Node *current = head; // Start from the head node

    while (current != NULL) // While there are nodes to visit
    {
        cout << current->data << " "; // Process the current node's data
        current = current->next;      // Move to the next node
    }
}

int main()
{
    // Create some nodes for demonstration
    Node *head = new Node();
    head->data = 10;
    head->next = new Node();
    head->next->data = 20;
    head->next->next = new Node();
    head->next->next->data = 30;
    head->next->next->next = NULL;

    // Traverse the list and print the values
    traverseList(head);

    return 0;
}
