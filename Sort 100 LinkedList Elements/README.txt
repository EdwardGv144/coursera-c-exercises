# Linked List Bubble Sort

This program demonstrates how to:
- Create and populate a singly linked list
- Sort it using the **Bubble Sort** algorithm
- Display values in cleanly formatted rows

## 🧠 Key Concepts

- **Linked Lists**: Dynamic memory, node insertion, pointer manipulation
- **Sorting**: Bubble sort adapted for linked structures
- **Memory Management**: Use of `malloc` for node creation
- **Output Formatting**: Neatly prints values in rows of 5

## 🧪 How It Works

1. Generates 100 random integers between 0–999
2. Stores them in a linked list using `insertEnd()`
3. Sorts the list using `bubbleSort()`
4. Prints both the original and sorted list in tabular format

## 🛠 How to Compile and Run

```bash
gcc sort_100_linkedlist_elements.c -o linkedlist
./linkedlist