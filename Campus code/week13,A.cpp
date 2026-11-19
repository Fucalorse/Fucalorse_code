#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int h=1,t=0;
int q[MAX];

void push(int n) { q[++t]=n; }
int front() { return q[h]; }
void pop() { ++h; }
int size() { return t-h+1; }

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
}ans[MAX],pre[MAX];

int n,m,tot=0;
int a[MAX];
bool vis[MAX];

void bfs()
{
    push(a[1]);
    vis[a[1]]=true;
    while(size())
    {
        int pos=front();pop();
        for(int i=head[pos];i;i=op[i].next)
        {
            int to=op[i].to;
            if(vis[to]) continue;
            vis[to]=true;
            ans[++tot].u=pos;
            ans[tot].v=to;
            push(to);
        }
    }
}

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char c;
        scanf(" %c",&c);
        a[i]=c-'A'+1;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        char u,v;
        scanf(" %c%*c%c",&u,&v);
        pre[i].u=u-'A'+1,pre[i].v=v-'A'+1;
    }
    for(int i=m;i>=1;i--)
        add(pre[i].u,pre[i].v),add(pre[i].v,pre[i].u);
    bfs();
    if(tot==n-1)
    {
        for(int i=1;i<=tot;i++)
            printf("%c,%c\n",ans[i].u+'A'-1,ans[i].v+'A'-1);
    }
    else printf("ERROR\n");
}

int main()
{
    solve();
    return 0;
}