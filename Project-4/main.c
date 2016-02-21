#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[7][6] = {0,1,0,0,0,0,
                   0,0,0,0,0,0,
                   -2,0,0,1,0,0,
                   0,0,0,0,0,0,
                   0,0,0,0,0,0,
                   0,-3,0,0,0,0,
                   0,0,0,0,0,-1};
    int i,j;
    int l=0,m=0;
    int b[14][3];
    for(i=0,l=0;i<7;i++)
    {
        for(j=0;j<6;j++)
        {
            m = 0;
            if(a[i][j]!=0)
            {
                b[l][m++] = i;
                b[l][m++] = j;
                b[l++][m++] = a[i][j];
            }
        }
    }
    for(i=0;i<l;i++)
    {
        for(j=0;j<3;j++)
            printf("%2d  ",b[i][j]);
        printf("\n");
    }
    return 0;
}
