#include <bits/stdc++.h>
using namespace std;

const int MAX=250,LEN=2e4+90,inf=0x3f3f3f3f;

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

int n,m,q;
int num[MAX],dist[MAX];
bool vis[MAX];

int bfs(const int &st,const int &ed,const int &t)
{
    if(num[st]>t||num[ed]>t) return -1;
    memset(dist,0x3f,sizeof dist);
    memset(vis,false,sizeof vis);
    priority_queue<qwq>q;
    dist[st]=0;
    q.push({st,0});
    while(!vis[ed]&&q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(int i=head[cur.pos];i;i=op[i].next)
        {
            int &to=op[i].to;
            if(num[to]>t) continue;
            if(dist[to]>dist[cur.pos]+op[i].val)
            {
                dist[to]=dist[cur.pos]+op[i].val;
                if(!vis[to]) q.push({to,dist[to]});
            }
        }
    }
    return dist[ed]==inf?-1:dist[ed];
}

int main()
{
    n=read(),m=read();
    for(int i=0;i<n;i++)
        num[i]=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        add(u,v,val),add(v,u,val);
    }
    q=read();
    while(q--)
    {
        int u=read(),v=read(),t=read();
        printf("%d\n",bfs(u,v,t));
    }
    return 0;
}