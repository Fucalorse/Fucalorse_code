#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int qwq;
int op[MAX];

int main()
{
    int v;
    while(scanf("%d",&v)==1&&v) op[++qwq]=v;
    for(int i=qwq;i>=1;i--)
    {
        if(i!=qwq) printf(" ");
        printf("%d",op[i]);
    }
    return 0;
}