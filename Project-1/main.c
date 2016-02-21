#include <stdio.h>
#include <stdlib.h>

void createArray(int);
void insert(int,int);
void del(int);
int *a,len;
int main()
{
    createArray(5);
    insert(1,0);
    insert(2,1);
    insert(3,2);
    int i;
    for(i=0;i<3;i++)
        printf("%d ",*(a+i));
    printf("\n");
    del(1);
    for(i=0;i<2;i++)
        printf("%d ",*(a+i));
    printf("\n");
    return 0;
}

void createArray(int x)
{
    a = (int*)malloc(sizeof(int)*x);
    len = x;
}

void insert(int x,int n)
{
    int j = len;
    while(j>n)
    {
        a[j-1] = a[j];
        j--;
    }
    a[j] = x;
}

void del(int n)
{
    int j = n;
    while(j<len)
    {
        a[j] = a[j+1];
        j++;
    }
}
