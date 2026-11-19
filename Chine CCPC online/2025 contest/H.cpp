#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e4+90,MOD=1e9+7,LEN=15;
const LL INF=1e18;

int n,m,k,T;
LL v[16][MAX],ans[100];
int h[55],cost[55],l[55][16],to[55][16];

void solve()
{
    cin>>n>>m>>k>>T;

    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
        {
            cin>>v[i][j];
            if(j>0) v[i][j]-=v[i][0];
        }

    for(int i=1;i<=m;i++)
    {
        cin>>h[i]>>cost[i];

        for(int j=1;j<=h[i];j++)
            cin>>l[i][j]>>to[i][j];
    }

    vector<vector<LL>>dp(T+2,vector<LL>(1<<n,-INF));
    vector<LL>f(1<<n);
    LL base=0;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        base+=v[i][0];

    for(int i=1;i<=m;i++)
    {
        for(int t=T-cost[i];t>=0;t--)
        {
            copy(dp[t].begin(),dp[t].end(),f.begin());

            for(int j=1;j<=h[i];j++)
            {
                int bit=1<<(l[i][j]-1);
                LL val=v[l[i][j]][to[i][j]];

                for(int S=0;S<(1<<n);++S)
                    if((S&bit)==0&&f[S]!=-INF) f[S|bit]=max(f[S|bit],f[S]+val);
            }
            
            for(int S=0;S<(1<<n);++S)
                dp[t+cost[i]][S]=max(dp[t+cost[i]][S],f[S]);
        }
    }

    for(int i=1;i<=T;i++)
    {
        for(int S=0;S<(1<<n);++S)
            ans[i]=max(ans[i],dp[i][S]);
        ans[i]=max(ans[i],ans[i-1]);
        cout<<ans[i]+base<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}