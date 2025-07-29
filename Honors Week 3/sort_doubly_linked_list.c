#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_SIZE 200
#define VALUE_RANGE 49

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Inserts a new Node at the end of the doubly linked list
void insertEnd(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Performs Bubble Sort on the list
void bubbleSort(Node *head) {
    if (head == NULL) return;

    int swapped;
    Node *ptr;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr) {
            if (ptr->data > ptr->next->data) {
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

// Removes duplicate values from a sorted doubly linked list
void removeDuplicates(Node *head) {
    if (head == NULL || head->next == NULL) return;

    Node *current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node *temp = current->next;
            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Prints the list values in rows of 5
void printRowsOf5(Node *head) {
    int count = 0;
    while (head != NULL) {
        printf("%5d ", head->data);
        head = head->next;
        if (++count % 5 == 0) printf("\n");
    }
    printf("\n");
}

// Frees all nodes in the list (memory cleanup)
void freeList(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    srand(time(NULL));
    Node *head = NULL;

    // Generate list with random values
    for (int i = 0; i < LIST_SIZE; i++) {
        int value = rand() % VALUE_RANGE;
        insertEnd(&head, value);
    }

    printf("\nOriginal List:\n");
    printRowsOf5(head);

    bubbleSort(head);
    printf("\nSorted List (using Bubble Sort):\n");
    printRowsOf5(head);

    removeDuplicates(head);
    printf("\nSorted List without Duplicates:\n");
    printRowsOf5(head);

    freeList(head);
    return 0;
}
