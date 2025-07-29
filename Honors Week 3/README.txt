# Doubly Linked List – Sort and Remove Duplicates

This program demonstrates operations on a **doubly linked list**, including:

- Inserting nodes at the end
- Sorting the list using **Bubble Sort**
- Removing duplicates from the sorted list
- Printing values in formatted rows of 5

## 🧠 Key Concepts

- **Dynamic memory** using `malloc` and pointer management
- **Doubly linked list** node management (`prev` and `next` pointers)
- **Bubble Sort** on a linked structure
- In-place **duplicate removal** after sorting

## 🧪 How It Works

1. Generates 200 random integers from 0 to 48
2. Inserts them into a doubly linked list
3. Sorts the list in ascending order
4. Removes any repeated values
5. Prints the list at each stage


## 🛠 How to Compile and Run

```bash
gcc sort_doubly_linked_list.c -o linkedlist
./linkedlist