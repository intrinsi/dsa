#include <stdio.h>
void main() {
    int num;
    // declaring an integer
    printf("Enter an integer: ");
    scanf("%d", &num);
    //scanning an number and storing in num

    // true if num is perfectly divisible by 2 then it is Even number
    if(num % 2 == 0)
        printf("%d is even.", num);
    //else if num is not perfectly divisible by 2 then it is Odd number
    else
        printf("%d is odd.", num);
    
}
