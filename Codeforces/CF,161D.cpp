#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5e4+90;

int n,k;
LL dp[MAX][510],sum[MAX];

void dfs(int ch,int fa,vector<vector<int>>& p)
{
    dp[ch][0]=1;

    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        dfs(to,ch,p);

        sum[ch]+=sum[to];
        for(int j=1;j<k;j++)
            sum[ch]+=dp[ch][j]*dp[to][k-j-1];

        for(int i=1;i<=k;i++)
            dp[ch][i]+=dp[to][i-1];
    }
}

void solve()
{
    cin>>n>>k;

    vector<vector<int>>p(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }

    dfs(1,0,p);

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<":";
    //     for(int d=0;d<=k;d++)
    //         cout<<dp[i][d]<<" ";
    //     cout<<endl;
    // }

    LL ans=sum[1];
    for(int i=1;i<=n;i++)
        ans+=dp[i][k];
    
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}