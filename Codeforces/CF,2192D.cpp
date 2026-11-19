#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int a[MAX],depth[MAX],max_depth[MAX];
LL sum[MAX],sub[MAX],dp[MAX];

void dfs(int ch,int fa,vector<vector<int>>& adj)
{
    max_depth[ch]=depth[ch]=depth[fa]+1;
    sum[ch]=a[ch];
    sub[ch]=0;
    dp[ch]=0;

    int max1=-INF,max2=-INF;
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);
        sum[ch]+=sum[to];
        sub[ch]+=sub[to]+sum[to];
        max_depth[ch]=max(max_depth[ch],max_depth[to]);

        if(max_depth[to]>max1)
        {
            max2=max1;
            max1=max_depth[to];
        }
        else if(max_depth[to]>max2) max2=max_depth[to];
    }

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dp[ch]=max(dp[ch],dp[to]);
        if(max1==-INF||max2==-INF) continue;
        int other=(max_depth[to]==max1?max2:max1)+1-depth[ch];
        LL now=1LL*sum[to]*max(0,other-1);
        dp[ch]=max(dp[ch],now);
    }
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[0]=-1;
    dfs(1,0,adj);
    
    // for(int i=1;i<=n;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;

    for(int i=1;i<=n;i++)
        cout<<sub[i]+dp[i]<<' ';
    cout<<endl;
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