#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;
const LL inf=1e18;

struct edge
{
    int u,v;
    LL val;
}op[MAX];

struct qwq
{
    int pos,from;
    LL val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int T,n,m,k;
int a[MAX];
LL dist[MAX];
double ans[MAX];
vector<pair<int,LL>>p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        dist[i]=inf;
        ans[i]=0;
    }
}

void get_max()
{
    priority_queue<qwq>q;
    q.push({1,0,0LL});
    dist[1]=0;
    vector<bool>vis(n+1,false);
    while(q.size())
    {
        auto [pos,from,val]=q.top();q.pop();
        if(vis[pos]) continue;
        vis[pos]=true;
        for(auto &[to,val]:p[pos])
        {
            if(dist[to]>dist[pos]+val)
            {
                dist[to]=dist[pos]+val;
                q.push({to,from,dist[to]});
            }
        }
    }
}

void solve()
{
    cin>>n>>m>>k;clear();
    for(int i=1;i<=k;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        LL val;
        cin>>u>>v>>val;
        op[i]={u,v,val};
        p[u].push_back({v,val});
        p[v].push_back({u,val});
    }

    get_max();
    LL maxn=-inf;
    for(int i=1;i<=k;i++)
        maxn=max(maxn,dist[a[i]]);

    vector<int>id(n+1,0);
    vector<LL>dis(n+1,inf);
    auto bfs=[&]()
    {
        priority_queue<qwq>q;
        for(int i=1;i<=k;i++)
        {
            q.push({a[i],i,0LL});
            dis[a[i]]=0;
        }
        while(q.size())
        {
            auto [pos,from,val]=q.top();q.pop();
            if(id[pos]) continue;
            // cout<<pos<<' '<<from<<endl;
            id[pos]=from;
            for(auto &[to,val]:p[pos])
            {
                if(dis[to]>dis[pos]+val)
                {
                    dis[to]=dis[pos]+val;
                    q.push({to,from,dis[to]});
                }
            }
        }
    };

    bfs();
    // for(int i=1;i<=n;i++)
    //     cout<<id[i]<<' ';
    // cout<<endl;
    for(int i=1;i<=m;i++)
    {
        auto [u,v,val]=op[i];
        if(id[u]==id[v]) continue;
        if(dis[u]+val+dist[v]<=maxn||dis[v]+val+dist[u]<=maxn)
        {
            double now=maxn-(double)(1.00*dis[u]+val+dis[v])/2;
            ans[id[u]]=max(ans[id[u]],now);
            ans[id[v]]=max(ans[id[v]],now);
        }
    }

    cout<<fixed<<setprecision(1);
    for(int i=1;i<=k;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}