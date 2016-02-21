#include <stdio.h>
#include <stdlib.h>

void push(int);
void pop();
int peep();
void change(int);
int a[100],top = -1;
int main()
{
    push(2);
    push(3);
    push(7);
    printf("%d\n",peep());
    pop();
    printf("%d\n",peep());
    pop();
    printf("%d\n",peep());
    push(7);
    printf("%d\n",peep());
    change(13);
    printf("%d\n",peep());
    return 0;
}

void push(int x)
{
    if(top==99)
        printf("Stack Full, cannot insert more elements\n");
    else
        a[++top] = x;
}

void pop()
{
    top==-1?printf("Stack Empty!\n"):top--;
}

int peep()
{
    if(top == -1)
    {
        printf("Stack is Empty!\n");
        return 0;
    }
    return a[top];
}

void change(int x)   //changes the top element
{
    if(top==-1)
        printf("Error stack is empty");
    else
        a[top]=x;
}
