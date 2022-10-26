#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Represents the node of list.
struct node
{
    int data;
    struct node *next;
};

int size;
// Declaring head and tail pointer as null.
struct node *head = NULL;
struct node *tail = NULL;

// This function will add the new node at the end of the list.
void add(int data)
{
    // Create new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    // Checks if the list is empty.
    if (head == NULL)
    {
        // If list is empty, both head and tail would point to new node.
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else
    {
        // tail will point to new node.
        tail->next = newNode;
        // New node will become new tail.
        tail = newNode;
        // Since, it is circular linked list tail will point to head.
        tail->next = head;
    }
    // Counts the number of nodes in list
    size++;
}

// Deletes node from the middle of the list
void deleteMid()
{
    struct node *current, *temp;
    // Checks whether list is empty
    if (head == NULL)
    {
        return;
    }
    else
    {
        // Store the mid position of the list
        int count = (size % 2 == 0) ? (size / 2) : ((size + 1) / 2);
        // Checks whether head is equal to tail or not, if yes then list has only one node.
        if (head != tail)
        {
            // Initially temp will point to head;
            temp = head;
            current = NULL;
            // Current will point to node previous to temp
            // If temp is pointing to node 2 then current will points to node 1.
            for (int i = 0; i < count - 1; i++)
            {
                current = temp;
                temp = temp->next;
            }

            if (current != NULL)
            {
                // temp is the middle that needs to be removed.
                // So, current node will point to node next to temp by skipping temp.
                current->next = temp->next;
                // Delete temp;
                temp = NULL;
            }
            // Current points to null then head and tail will point to node next to temp.
            else
            {
                head = tail = temp->next;
                tail->next = head;
                // Delete temp;
                temp = NULL;
            }
        }
        // If the list contains only one element
        // then it will remove it and both head and tail will point to null
        else
        {
            head = tail = NULL;
        }
    }
    size--;
}

// This function will display the nodes of circular linked list
void display()
{
    struct node *current = head;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        do
        {
            // Prints each node by incrementing pointer.
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
        printf("\n");
    }
}

int main()
{
    // Adds data to the list
    add(1);
    add(2);
    add(3);
    add(4);
    // Printing original list
    printf("Original List:\n ");
    display();
    while (head != NULL)
    {
        deleteMid();
        // Printing updated list
        printf("Updated List:\n ");
        display();
    }

    return 0;
}