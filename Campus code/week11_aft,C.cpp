#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 1e9
#define LL long long

LL max(LL a,LL b) { return a>b?a:b; }

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

int n;
int f[MAX];
LL a[MAX],dp[MAX];

void dfs(int ch,int fa)
{
    f[ch]=fa;
    dp[ch]=a[ch];
    for(int i=head[ch];i;i=op[i].next)
    {
        int to=op[i].to;
        if(to==fa) continue;
        dfs(to,ch);
        dp[ch]+=max(0LL,dp[to]);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    dfs(1,0);
    LL maxn=-inf;
    for(int i=1;i<=n;i++)
        maxn=max(maxn,dp[i]);
    printf("%lld\n",maxn);
    return 0;
}