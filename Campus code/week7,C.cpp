#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n,qwq=0;
int num[MAX];
bool vis[MAX];
int op[MAX];

void dfs(int pos,int sum)
{
    if(sum>n) return;
    if(sum==n)
    {
        for(int i=1;i<=qwq;i++)
        {
            if(i!=1) printf(" ");
            printf("%d",op[i]);
        }
        printf("\n\n");
        return;
    }
    for(int i=pos;i<=n;i++)
        if(!vis[i])
        {
            op[++qwq]=num[i];
            dfs(i+1,sum+num[i]);
            --qwq;
        }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        num[i]=n-i+1;
    dfs(1,0);
    return 0;
}