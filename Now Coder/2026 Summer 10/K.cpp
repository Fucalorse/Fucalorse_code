#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353;
const LL INF=1e18;

int n;
LL a[100][100];

void solve()
{
    cin>>n;
    int m=n*3,S=1<<m,full=S-1,A=(n/2)*3,B=((n+1)/2)*3;

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    vector<LL>dp(S,-INF);
    dp[0]=0;

    auto cal=[&](int i,int j,int k) { return a[i][j]+a[j][k]+a[k][i]; };

    for(int mask=1;mask<S;mask++)
    {
        int cnt=__builtin_popcount(mask);
        if(cnt>B||cnt%3!=0) continue;

        int i=__builtin_ctz(mask);
        int rest1=mask^(1<<i);

        for(int bit1=rest1;bit1;bit1-=bit1&-bit1)
        {
            int j=__builtin_ctz(bit1);
            int rest2=bit1^(1<<j);
            for(int bit2=rest2;bit2;bit2-=bit2&-bit2)
            {
                int k=__builtin_ctz(bit2);
                int pre=mask^(1<<i)^(1<<j)^(1<<k);
                if(dp[pre]!=-INF) dp[mask]=max(dp[mask],dp[pre]+cal(i,j,k));
            }
        }
    }

    LL ans=-INF;
    for(int mask=0;mask<S;mask++)
    {
        if(__builtin_popcount(mask)==A)
        {
            LL now=dp[mask]+dp[full-mask];
            ans=max(ans,now);
        }
    }

    cout<<ans<<endl;
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