#include<stdio.h>
#include<stdlib.h> 
struct node    //structure of node in circular
{
  int data;
  struct node *nextpt;
} *headpt;

void list (int n) // list creation function of circular linked list
{
  int l,data;
  struct node *prevpt, *new_node;

if (n >= 1)
{
  headpt = (struct node *) malloc (sizeof (struct node));

  printf ("Enter data for node 1 : ");
  scanf ("%d", &data);
  headpt->data = data;
  headpt->nextpt = NULL;
  prevpt = headpt;
  for (l = 2; l <= n;l++)
  {
   new_node = (struct node *) malloc (sizeof (struct node));
   printf ("Enter data for node %d : ", l);
   scanf ("%d", &data);
   new_node->data = data;
   new_node->nextpt = NULL;
   prevpt->nextpt = new_node;
   prevpt = new_node;
  }
  prevpt->nextpt = headpt;
}
}

void insertAtEnd(int num1) //the function which adds last node
{
  struct node *e;
  int p;
  p=num1;
  struct node *extra=(struct node*)malloc(sizeof(struct node));
  extra->data=p;
  e=headpt;
  while(e->nextpt!=headpt)
  {
   e=e->nextpt;
  }
  e->nextpt=extra;
  extra->nextpt=headpt;
}

void print (int m) // print function of circular linked list
{
  struct node *extra;
  int n = 1;
  if (headpt == NULL)
  {
   printf ("The List is empty");
  }
  else
  {
   extra = headpt;
   if (m == 1)
   {
    printf ("The circular linked list is :\n");
   }
   else
  {
    printf ("After insertion the circular list is :\n");
   }
  do
  {
   printf ("The data at node %d :: %d\n", n, extra->data);
   extra = extra->nextpt;
   n++;
  }
  while (extra != headpt);
 }
}

int main ()
{
  int n,x,num1;
  headpt = NULL;
  printf ("Enter the size of nodes: \n");
  scanf ("%d", &n);
  list (n);
  print (x);
  printf ("\nEnter the data to be inserted at the end: ");
  scanf ("%d", &num1);
  insertAtEnd(num1);
  print (x);
  return 0;
}
