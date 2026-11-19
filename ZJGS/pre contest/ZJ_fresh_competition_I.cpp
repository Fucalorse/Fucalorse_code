#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=2e5+90;

struct edge
{
    int next,to;
    LL val;
}op[MAX<<5];

int head[MAX<<2],cnt=0;
void add(int from,int to,LL val)
{
    op[++cnt]={head[from],to,val};
    head[from]=cnt;
}

struct qwq
{
    int pos;
    LL val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n,m;
LL dist[MAX<<2],num[MAX<<2];
bool vis[MAX<<2];
priority_queue<qwq>q;

void bfs()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    q.push({1,0});
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(int i=head[cur.pos];i;i=op[i].next)
        {
            int &to=op[i].to;
            LL &val=op[i].val;
            if(dist[to]>dist[cur.pos]+val)
            {
                dist[to]=dist[cur.pos]+val;
                if(!vis[to]) q.push({to,dist[to]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        if(!num[i]) continue;
        add(i,i+n,num[i]),add(i+n,i,num[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        LL a,b;
        cin>>u>>v>>a>>b;
        add(u,v,a),add(v,u,a);
        add(u+n,v+n,b),add(v+n,u+n,b);
    }
    bfs();
    cout<<min(dist[n],dist[n*2])<<'\n';
    return 0;
}