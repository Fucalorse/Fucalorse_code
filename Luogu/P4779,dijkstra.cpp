#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90,inf=2e9;

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
void add(int from,int to,int n)
{
    op[cnt].to=to;
    op[cnt].next=head[from];
    op[cnt].val=n;
    head[from]=cnt;
    cnt++;
}

struct qwq
{
    int pos,val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n,m,st;
vector<int>dist;
bool vis[MAX];
priority_queue<qwq>q;

void bfs()
{
    dist.resize(n+5,inf);
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
    n=read(),m=read(),st=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        add(u,v,val);
    }
    bfs();
    for(int i=1;i<=n;i++)
        printf("%d ",dist[i]);
    printf("\n");
    return 0;
}