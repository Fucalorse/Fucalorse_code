#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=30,G=3,MOD=998244353;
const LL INF=1e18;

int n;
LL a[MAX],dp[2],ndp[2];

LL get_min(LL a,LL mask,LL pre)
{
    dp[0]=0,dp[1]=INF;

    for(int k=LEN;k>=0;k--)
    {
        ndp[0]=ndp[1]=INF;
        int pre_bit=(pre>>k)&1;

        for(int i=0;i<=1;i++)
        {
            if(dp[i]==INF) continue;

            for(int j=0;j<=1;j++)
            {
                if(!((mask>>k)&1)&&j!=((a>>k)&1)) continue;
                if(!i&&j<pre_bit) continue;

                int nxt=i||(j>pre_bit);
                LL now=dp[i]|(1LL*j<<k);

                ndp[nxt]=min(ndp[nxt],now);
            }
        }

        dp[0]=ndp[0];
        dp[1]=ndp[1];
    }

    return min(dp[0],dp[1]);
}

bool check(LL mask,int bit)
{
    LL pre=0;

    for(int i=1;i<=n;i++)
    {
        LL x=(a[i]>>bit)<<bit;

        LL now=get_min(x,mask,pre);
        if(now==INF) return false;

        pre=now;
    }

    return true;
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    LL mask=0;
    for(int k=LEN;k>=0;k--)
        if(!check(mask,k)) mask|=1LL<<k;

    cout<<mask<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}