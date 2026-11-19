#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define  LL long long
const int MAX=550,inf=2e9,mod=998244353;

int t,n;

void solve()
{
    cin>>n;
    for(int k=1;k<=n;k++)
    {
        vector<vector<LL>>dp(n+3,vector<LL>(k+3,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=k;j++)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j]*(j?2:1))%mod;
                if(j-1>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                if(j+1<=k) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
            }
        cout<<(dp[n][0]+dp[n][1])%mod<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}