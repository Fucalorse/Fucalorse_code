#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e4+120;

int n,k,mod;
LL dp[2][105][MAX][2];

void solve()
{
    cin>>n>>k>>mod;
    dp[0][0][0][0]=1;
    int p=1;
    for(int i=1;i<=n*2;i++,p^=1)
    {
        int maxn=min({n,i,2*n-i+1});
        auto &g=dp[p],&f=dp[p^1];
        memset(dp[p],0,sizeof(dp[p]));
        for(int j=0;j<=maxn;j++)
            for(int s=0;s<=k;s++)
            {
                for(int x=0;x<=1;x++)
                {
                    LL &val=f[j][s][x];
                    if(!val) continue;
                    if(x==1)
                    {
                        if(j) g[j-1][s][1]=(g[j-1][s][1]+val*j)%mod;
                        g[j][min(s+i,k)][0]=(g[j][min(s+i,k)][0]+val)%mod;
                    }
                    else
                    {
                        if(j) g[j-1][s][0]=(g[j-1][s][0]+val*j)%mod;
                        g[j][s][1]=(g[j][s][1]+val)%mod;
                        if(j+1<=n) g[j+1][min(s+i,k)][0]=(g[j+1][min(s+i,k)][0]+val)%mod;
                    }
                }
            }
    }
    cout<<dp[p^1][0][k][0]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}