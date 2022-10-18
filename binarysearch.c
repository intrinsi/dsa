#include<stdio.h>
#include<stdlib.h>
int search(int [], int ,int);
int main(void){
    int a[40],n,ele,index=-1;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for (int  i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to search");
    scanf("%d",&ele);
    index = search(a,n,ele);
    if (index==-1){
        printf("Element is not found");
    }
    else{
        printf("%d",index);
    }
} 
    int search(int a[], int n, int ele){
        int f=0,l=n-1,mid;
        while (f<=l){
            mid=(f+l)/2;
            if (a[mid]==ele){
              return mid;
            }
            else if(a[mid]<ele){
                f=mid+1;
            }
            else{
                l=mid-1;
            }
            
        }
            
        return -1;
}