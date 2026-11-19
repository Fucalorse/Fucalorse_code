#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 10090

int t,n;
bool vis[MAX];
int num[MAX],op[MAX];

bool dis()
{
    int qwq=0;
    for(int i=1,j=1;i<=n;i++)
    {
        op[++qwq]=i;
        while(qwq&&op[qwq]==num[j])
        {
            --qwq;
            j++;
        }
    }
    if(qwq) return false;
    else return true;
}

void dfs(int cnt)
{
    if(cnt>n)
    {
        if(dis())
        {
            for(int i=1;i<=n;i++)
            {
                if(i>1) printf(" ");
                printf("%d",num[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            vis[i]=true;
            num[cnt]=i;
            dfs(cnt+1);
            vis[i]=false;
        }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(vis,false,sizeof(bool)*(n+5));
        dfs(1);
    }
    return 0;
}