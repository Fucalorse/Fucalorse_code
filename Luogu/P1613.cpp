#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=100,LEN=32;
const LL inf=1e18;

int n,m;
bool f[MAX][MAX][LEN+3];
vector<vector<LL>>dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    dp.assign(n+3,vector<LL>(n+3,inf));
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        f[u][v][0]=true;
        dp[u][v]=1;
    }
    for(int k=1;k<=LEN;k++)
        for(int p=1;p<=n;p++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    f[i][j][k]|=f[i][p][k-1]&f[p][j][k-1];
                    if(f[i][j][k]) dp[i][j]=1;
                }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    cout<<dp[1][n]<<endl;
    return 0;
}