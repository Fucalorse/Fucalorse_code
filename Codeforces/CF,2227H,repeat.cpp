#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353;
const LL INF=1e18;

int n;
int cnt[MAX];
LL dp[MAX][2];

void dfs(int ch,int fa,vector<vector<int>>& adj)
{
    cnt[ch]=0;
    dp[ch][0]=0,dp[ch][1]=INF;
    if((int)adj[ch].size()==1)
    {
        cnt[ch]=1;
        dp[ch][1]=0;
        return;
    }

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);

        LL a=dp[to][0]+(cnt[to]&1);
        LL b=dp[to][1]+((cnt[to]-1)&1);
        dp[ch][1]=min(dp[ch][1]+a,dp[ch][0]+b);
        dp[ch][0]+=a;

        cnt[ch]+=cnt[to];
    }
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

    int root=1;
    for(int i=1;i<=n;i++)
        if((int)adj[i].size()>=2)
        {
            root=i;
            break;
        }

    dfs(root,0,adj);
    cout<<dp[root][cnt[root]&1]<<endl;
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