#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=110,MOD=1e8;
const LL INF=1e18;

int n,m,k;
int c[MAX];
LL p[MAX][MAX];

void solve()
{
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>p[i][j];
        
    vector<vector<vector<LL>>>dp(n+3,vector<vector<LL>>(m+3,vector<LL>(k+3,INF)));
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i])
        {
            if(c[i-1])
            {
                for(int s=0;s<=k;s++)
                    if(dp[i-1][c[i-1]][s]!=INF)
                    {
                        if(c[i]==c[i-1]) dp[i][c[i]][s]=min(dp[i][c[i]][s],dp[i-1][c[i-1]][s]);
                        else dp[i][c[i]][s+1]=min(dp[i][c[i]][s+1],dp[i-1][c[i-1]][s]);
                    }
            }
            else
            {
                for(int col=0;col<=m;col++)
                    for(int s=0;s<=k;s++)
                        if(dp[i-1][col][s]!=INF)
                        {
                            if(c[i]==col) dp[i][c[i]][s]=min(dp[i][c[i]][s],dp[i-1][col][s]);
                            else dp[i][c[i]][s+1]=min(dp[i][c[i]][s+1],dp[i-1][col][s]);
                        }
            }
        }
        else
        {
            if(c[i-1])
            {
                for(int col=1;col<=m;col++)
                    for(int s=0;s<=k;s++)
                        if(dp[i-1][c[i-1]][s]!=INF)
                        {
                            if(col==c[i-1]) dp[i][col][s]=min(dp[i][col][s],dp[i-1][c[i-1]][s]+p[i][col]);
                            else dp[i][col][s+1]=min(dp[i][col][s+1],dp[i-1][c[i-1]][s]+p[i][col]);

                            // if(col==c[i-1]) cout<<dp[i][col][s]<<' ';
                            // else cout<<dp[i][col][s+1]<<' ';
                        }
            }
            else
            {
                for(int nc=1;nc<=m;nc++)
                    for(int pc=0;pc<=m;pc++)
                        for(int s=0;s<=k;s++)
                            if(dp[i-1][pc][s]!=INF)
                            {
                                if(nc==pc) dp[i][nc][s]=min(dp[i][nc][s],dp[i-1][pc][s]+p[i][nc]);
                                else dp[i][nc][s+1]=min(dp[i][nc][s+1],dp[i-1][pc][s]+p[i][nc]);

                                // cout<<nc<<' '<<pc<<' '<<s<<endl;
                                // if(nc==pc) cout<<dp[i][nc][s]<<' ';
                                // else cout<<dp[i][nc][s+1]<<' ';
                            }
            }
        }
    }

    LL ans=INF;
    for(int i=1;i<=m;i++)
        ans=min(ans,dp[n][i][k]);

    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}