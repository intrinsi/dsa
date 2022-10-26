#include <stdio.h>
#include <stdlib.h>

struct node // structure of node
{
    int data;
    struct node *nextpt;
} * headpt;

void delete_end_node() // function for deleting end node in the linked list
{
    struct node *n, *r;
    n = headpt;
    while (n->nextpt != headpt)
    {
        r = n;
        n = n->nextpt;
    }
    r->nextpt = headpt;
    printf("The deletion at end node is -> %d", n->data);
    free(n);
}

void list(int n) // list creation function of circular linked list
{
    int l, data;
    struct node *prevpt, *new_node;

    if (n >= 1)
    {
        headpt = (struct node *)malloc(sizeof(struct node));

        printf("Enter data for node 1 : ");
        scanf("%d", &data);
        headpt->data = data;
        headpt->nextpt = NULL;
        prevpt = headpt;
        for (l = 2; l <= n; l++)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            printf("Enter data for node %d : ", l);
            scanf("%d", &data);
            new_node->data = data;
            new_node->nextpt = NULL;
            prevpt->nextpt = new_node;
            prevpt = new_node;
        }
        prevpt->nextpt = headpt;
    }
}

void print(int m) // print function of circular linked list
{
    struct node *extra;
    int n = 1;

    if (headpt == NULL)
    {
        printf("The List is empty");
    }
    else
    {
        extra = headpt;
        if (m == 1)
        {
            printf("The circular linked list is :\n");
        }
        else
        {
            printf("After insertion the list is :\n");
        }
        do
        {
            printf("The data at node %d is %d\n", n, extra->data);
            extra = extra->nextpt;
            n++;
        } while (extra != headpt);
    }
}

int main()
{
    int value, n, x;
    printf("Enter the size of nodes: \n");
    scanf("%d", &n);
    list(n);
    print(x);
    delete_end_node(value);
    return 0;
}