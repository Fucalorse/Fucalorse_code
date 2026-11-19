#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,inf=1e9;

int read()
{
    int ans=0,f=1;
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
    int next,to,val;
}op[MAX<<1];

int head[MAX],cnt=1;
void add(int from,int to,int val)
{
    op[cnt]={head[from],to,val};
    head[from]=cnt++;
}

struct qwq
{
    int pos,val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

struct segment
{
    int u,v,val;
}seg[MAX];

int n,m;
bool vis[MAX];
vector<int>f,g;

void bfs(const int &st,vector<int>&dist)
{
    priority_queue<qwq>q;
    memset(vis,false,sizeof vis);
    dist.assign(n+10,inf);
    dist[st]=0;
    q.push({st,0});
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(int i=head[cur.pos];i;i=op[i].next)
        {
            int &to=op[i].to;
            if(dist[to]>dist[cur.pos]+op[i].val)
            {
                dist[to]=dist[cur.pos]+op[i].val;
                if(!vis[to]) q.push({to,dist[to]});
            }
        }
    }
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        seg[i]={u,v,val};
        add(u,v,val),add(v,u,val);
    }
    bfs(1,f),bfs(n,g);
    int minn=f[n],ans=inf;
    for(int i=1;i<=m;i++)
    {
        int &u=seg[i].u,&v=seg[i].v,&val=seg[i].val;
        if(f[u]+g[v]>f[v]+g[u]) swap(u,v);
        if(f[u]+g[v]+val==minn) ans=min(ans,minn+val*2);
        else ans=min(ans,f[u]+g[v]+val);
    }
    printf("%d\n",ans);
    return 0;
}