#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=1e9+7,INF=2e9;

LL qpow(LL a,LL p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ans;
}

int n;
LL m;
LL a[MAX];

void solve()
{
    cin>>n>>m;
    
    int unknown=0,cnt1=0;
    bool always=false;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==-1) unknown++;
        if(a[i]==1) cnt1++;
        if(a[i]!=-1&&a[i]>1&&a[i]<n) always=true;
    }

    if(n==2)
    {
        if(cnt1) cout<<qpow(m,unknown)<<endl;
        else
        {
            if(unknown==0) cout<<0<<endl;
            else if(unknown==1) cout<<1<<endl;
            else cout<<(2*m-1)%MOD<<endl;
        }
        return;
    }

    if(always)
    {
        cout<<qpow(m,unknown)<<endl;
        return;
    }

    LL del=0;
    if(unknown+cnt1==n&&(n&1)) ++del;

    if(a[1]!=1&&a[n]!=1&&m>=n)
    {
        vector<vector<LL>>dp(n+1,vector<LL>(2,0));
        dp[0][0]=1;

        for(int i=1;i<=n;i++)
        {
            if(i==1||i==n)
            {
                for(int pre=0;pre<=1;pre++)
                {
                    if(a[i]==-1) dp[i][0]=(dp[i][0]+dp[i-1][pre]*(m-n+1)%MOD)%MOD;
                    else dp[i][0]=(dp[i][0]+dp[i-1][pre])%MOD;
                }
            }
            else
            {
                if(a[i]==-1)
                {
                    for(int pre=0;pre<=1;pre++)
                        dp[i][0]=(dp[i][0]+dp[i-1][pre]*(m-n+1)%MOD)%MOD;

                    dp[i][1]=(dp[i][1]+dp[i-1][0])%MOD;
                }
                else
                {
                    if(a[i]==1) dp[i][1]=(dp[i][1]+dp[i-1][0])%MOD;
                    else
                    {
                        for(int pre=0;pre<=1;pre++)
                            dp[i][0]=(dp[i][0]+dp[i-1][pre])%MOD;
                    }
                }
            }
        }

        del=(del+dp[n][0])%MOD;
    }

    LL ans=(qpow(m,unknown)-del)%MOD;
    cout<<(ans+MOD)%MOD<<endl;
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