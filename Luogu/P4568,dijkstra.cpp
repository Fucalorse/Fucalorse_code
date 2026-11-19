#include <bits/stdc++.h>
using namespace std;

const int MAX=3e6+90;

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
}op[MAX];

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

int n,m,k,st,ed;
int dist[MAX];
bool vis[MAX];
priority_queue<qwq>q;

void bfs()
{
    q.push({st,0});
    memset(dist,0x3f,sizeof dist);
    dist[st]=0;
    while(q.size()&&!vis[ed+k*n])
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(int i=head[cur.pos];i;i=op[i].next)
        {
            int &to=op[i].to;
            if(vis[to]) continue;
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
    n=read(),m=read(),k=read();
    st=read(),ed=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        add(u,v,val),add(v,u,val);
        for(int j=1;j<=k;j++)
        {
            add(u+(j-1)*n,v+j*n,0),add(v+(j-1)*n,u+j*n,0);
            add(u+j*n,v+j*n,val),add(v+j*n,u+j*n,val);
        }
    }
    for(int i=1;i<=k;i++)
        add(ed+(i-1)*n,ed+i*n,0);
    bfs();
    printf("%d\n",dist[ed+k*n]);
    return 0;
}