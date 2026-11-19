#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=3e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int sz[MAX];
LL dp[MAX];

void dfs(int ch,int fa,vector<vector<int>>& adj)
{
    sz[ch]=1;
    dp[ch]=0;
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);
        dp[ch]+=1LL*sz[ch]*sz[to];
        sz[ch]+=sz[to];
    }    
}

void solve()
{
    cin>>n;

    int S=1<<n;
    vector<vector<int>>adj(S);
    for(int i=1;i<=S-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0,-1,adj);

    int ans=0;
    for(int i=1;i<S;i++)
        if((dp[i]+1)&1) ans^=i;
    
    cout<<ans<<endl;
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