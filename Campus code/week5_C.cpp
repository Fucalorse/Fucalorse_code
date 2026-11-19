#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int qwq=0,n;
int op[MAX];

int main()
{
    scanf("%d",&n);
    if(!n) op[++qwq]=0;
    while(n)
    {
        op[++qwq]=n%8;
        n/=8;
    }
    printf("%d ",qwq);
    for(int i=1;i<=qwq;i++)
        printf("%d",op[i]);
    return 0;
}