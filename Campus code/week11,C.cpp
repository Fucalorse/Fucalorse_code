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

int n,st,maxn;
int depth[MAX],f[MAX];

int min(int a,int b) { return a<b?a:b; }

void clear()
{
    cnt=0;
    for(int i=0;i<=n;i++)
        head[i]=0;
}

void dfs(int ch,int fa)
{
    f[ch]=fa;
    depth[ch]=depth[fa]+1;
    if(depth[ch]>maxn) maxn=depth[ch],st=ch;
    else if(depth[ch]==maxn&&ch<st) st=ch;
    for(int i=head[ch];i;i=op[i].next)
    {
        int to=op[i].to;
        if(to==fa) continue;
        dfs(to,ch);
    }
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v),add(v,u);
        }
        maxn=0;
        dfs(1,0);
        int ed=st;
        depth[st]=maxn=0;
        dfs(st,0);
        printf("%d %d\n",min(st,ed),depth[st]-depth[ed]+1);
    }
    return 0;
}