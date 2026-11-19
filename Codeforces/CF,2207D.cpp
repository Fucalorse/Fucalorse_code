#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,k,st_node;
int dp[MAX],depth[MAX],f[MAX];

void update(int &min1,int &min2,int val)
{
    if(val<min1)
    {
        min2=min1;
        min1=val;
    }
    else min2=min(min2,val);
}

void dfs(int ch,int fa,vector<vector<int>>& adj)
{
    depth[ch]=depth[fa]+1;
    dp[ch]=f[ch]=INF;
    if((int)adj[ch].size()==1)
    {
        f[ch]=depth[ch];
        return;
    }

    int min1=INF,min2=INF;
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);
        dp[ch]=min(dp[ch],dp[to]);
        f[ch]=min(f[ch],f[to]);
        if(dp[to]==INF) update(min1,min2,f[to]);
        else update(min1,min2,min(dp[to],f[to]));
    }

    if(min1!=INF&&min2!=INF)
    {
        int now=min1+min2-2*depth[ch];
        if(now<=k+1) dp[ch]=depth[ch];
    }
}

void solve()
{
    cin>>n>>k>>st_node;

    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(st_node,0,adj);
    if(dp[st_node]==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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