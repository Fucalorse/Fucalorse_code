#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=105,LEN=100,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

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

int n,m;
int p[MAX],v[MAX];
LL f[MAX][MAX][LEN*LEN+1];

void create()
{
    f[0][0][0]=1;
    for(int L=1;L<=LEN;L++)
        for(int K=0;K<=L;K++)
            for(int S=0;S<=(1+L)*L/2;S++)
            {
                f[L][K][S]=f[L-1][K][S];
                if(K>=1&&S>=L) f[L][K][S]=(f[L][K][S]+f[L-1][K-1][S-L])%MOD;
            }
}

void solve()
{
    cin>>n>>m;

    p[0]=1,v[0]=0;
    vector<LL>dp(n+1,0LL),ndp(n+1,0LL);
    dp[0]=1;

    for(int i=1;i<=m;i++)
    {
        cin>>p[i]>>v[i];

        fill(ndp.begin(),ndp.end(),0LL);
        int L=p[i]-p[i-1];
        for(int h=0;h<=n;h++)
            for(int k=0;k<=L;k++)
            {
                if(k+h>n) break;

                int dx=v[i]-v[i-1]-h*L;
                if(dx>=0&&dx<=(1+L)*L/2) ndp[h+k]=(ndp[h+k]+dp[h]*f[L][k][dx]%MOD)%MOD;
            }

        swap(dp,ndp);
    }

    if(!m)
    {
        cout<<qpow(2,n-1)<<endl;
        return;
    }

    LL ans=0;
    for(int h=0;h<=n;h++)
        ans=(ans+dp[h])%MOD;

    ans=ans*qpow(2,n-p[m])%MOD;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}