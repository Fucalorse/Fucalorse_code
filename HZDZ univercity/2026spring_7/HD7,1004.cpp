#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=510;
const LL inf=1e15;

int t,n;
LL a[MAX];

void solve()
{
    cin>>n;
    vector<vector<vector<LL>>>dp(n+5,vector<vector<LL>>(n+5,vector<LL>(3,-inf)));
    for(int i=1;i<=n+1;i++)
        cin>>a[i];
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
            for(int k=0;k<=2;k++)
            {
                if(dp[i-1][j][k]==-inf) continue;
                dp[i][j+1][min(k+1,2)]=max(dp[i][j+1][min(k+1,2)],dp[i-1][j][k]-a[i]);
            }
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<=1;k++)
            {
                if(dp[i-1][j][k]==-inf) continue;
                dp[i][j-1][0]=max(dp[i][j-1][0],dp[i-1][j][k]+a[i]);
            }
            if(i>=3&&a[i-2]>a[i-1]) dp[i][j-1][0]=max(dp[i][j-1][0],dp[i-1][j][2]+a[i]);
        }
    }
    LL ans=-inf;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=2;j++)
            if(dp[n][i][j]!=-inf) ans=max(ans,dp[n][i][j]+i*a[n+1]);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}