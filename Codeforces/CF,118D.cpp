#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=110,INF=2e9,MOD=1e8;

int n1,n2,k1,k2;
LL dp[MAX][MAX][2];

void solve()
{
    cin>>n1>>n2>>k1>>k2;

    dp[0][0][0]=dp[0][0][1]=1;
    for(int i=0;i<=n1;i++)
        for(int j=0;j<=n2;j++)
        {
            if(!i&&!j) continue;

            for(int k=1;k<=min(i,k1);k++)
                dp[i][j][0]=(dp[i][j][0]+dp[i-k][j][1])%MOD;
            for(int k=1;k<=min(j,k2);k++)
                dp[i][j][1]=(dp[i][j][1]+dp[i][j-k][0])%MOD;
        }

    cout<<(dp[n1][n2][0]+dp[n1][n2][1])%MOD<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}