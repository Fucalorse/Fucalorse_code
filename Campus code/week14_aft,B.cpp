#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int t,n,m;
int fa[MAX];

int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

void combine(int x,int y) { fa[find(x)]=find(y); }

void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    int total=n;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(find(u)==find(v)) continue;
        combine(u,v);
        --total;
    }

    if(total==1) printf("yes\n");
    else printf("no\n");
}

int main()
{
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}