#include <bits/stdc++.h>
using namespace std;

const int MAX=1e4+90,LEN=2e4+90,inf=0x3f3f3f3f;

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
}op[LEN<<1];

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

int n,m,st,ed;
int dist[MAX];
bool vis[MAX];
priority_queue<qwq>q;

bool bfs(const int &mid)
{
    memset(dist,0x3f,sizeof(dist));
    memset(vis,false,sizeof(vis));
    dist[st]=0;
    q.push({st,0});
    while(q.size()&&!vis[ed])
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(int i=head[cur.pos];i;i=op[i].next)
        {
            if(op[i].val>mid) continue;
            int &to=op[i].to;
            if(dist[to]>dist[cur.pos]+op[i].val)
            {
                dist[to]=dist[cur.pos]+op[i].val;
                if(!vis[to]) q.push({to,dist[to]});
            }
        }
    }
    return dist[ed]!=inf;
}

int main()
{
    n=read(),m=read(),st=read(),ed=read();
    int l=0,r=0;
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        add(u,v,val),add(v,u,val);
        if(val>r) r=val;
    }
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(bfs(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}