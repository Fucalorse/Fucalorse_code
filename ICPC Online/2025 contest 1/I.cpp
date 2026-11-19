#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,INF=2e9;

struct qwq
{
    int pos;
    int bag,rest;
    bool operator<(const qwq &a)const
    {
        if(bag!=a.bag) return bag>a.bag;
        else return rest<a.rest;
    }
};

int n,m,V,T;

vector<pair<int,int>> bfs(vector<vector<pair<int,int>>>& p)
{
    priority_queue<qwq>q;
    vector<pair<int,int>>cost(n+1,{INF,0});
    vector<bool>vis(n+1,false);

    q.push({T,1,V});
    cost[T]={1,V};

    while(q.size())
    {
        auto [pos,bag,rest]=q.top();q.pop();

        if(vis[pos]) continue;
        vis[pos]=true;

        for(auto &[to,val]:p[pos])
        {
            int n_bag=cost[pos].first+(cost[pos].second<val);
            int n_rest=cost[pos].second>=val?cost[pos].second-val:V-val;

            if(cost[to].first>n_bag)
            {
                cost[to]={n_bag,n_rest};
                if(!vis[to]) q.push({to,n_bag,n_rest});
            }
            else if(cost[to].first==n_bag&&cost[to].second<n_rest)
            {
                cost[to]={n_bag,n_rest};
                if(!vis[to]) q.push({to,n_bag,n_rest});
            }
        }
    }

    return cost;
}

void solve()
{
    cin>>n>>m>>V>>T;

    vector<vector<pair<int,int>>>p(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;

        p[u].push_back({v,val});
        p[v].push_back({u,val});
    }

    vector<pair<int,int>>cost=bfs(p);
    for(int i=1;i<=n;i++)
    {
        if(cost[i].first==INF) cout<<-1<<' ';
        else cout<<cost[i].first<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}