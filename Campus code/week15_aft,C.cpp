#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 1e9
#define LL long long

struct edge
{
    int u,v;
}ans[MAX];

int n,m;
int g[50][50],dist[50],pre[50];

void clear()
{
    memset(pre,0,sizeof(pre));
    memset(dist,-0x3f,sizeof(dist));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i][j]=inf;
}

void dfs(int pos)
{
    for(int to=1;to<=n;to++)
        if(g[pos][to]!=inf)
        {
            if(dist[to]<dist[pos]+g[pos][to])
            {
                dist[to]=dist[pos]+g[pos][to];
                pre[to]=pos;
                dfs(to);
            }
            else if(dist[to]==dist[pos]+g[pos][to]&&pos<pre[to]) pre[to]=pos;
        }
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        clear();
        for(int i=1;i<=m;i++)
        {
            int u,v,val;
            scanf("%d%d%d",&u,&v,&val);
            g[u][v]=val;
        }

        dist[1]=0;
        dfs(1);

        int qwq=0;
        for(int i=n;i;i=pre[i])
            if(pre[i])
            {
                ++qwq;
                ans[qwq].u=pre[i],ans[qwq].v=i;
            }
    
        // for(int i=1;i<=n;i++)
        //     printf("%d ",dist[i]);
        // printf("\n\n");

        printf("%d\n",dist[n]);
        for(int i=qwq;i>=1;i--)
            printf("%d %d\n",ans[i].u,ans[i].v);
    }
}