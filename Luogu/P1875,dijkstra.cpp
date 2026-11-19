#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1090,LEN=1e7+90;

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
    int next,to,bro;
}op[LEN];

int head[MAX],cnt=1;
void add(int from,int to,int bro)
{
    op[cnt]={head[from],to,bro};
    head[from]=cnt++;
}

struct qwq
{
    int pos;
    LL val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n;
LL cost[MAX],f[MAX];
bool vis[MAX];
priority_queue<qwq>q;

void bfs()
{
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(int i=head[cur.pos];i;i=op[i].next)
        {
            int &to=op[i].to,&bro=op[i].bro;
            if(!vis[bro]) continue;
            if(cost[to]>cost[cur.pos]+cost[bro])
            {
                cost[to]=cost[cur.pos]+cost[bro];
                f[to]=f[cur.pos]*f[bro];
                if(!vis[to]) q.push({to,cost[to]});
            }
            else if(cost[to]==cost[cur.pos]+cost[bro])
                f[to]+=f[cur.pos]*f[bro];
        }
    }
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        cost[i]=read();
        q.push({i,cost[i]});
        f[i]=1;
    }
    int u,v,to;
    while(scanf("%d%d%d",&u,&v,&to)==3)
    {
        ++u,++v,++to;
        add(u,to,v);
        if(u!=v) add(v,to,u);
    }
    bfs();
    printf("%lld %lld\n",cost[1],f[1]);
    return 0;
}