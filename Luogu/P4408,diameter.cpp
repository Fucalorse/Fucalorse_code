#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=2e5+90;

LL read()
{
    LL ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

struct edge
{
    int next,to;
    LL val;
}op[MAX<<1];

int head[MAX],cnt=1;
void add(int from,int to,LL n)
{
    op[cnt].to=to;
    op[cnt].next=head[from];
    op[cnt].val=n;
    head[from]=cnt;
    cnt++;
}

int n,m,st,ed;
int f[MAX];
LL depth[MAX],maxn;
vector<LL>fst,fed;

void dfs(int ch,int fa)
{
    f[ch]=fa;
    for(int i=head[ch];i;i=op[i].next)
    {
        int &to=op[i].to;
        if(to==fa) continue;
        depth[to]=depth[ch]+op[i].val;
        if(depth[to]>maxn) maxn=depth[to],st=to;
        dfs(to,ch);
    }
}

void find(int ch,int fa,vector<LL>&num)
{
    num[ch]=depth[ch];
    for(int i=head[ch];i;i=op[i].next)
    {
        int &to=op[i].to;
        if(to==fa) continue;
        depth[to]=depth[ch]+op[i].val;
        find(to,ch,num);
    }
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        LL val=read();
        add(u,v,val),add(v,u,val);
    }
    dfs(1,0);
    depth[st]=maxn=0;
    dfs(st,0);
    for(int i=st;i;i=f[i]) ed=i;
    LL total=maxn,ans=0;
    fst.resize(n+1,0),fed.resize(n+1,0);
    depth[st]=0,find(st,0,fst);
    depth[ed]=0,find(ed,0,fed);
    for(int i=1;i<=n;i++)
        ans=max(min(fst[i],fed[i]),ans);
    printf("%lld\n",ans+total);
    return 0;
}