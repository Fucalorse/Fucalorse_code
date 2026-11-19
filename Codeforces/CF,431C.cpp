#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=210,INF=2e9,MOD=1e9+7;

int n,k,d;
LL dp[MAX][MAX][2];

void solve()
{
    cin>>n>>k>>d;

    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
        for(int s=0;s<n;s++)
            for(int v=1;v<=k;v++)
            {
                if(s+v>n) continue;

                if(v<d)
                {
                    dp[i][s+v][0]=(dp[i][s+v][0]+dp[i-1][s][0])%MOD;
                    dp[i][s+v][1]=(dp[i][s+v][1]+dp[i-1][s][1])%MOD;
                }
                else dp[i][s+v][1]=(dp[i][s+v][1]+dp[i-1][s][0]+dp[i-1][s][1])%MOD;
            }

    LL ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+dp[i][n][1])%MOD;

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}