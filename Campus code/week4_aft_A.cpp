#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

void swap(int *a,int *b)
{
    int p=*a;
    *a=*b;
    *b=p;
}

int n;
int op[20][20];

int main()
{
    scanf("%d",&n);
    int min1=2e9,min2=2e9;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",op[i]+j);
            if(op[i][j]<min1) min2=min1,min1=op[i][j];
            else if(op[i][j]<min2) min2=op[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(op[i][j]==min1)
            {
                swap(op[i]+j,op[1]+1);
                break;
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(op[i][j]==min2)
            {
                swap(op[i]+j,op[n]+n);
                break;
            }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d",op[i][j]);
            if(j<n) printf(" ");
        }
        printf("\n");
    }
    return 0;
}