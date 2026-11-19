#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
LL a[MAX],b[MAX],g[MAX],dp[MAX];

void dfs(int ch,int fa,vector<vector<int>>& adj)
{
    dp[ch]=0;
    g[ch]=b[ch];
    LL sum=0;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);
        sum+=a[to];
        if(g[to]<b[to]) g[ch]=__gcd(g[ch],g[to]);
        dp[ch]+=dp[to];
    }

    g[ch]=__gcd(g[ch],sum);
    dp[ch]+=b[ch]-g[ch]+a[ch]%g[ch];
}

void solve()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
        cin>>b[i];

    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,adj);
    
    cout<<dp[1]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}