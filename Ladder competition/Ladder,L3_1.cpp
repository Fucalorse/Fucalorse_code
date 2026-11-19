#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define endl '\n'
const int MAX=505,LEN=5e6+10;
const LL inf=1e18;

struct edge
{
    int next,to,val,h;
}op[LEN];

int head[MAX],cnt=0;
void add(int from,int to,int val,int h)
{
    op[++cnt]={head[from],to,val,h};
    head[from]=cnt;
}

struct qwq
{
    int pos;
    LL val;
    bool operator>(const qwq &a)const { return val>a.val; }
    bool operator<(const qwq &a)const { return val<a.val;}
};

int w,n,m,k;
LL minn,maxn;
vector<LL>dist,f;
vector<bool>vis;

void bfs(const int &st)
{
    dist.assign(n+1,inf);
    f.assign(n+1,0);
    vis.assign(n+1,false);
    dist[st]=0;
    priority_queue<qwq,vector<qwq>,greater<qwq>>q;
    q.push({st,0});
    while(q.size())
    {
        auto [pos,val]=q.top();q.pop();
        if(vis[pos]) continue;
        vis[pos]=true;
        for(int i=head[pos];i;i=op[i].next)
        {
            int &to=op[i].to,&val=op[i].val,&h=op[i].h;
            if(dist[to]>dist[pos]+val)
            {
                dist[to]=dist[pos]+val;
                f[to]=f[pos]+h;
                if(!vis[to]) q.push({to,dist[to]});
            }
            else if(dist[to]==dist[pos]+val)
                f[to]=max(f[to],f[pos]+h);
        }
    }
    minn=inf,maxn=-inf;
    for(int i=1;i<=n;i++)
        if(i!=st&&dist[i]<=w)
        {
            maxn=max(maxn,f[i]);
            minn=min(minn,dist[i]);
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>w>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,val,h;
        cin>>u>>v>>val>>h;
        add(u,v,val,h),add(v,u,val,h);
    }
    while(k--)
    {
        int now;
        cin>>now;
        bfs(now);
        if(minn>w)
        {
            cout<<"T_T"<<endl;
            continue;
        }
        cout<<endl;
    }
    return 0;
}