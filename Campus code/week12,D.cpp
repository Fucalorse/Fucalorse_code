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

void initial()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}

void solve()
{
    scanf("%d",&m);
    initial();
    int cnt=n-1;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(find(u)==find(v)) continue;
        combine(u,v);
        --cnt;
    }
    printf("%d\n",cnt);
}

int main()
{
    while(scanf("%d",&n)&&n) solve();
    return 0;
}