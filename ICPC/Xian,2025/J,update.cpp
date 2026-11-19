#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=32;
const LL INF=1e18;

int n,m,timer;
int tin[MAX],tout[MAX];
LL c[MAX],dp[MAX],g[MAX],sum[MAX];

void dfs_first(int ch,int fa,vector<vector<int>>& adj)
{
    dp[ch]=c[ch];
    multiset<LL>st;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs_first(to,ch,adj);
        st.insert(dp[to]);
    }

    if((int)adj[ch].size()==1) return;

    //update dp
    auto it1=st.begin();
    auto it2=st.begin();++it2;
    dp[ch]=min(dp[ch],*it1+*it2);

    //update g
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        auto it=st.find(dp[to]);
        LL val=*it;
        st.erase(it);
        g[to]=*st.begin();
        st.insert(val);
    }
}

void dfs_second(int ch,int fa,vector<vector<int>>& adj)
{
    tin[ch]=++timer;
    sum[ch]=sum[fa]+g[ch];

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs_second(to,ch,adj);
    }

    tout[ch]=timer;
}

void clear()
{
    timer=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=g[i]=sum[i]=0;
        tin[i]=tout[i]=0;
    }
}

bool is_LCA(int u,int v) { return tin[u]<=tin[v]&&tout[v]<=tout[u]; }

void solve()
{
    cin>>n>>m;clear();

    for(int i=1;i<=n;i++)
        cin>>c[i];

    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_first(1,0,adj);
    dfs_second(1,0,adj);

    while(m--)
    {
        int x,y;
        cin>>x>>y;
        
        if(!is_LCA(y,x))
        {
            cout<<-1<<endl;
            continue;
        }

        cout<<sum[x]-sum[y]<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ J.cpp -O2 -o out.exe && .\out.exe < in.txt