//Infix to Postfix conversion

#include <stdio.h>
#include <stdlib.h>

void push(char);
void pop();
char peep();
void change(char);
char s1[100] = "((A+B)*D)^(E–F)"
char s2[100] = "A+(B*C–(D/E^F)*G)*H";
int top = -1;
int main()
{

    return 0;
}

void push(char x)
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

void change(char x)   //changes the top element
{
    if(top==-1)
        printf("Error stack is empty");
    else
        a[top]=x;
}
