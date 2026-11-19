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
    int next,to;
}op[MAX];

int head[MAX],cnt=0;
void add(int from,int to)
{
    ++cnt;
    op[cnt].next=head[from];
    op[cnt].to=to;
    head[from]=cnt;
}

struct qwq
{
    int u,v;
}pre[MAX],ans[MAX];

int n,m,tot;
bool vis[MAX],g[200][200];
char s[MAX];

void dfs(int u)
{
    if(vis[u]) return;
    vis[u]=true;
    for(int v=1;v<=n;v++)
        if(g[u][v]&&!vis[v])
        {
            ans[++tot].u=u;
            ans[tot].v=v;
            dfs(v);
        }
}

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf(" %c",s+i);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        char a,b;
        int u,v;
        scanf(" %c%*c%c",&a,&b);
        u=a-'A'+1,v=b-'A'+1;
        g[u][v]=g[v][u]=true;
    }
    dfs(s[1]-'A'+1);
    if(tot==n-1)
    {
        for(int i=1;i<=tot;i++)
        {
            char u=ans[i].u+'A'-1,v=ans[i].v+'A'-1;
            if(u<v) printf("%c,%c",u,v);
            else printf("%c,%c",v,u);
            printf("\n");
        }
    }
    else printf("ERROR\n");
}

int main()
{
    solve();
    return 0;
}