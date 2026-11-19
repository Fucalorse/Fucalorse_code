#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 2e9
#define LL long long

struct edge
{
    int u,v;
}ans[MAX];

int q[MAX],h,t;

void push(int n) { q[++t]=n; }
int front() { return q[h]; }
void pop() { ++h; }
int size() { return t-h+1; }

int n,m;
int g[50][50],nxt[50],indeg[50],dist[50];

void clear()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i][j]=inf;
    memset(indeg,0,sizeof(indeg));
    memset(dist,-0x3f,sizeof(dist));
    memset(nxt,0,sizeof(nxt));
    h=1,t=0;
}

void bfs()
{
    push(n);
    dist[n]=0;
    while(size())
    {
        int pos=front();pop();
        for(int to=1;to<=n;to++)
            if(g[pos][to]!=inf)
            {
                if(dist[to]<dist[pos]+g[pos][to])
                {
                    dist[to]=dist[pos]+g[pos][to];
                    nxt[to]=pos;
                }
                else if(dist[to]==dist[pos]+g[pos][to]&&pos<nxt[to]) nxt[to]=pos;
                if(--indeg[to]==0) push(to);
            }
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
            g[v][u]=val;
            indeg[u]++;
        }
        bfs();

        printf("%d\n",dist[1]);
        
        int tot=0;
        for(int i=1;i;i=nxt[i])
            if(nxt[i])
            {
                ++tot;
                ans[tot].u=i;
                ans[tot].v=nxt[i];
            }
        for(int i=1;i<=tot;i++)
            printf("%d %d\n",ans[i].u,ans[i].v);
    }
    return 0;
}