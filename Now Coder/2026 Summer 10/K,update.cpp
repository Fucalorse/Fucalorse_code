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
    int m=n*3,S=1<<m,full=S-1;

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    vector<LL>dp(S,-INF);
    dp[0]=0;

    auto cal=[&](int i,int j,int k) { return a[i][j]+a[j][k]+a[k][i]; };

    for(int mask=0;mask<S;++mask)
    {
        int cnt=__builtin_popcount(mask);
        if(cnt%3!=0||dp[mask]==-INF) continue;

        int rm=full^mask;
        int i=__builtin_ctz(rm);
        int ri=rm^(1<<i);

        for(int bj=ri;bj;bj-=bj&-bj)
        {
            int j=__builtin_ctz(bj);
            int rj=ri^(1<<j);

            for(int bk=rj;bk;bk-=bk&-bk)
            {
                int k=__builtin_ctz(bk);
                int nxt=mask|(1<<i)|(1<<j)|(1<<k);

                dp[nxt]=max(dp[nxt],dp[mask]+cal(i,j,k));
            }
        }
    }

    cout<<dp.back()<<endl;
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