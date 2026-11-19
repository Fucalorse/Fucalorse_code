#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

int T,n,m;
string a;

void solve()
{
    cin>>n>>m>>a;
    a=' '+a,a=a+' ';

    vector<vector<vector<LL>>>dp(n+3,vector<vector<LL>>(m+3,vector<LL>(m+3,0)));
    dp[0][0][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=m;k++)
            {
                //left
                if(a[i+1]=='(') dp[i+1][j+1][k+1]=(dp[i+1][j+1][k+1]+dp[i][j][k])%MOD;
                else dp[i][j+1][k+1]=(dp[i][j+1][k+1]+dp[i][j][k])%MOD;

                //right
                if(!k) continue;
                if(a[i+1]==')') dp[i+1][j+1][k-1]=(dp[i+1][j+1][k-1]+dp[i][j][k])%MOD;
                else dp[i][j+1][k-1]=(dp[i][j+1][k-1]+dp[i][j][k])%MOD;

                // cout<<dp[i][j][k]<<' ';
            }
    // cout<<endl;

    cout<<dp[n][m][0]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}