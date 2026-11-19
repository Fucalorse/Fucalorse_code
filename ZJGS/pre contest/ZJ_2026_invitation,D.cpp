#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e5+10;
const double eps=1e-12,inf=1e30;

struct ovo
{
    int to,id;
    double l;
};

struct qwq
{
    int pos;
    double val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n,m;
double t;
double a[MAX],b[MAX],dist[MAX];
bool vis[MAX];
vector<ovo>p[MAX];
priority_queue<qwq>q;

void bfs()
{
    for(int i=1;i<=n;i++)
        dist[i]=inf;
    dist[1]=0;
    q.push({1,0});
    while(q.size())
    {
        auto [u,val]=q.top();q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto &[v,id,l]:p[u])
        {
            double cost;
            if(dist[u]>t+eps) cost=dist[u]+l/b[id];
            else if(dist[u]+l/a[id]<t+eps) cost=dist[u]+l/a[id];
            else cost=t+(l-a[id]*(t-dist[u]))/b[id];
            if(dist[v]>cost+eps)
            {
                dist[v]=cost;
                if(!vis[v]) q.push({v,dist[v]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>t;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        double l;
        cin>>u>>v>>l>>a[i]>>b[i];
        p[u].push_back({v,i,l});
        p[v].push_back({u,i,l});
    }
    bfs();
    cout<<fixed<<setprecision(9)<<dist[n]<<endl;
    return 0;
}