#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findPos(char[]);
void insert(char[]);
void del(int);
char a[100][100],len=0;
int main()
{
    insert("Anirudh");
    insert("Kanabar");
    insert("Rahul");
    insert("Sanatt");
    insert("AAnirudh");
    insert("Youth");
    int i;
    for(i=0;i<=len;i++)
        printf("%s ",a[i]);
    printf("\n");
    del(1);
    for(i=0;i<=len;i++)
        printf("%s ",a[i]);
    printf("\n");
    return 0;
}

int findPos(char str[])
{
    int i;
    for(i=0;i<len;i++)
    {
        if(strcmp(str,a[i])<=0)
            return i;
    }
    return i;
}

void insert(char str[])
{
    int j = len+1;
    int n = findPos(str);
    while(j>n)
    {
        strcpy(a[j],a[j-1]);
        j--;
    }
    strcpy(a[j],str);
    len++;
}

void del(int n)
{
    int j = n;
    while(j<len)
    {
        strcpy(a[j],a[j+1]);
        j++;
    }
    len--;
}
