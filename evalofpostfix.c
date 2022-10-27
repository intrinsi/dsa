#include<stdio.h>
#include<math.h>
#include<conio.h>
int stack[20], top=-1;
void push(int x)
{
    stack[++top]=x;
}
int pop()
{
    return(stack[top--]);
}
void main()
{
    char s[20];
    int x, i, y;
    clrscr();
    printf("\n evaluation of postfix expression \n");
    printf("\n enter a postfix expression");
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        push(s[i]-'0');
        else
        {
            y=pop();
            x=pop();
            switch(s[i]){
                case '+':push(x+y); break;
                case '-':push(x-y); break;
                case '*':push(x*y); break;
                case '/':push(x/y); break;
                case '^':
                case '$':push(pow(x,y)); break;
            }
        }
    }
    printf("\n result is %d",pop());
    getch();
}