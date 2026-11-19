#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int fa[MAX];

int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

void combine(int x,int y) { fa[find(x)]=find(y); }

int n,m;
int deg[MAX];

void initial()
{
    for(int i=1;i<=n;i++)
        deg[i]=0;
}

void solve()
{
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++)
        if(deg[i]&1)
        {
            printf("NO\n");
            return;
        }
    printf("YES\n");
}

int main()
{
    while(scanf("%d%d",&n,&m))
    {
        if(!n&&!m) break;
        solve();
    }
    return 0;
}