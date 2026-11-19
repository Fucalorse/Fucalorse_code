#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int fa[MAX],sz[MAX];

int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

void combine(int x,int y)
{
    int px=find(x),py=find(y);
    if(px==py) return;
    fa[px]=py;
    sz[py]+=sz[px];
}

int t,n,k;
int deg[MAX];

void initial()
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        sz[i]=1;
        deg[i]=0;
    }
}

void solve()
{
    scanf("%d%d",&n,&k);
    initial();
    for(int i=1;i<=k;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        deg[u]++,deg[v]++;
        // printf("121::%d %d\n",find(u),find(v));
        combine(u,v);
    }
    if(sz[find(1)]!=n)
    {
        printf("NO\n");
        return;
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
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}