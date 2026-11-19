#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n;
int op[MAX];

int max(int a,int b) { return a>b?a:b; }

int main()
{
    int v;
    while(scanf("%d",&v)==1) op[++n]=v;
    int sum=0,maxn=-2e9;
    for(int i=1;i<=n;i++)
    {
        sum=max(sum+op[i],op[i]);
        maxn=max(maxn,sum);
    }
    printf("%d",maxn);
    return 0;
}