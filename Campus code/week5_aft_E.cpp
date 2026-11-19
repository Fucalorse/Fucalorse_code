#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int k,n;
int num[MAX],ans[MAX];

void dfs(int pos,int cnt)
{
    if(cnt==k)
    {
        for(int i=0;i<k;i++)
        {
            if(i>0) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=pos;i<=n;i++)
    {
        ans[cnt]=num[i];
        dfs(i+1,cnt+1);
    }
}

int main()
{
    scanf("k=%d",&k);
    int v;
    while(scanf("%d",&v)==1) num[++n]=v;
    dfs(1,0);
    return 0;
}