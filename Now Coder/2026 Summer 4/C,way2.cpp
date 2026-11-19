#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e4+90,LEN=20,MOD=1e9+7;
const LL INF=1e18;

int n,m;
LL d[LEN+2],cost[1<<(LEN+1)][LEN+2];

void solve()
{
    cin>>n>>m;

    int S=1<<m,FULL=S-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>d[j];

        string s;
        cin>>s;

        int reject=0;
        for(int j=0;j<m;j++)
            if(s[j]=='R') reject|=1<<j;

        for(int j=0;j<m;j++)
            cost[FULL^reject][j]+=d[j];
    }

    for(int bit=0;bit<m;bit++)
        for(int mask=0;mask<S;mask++)
        {
            if((mask>>bit)&1) continue;

            for(int i=0;i<m;i++)
                cost[mask][i]+=cost[mask|(1<<bit)][i];
        }

    vector<LL>dp(S,INF);
    dp[0]=0;

    for(int mask=0;mask<S;mask++)
        for(int k=0;k<m;k++)
        {
            if((mask>>k)&1) continue;

            LL now=cost[mask][k];
            if(dp[mask]!=INF) dp[mask|(1<<k)]=min(dp[mask|(1<<k)],dp[mask]+now);
        }

    cout<<dp[FULL]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}