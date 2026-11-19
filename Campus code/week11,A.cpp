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

int n,root;
int son[MAX];

void dfs(int ch,int fa)
{
    for(int i=head[ch];i;i=op[i].next)
    {
        int to=op[i].to;
        if(to==fa) continue;
        son[ch]++;
        dfs(to,ch);
    }
}

void solve()
{
    scanf("%d%d",&n,&root);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    dfs(root,0);
    for(int i=1;i<=n;i++)
        if(son[i]!=2&&son[i]!=0)
        {
            printf("no\n");
            return;
        }
    printf("yes\n");
}

int main()
{
    solve();
    return 0;
}