#include<stdio.h>
void linearsearch (int a[], int, int);
     void main()
 {
  int a[50], i, n, search;
  printf ("enter the size of array :");
  scanf ("%d", &n);
  printf("enter the elements");
  for (i=0;i<n; i++)
    {
      
      scanf ("%d", &a[i]);
    }
  printf ("enter the value to search");
  scanf ("%d", &search);
linearsearch(a,n,search);
    
}

void linearsearch (int a[], int n, int search)
{    int i;   
     int count = 0;
for (i = 0; i < n; i++)
  {
    if (a[i] == search)
      {
	count++;

      }
  }

printf ("%d occurs %d times\n", search, count);
}