#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
#define ULL unsigned long long
const int MAX=505,LEN=500,G=3,MOD=1e9+7,INF=2e9;
const LL LINF=1e18;

mt19937_64 rng(random_device{}());

int n,m;
int p[MAX][MAX],pos[MAX][MAX];
bool ok[MAX][MAX],same[MAX];
ULL Val[MAX],pre[MAX][MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>p[i][j];
            pre[i][j]=pre[i][j-1]^Val[p[i][j]];
            pos[i][p[i][j]]=j;
        }

    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            bool flag=true;
            ULL base=pre[1][r]^pre[1][l-1];
            for(int i=1;i<=m;i++)
            {
                int L=pos[i][p[1][l]],R=L+r-l;
                if(R>n)
                {
                    flag=false;
                    break;
                }
                ULL now=pre[i][R]^pre[i][L-1];
                if(now!=base)
                {
                    flag=false;
                    break;
                }
            }
            ok[l][r]=flag;
        }
    }

    vector<vector<LL>>dp(n+3,vector<LL>(n+3,0LL)),f(n+3,vector<LL>(n+3,0LL));
    for(int i=1;i<=n;i++)
    {
        f[i][i-1]=1;
        if(ok[i][i]) dp[i][i]=f[i][i]=1;
    }
    f[n+1][n]=1;

    for(int len=2;len<=n;len++)
        for(int l=1;l<=n-len+1;l++)
        {
            int r=l+len-1;
            if(ok[l][r]) dp[l][r]=f[l+1][r];
            for(int k=l;k<=r;k++)
                f[l][r]=(f[l][r]+dp[l][k]*f[k+1][r])%MOD;
        }

    cout<<dp[1][n]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    for(int i=1;i<=LEN;i++)
        Val[i]=rng();

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}