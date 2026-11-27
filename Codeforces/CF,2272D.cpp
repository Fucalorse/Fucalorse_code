#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct node
{
    int drop,choose;
}op[MAX];

int k;
int sz[MAX],dp[MAX][2],son[MAX];

void dfs(int ch,int fa,vector<vector<int>>& adj)
{
    dp[ch][1]=1;
    dp[ch][0]=0;
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);
        dp[ch][1]+=dp[to][0];
        dp[ch][0]+=max(dp[to][0],dp[to][1]);
    }
}

void solve()
{
    cin>>k;
    
    int size_two_pos=-1;
    for(int i=1;i<=k;i++)
    {
        cin>>sz[i];
        if(sz[i]>=2) size_two_pos=i;
        vector<vector<int>>adj(sz[i]+1);
        for(int j=1;j<sz[i];j++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(adj[1].size()) son[i]=adj[1].front();
        dfs(1,0,adj);
        op[i]={dp[1][0],dp[1][1]};
    }

    pair<int,int>base;
    if(size_two_pos!=-1)
    {
        base.first=size_two_pos;
        if(op[size_two_pos].choose<=op[size_two_pos].drop) base.second=1;
        else base.second=son[size_two_pos];
    }
    else base={1,1};

    // cout<<base.first<<endl;
    for(int i=1;i<=k;i++)
    {
        if(i==base.first) continue;
        cout<<base.first<<' '<<base.second<<' '<<i<<' '<<1<<endl;
    }
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