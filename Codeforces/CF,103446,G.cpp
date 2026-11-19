#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e5,G=3,MOD=998244353,INF=2e9;

int n;
int edge[MAX];
LL dp[MAX],cnt[MAX];

void create()
{
    cnt[0]=cnt[1]=1;
    for(int i=2;i<=LEN;i++)
    {
        if(i&1) cnt[i]=i*cnt[i-1]%MOD;
        else cnt[i]=(i-1)*cnt[i-2]%MOD;
    }
}

void dfs(int ch,int fa,vector<vector<int>> &adj)
{
    dp[ch]=1;
    int rest=adj[ch].size();
    if(fa) --rest;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;

        dfs(to,ch,adj);
        edge[ch]+=edge[to]+1;
        dp[ch]=dp[ch]*dp[to]%MOD;

        if(edge[to]&1) --rest;
    }

    if(rest>=2) dp[ch]=dp[ch]*cnt[rest]%MOD;
}

void solve()
{
    cin>>n;

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

    create();
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}