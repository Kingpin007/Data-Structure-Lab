#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3],b[3][3],c[3][3][3];
    int *p = b,*q = c;
    printf("a[0] = %d \na[2] = %d\t%d\n",a,&a[2],a+2);
    printf("b[0][0] = %d \nb[2][1] = %d\t%d\n",b,&b[2][1],p+2*3+1);
    printf("c[0][0][0] = %d \nc[1][2][0] = %d\t%d\n",c,&c[1][2][0],q+1*3*3+2*3+0);
    return 0;
}
