#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function that inserts a new Node at the end of a linked list
void insertEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) // First element
        *head = newNode;
    else // Go to the end of the list and insert new node
    {
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to sort a list using Bubble Sort Algorithm
void bubbleSort(Node *head)
{
    int swapped, i;
    Node *ptr;
    Node *lptr = NULL;

    // Check for empty list
    if (head == NULL)
        return;
    do
    {
        swapped = 0; // If no swaps, list ordered
        ptr = head;
        while (ptr->next != lptr)
        {
            if (ptr->data > ptr->next->data)
            {
                // Swap nodes
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

// Function to print values in rows of 5
void printRowsOf5(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        printf("%5d ", head->data);
        head = head->next;
        count++;
        if (count % 5 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main(void)
{

    srand(time(NULL));
    Node *head = NULL;

    // Generate 100 random values and assign them to a list
    for (int i = 0; i < 100; i++)
    {
        int randomValue = rand() % 1000; // Setting range of 0-1000 to be more readable
        insertEnd(&head, randomValue);
    }

    printf("Original List:\n");
    printRowsOf5(head);

    // Perform bubble sort on the linked list
    bubbleSort(head);

    printf("Sorted List (using Bubble Sort):\n");
    printRowsOf5(head);

    return 0;
}
