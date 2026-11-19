#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e5+10,LEN=30,MOD=998244353,INF=1e9;

int n,S;
int ans[MAX];
vector<vector<int>>dp(MAX);

void dfs(int ch,int fa,vector<vector<pair<int,int>>>& p)
{
    dp[ch].assign(S+1,0);
    for(int i=0;i<=S;i++)
        dp[ch][i]=i;

    for(auto &[to,val]:p[ch])
    {
        if(to==fa) continue;

        dfs(to,ch,p);
        for(int x=0;x<=S;x++)
        {
            int now=INF;
            if(x-val>=0) now=min(now,dp[to][x-val]);
            if(x+val<=S) now=min(now,dp[to][x+val]);
            dp[ch][x]=max(now,dp[ch][x]);
        }
    }

    ans[ch]=INF;
    for(int x=0;x<=S;x++)
        ans[ch]=min(ans[ch],dp[ch][x]);
}

void solve()
{
    cin>>n;

    S=0;
    vector<vector<pair<int,int>>>p(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        p[u].push_back({v,val});
        p[v].push_back({u,val});
        S=max(S,val);
    }
    S<<=1;

    dfs(1,0,p);

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while (T--) solve();

    return 0;
}