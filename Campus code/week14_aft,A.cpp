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
}op[MAX],ans[MAX];
typedef struct edge qwq;

int cmp(const void *a,const void *b)
{
    const qwq x=*(const qwq *)a;
    const qwq y=*(const qwq *)b;
    return x.val-y.val;
}

int n,m;
int fa[MAX];
char s[MAX];

int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

void combine(int x,int y) { fa[find(x)]=find(y); }

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf(" %c",s+i);
        fa[i]=i;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        char a,b;
        int val,u,v;
        scanf(" %c%*c%c%*c%d",&a,&b,&val);
        u=a-'A'+1,v=b-'A'+1;
        op[i].u=u,op[i].v=v,op[i].val=val;
    }
    qsort(op+1,m,sizeof(qwq),cmp);

    // for(int i=1;i<=m;i++)
    //     printf("%d %d %d\n",op[i].u,op[i].v,op[i].val);

    int total=0,tot=0;
    for(int i=1;i<=m;i++)
    {
        int u=op[i].u,v=op[i].v,val=op[i].val;
        if(find(u)==find(v)) continue;
        ans[++tot]=op[i];
        combine(u,v);
        total+=val;
    }
    if(tot==n-1)
    {
        for(int i=1;i<=tot;i++)
            printf("%c,%c:%d\n",ans[i].u+'A'-1,ans[i].v+'A'-1,ans[i].val);
        printf("\n%d\n",total);
    }
    else printf("ERROR\n");
}

int main()
{
    solve();
    return 0;
}