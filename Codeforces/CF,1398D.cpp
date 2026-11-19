#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2090,MOD=1e9+7;
const LL INF=1e18;

int R,G,B;
LL r[MAX],g[MAX],b[MAX];

void solve()
{
    cin>>R>>G>>B;

    for(int i=1;i<=R;i++)
        cin>>r[i];
    for(int i=1;i<=G;i++)
        cin>>g[i];
    for(int i=1;i<=B;i++)
        cin>>b[i];

    sort(r+1,r+R+1,greater<LL>());
    sort(g+1,g+G+1,greater<LL>());
    sort(b+1,b+B+1,greater<LL>());

    vector<vector<vector<LL>>>dp(R+1,vector<vector<LL>>(G+1,vector<LL>(B+1)));

    LL ans=0;
    for(int i=0;i<=R;i++)
        for(int j=0;j<=G;j++)
            for(int k=0;k<=B;k++)
            {
                if((i+j+k)&1) continue;

                if(i>0&&j>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+r[i]*g[j]);
                if(i>0&&k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+r[i]*b[k]);
                if(j>0&&k>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+g[j]*b[k]);
                // cout<<dp[i][j][k]<<' ';
                ans=max(ans,dp[i][j][k]);
            }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}