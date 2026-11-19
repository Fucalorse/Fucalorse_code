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

int t,idx,n,qwq,st,maxn;
int depth[MAX],f[MAX];
char s[MAX];

int find()
{
    if(idx>n) return 0;
    char now=s[idx++];
    if(now=='#') return 0;
    int pos=++qwq;
    int l=find();
    int r=find();
    if(l) add(pos,l),add(l,pos);
    if(r) add(pos,r),add(r,pos);
    return pos;
}

void dfs(int ch,int fa)
{
    depth[ch]=depth[fa]+1;
    f[ch]=fa;
    if(depth[ch]>maxn) maxn=depth[ch],st=ch;
    for(int i=head[ch];i;i=op[i].next)
    {
        int to=op[i].to;
        if(to==fa) continue;
        dfs(to,ch);
    }
}

void solve()
{
    scanf(" %s",s+1);
    n=strlen(s+1);
    idx=1,qwq=0;
    memset(head,0,sizeof(int)*(n+3)),cnt=0;
    int root=find();

    maxn=0;
    dfs(root,0);
    maxn=depth[st]=0;
    dfs(st,0);
    printf("%d\n",maxn-1);
}

int main()
{
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}