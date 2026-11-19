#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e5+90,LEN=32,G=3,MOD=998244353;
const LL INF=1e18;

struct qwq
{
    int pos;
    LL val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n,m;
vector<LL>dist;
int from[MAX];
bool vis[MAX];

void bfs(vector<vector<pair<int,LL>>>& adj)
{
    priority_queue<qwq>q;
    dist.assign(n+1,INF);
    q.push({1,0LL}),dist[1]=0;
    
    while(q.size())
    {
        auto [pos,val]=q.top();q.pop();
        if(vis[pos]) continue;
        vis[pos]=true;

        for(auto &[to,val]:adj[pos])
            if(dist[to]>dist[pos]+val)
            {
                dist[to]=dist[pos]+val;
                from[to]=pos;
                q.push({to,dist[to]});
            }
    }
}

void solve()
{
    cin>>n>>m;

    vector<vector<pair<int,LL>>>adj(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        LL val;
        cin>>u>>v>>val;
        adj[u].push_back({v,val});
        adj[v].push_back({u,val});
    }

    bfs(adj);

    if(dist[n]==INF) cout<<-1<<endl;
    else
    {
        vector<int>st;
        for(int i=n;i;i=from[i])
            st.push_back(i);

        while(st.size())
        {
            cout<<st.back()<<' ';
            st.pop_back();
        }
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}