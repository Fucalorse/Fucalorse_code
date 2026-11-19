#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5090,LEN=1e4+90;
const LL INF=1e18;

struct qwq
{
    int x,y;
}op[LEN];

int n,m;
vector<pair<int,LL>>p[MAX];

void dfs1(int ch,int fa,vector<LL>& dp)
{
    for(auto &[to,val]:p[ch])
    {
        if(to==fa) continue;

        dp[to]=min(dp[to],dp[ch]+val);
        dfs1(to,ch,dp);
    }
}

void dfs2(int ch,int fa,vector<LL>& dp)
{
    for(auto &[to,val]:p[ch])
    {
        if(to==fa) continue;

        dfs2(to,ch,dp);
        dp[ch]=min(dp[ch],dp[to]+val);
    }
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<n;i++)
    {
        int u,v;
        LL val;
        cin>>u>>v>>val;

        p[u].push_back({v,val});
        p[v].push_back({u,val});
    }

    for(int i=1;i<=m;i++)
        cin>>op[i].x>>op[i].y;

    vector<LL>dp(n+1,INF);
    dp[1]=0;
    dfs1(1,0,dp);
    
    LL ans=0;
    for(int i=2;i<=n;i++)
        ans+=dp[i];
    cout<<ans<<endl;

    for(int k=1;k<=n;k++)
    {
        LL ans=0;
        vector<LL>ndp=dp;

        for(int i=1;i<=m;i++)
        {
            auto [x,y]=op[i];

            ndp[x]=min(ndp[x],dp[y]);
            ndp[y]=min(ndp[y],dp[x]);
        }

        dp=ndp;
        dfs2(1,0,dp);
        dfs1(1,0,dp);

        for(int i=2;i<=n;i++)
            ans+=dp[i];
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}