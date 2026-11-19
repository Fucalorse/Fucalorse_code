#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=610,LEN=300;

int T,n,m;
LL C[MAX][MAX],f[MAX];

void solve()
{
    cin>>n>>m;

    C[0][0]=1;
    for(int i=1;i<=n*2;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%m;
    }

    f[0]=1;
    for(int i=1;i<=n*2;i++)
        f[i]=f[i-1]*i%m;

    vector<vector<vector<LL>>>dp(n+1,vector<vector<LL>>(n+1,vector<LL>(2,0)));

    for(int i=1;i<=n;i++)
        dp[i][0][0]=dp[0][i][1]=C[n][i];

    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            for(int k=1;k<=n-i;k++)
                dp[i+k][j][0]=(dp[i+k][j][0]+dp[i][j][1]*C[n-i][k]%m)%m;
            for(int k=1;k<=n-j;k++)
                dp[i][j+k][1]=(dp[i][j+k][1]+dp[i][j][0]*C[n-j][k]%m)%m;
        }

    LL ans=f[2*n];
    for(int k=1;k<n*2;k++)
        for(int i=0;i<=min(k,n);i++)
        {
            if(k-i>n||k-i<0) continue;

            LL now=(dp[i][k-i][0]+dp[i][k-i][1])%m;
            ans=(ans+now*f[2*n-k])%m;
        }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}