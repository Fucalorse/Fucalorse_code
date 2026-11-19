#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

struct edge
{
    int u,v,val;
}op[MAX];
typedef struct edge qwq;

int cmp(const void *a,const void *b)
{
    const qwq x=*(const qwq*)a,y=*(const qwq *)b;
    return x.val-y.val;
}

int fa[MAX];

int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

void combine(int x,int y) { fa[find(x)]=find(y); }

int n;

void initial()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}

void solve()
{
    initial();
    int len=n*(n-1)/2;
    for(int i=1;i<=len;i++)
        scanf("%d%d%d",&op[i].u,&op[i].v,&op[i].val);
    qsort(op+1,len,sizeof(qwq),cmp);
    // printf("\n");
    int ans=0;
    for(int i=1;i<=len;i++)
    {
        int u=op[i].u,v=op[i].v,val=op[i].val;
        // printf("%d %d %d\n",u,v,val);
        if(find(u)==find(v)) continue;
        combine(u,v);
        ans+=val;
    }
    printf("%d\n",ans);
}

int main()
{
    while(scanf("%d",&n))
    {
        if(!n) break;
        solve();
    }
    return 0;
}