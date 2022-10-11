#include<stdio.h>
#include<iostream>

int main()
{
    int n;
    printf("enter number of elements in array");
    scanf("%d",&n);

    int ar[n];

 printf("enter elements of array in sorted order");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);

    }

    printf("enter elements which need to search in array");
    int ele;
    scanf("%d",&ele);

    int l=0,r=n-1;
    int mid;
    while(l<=r)
    {
        min=(l+r)/2;
        if(ar[mid]==ele)
        {
            printf("element found");
            return 0;
        }
        else if(ar[min] <ele)
        {
            l=mid+1;
        }
        else{
            r=mid-1;
        }
        printf("element not found");
    return 0;

    }




}

