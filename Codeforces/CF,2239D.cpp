#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e6,G=3,MOD=998244353,INF=2e9;

LL qpow(LL a,int p)
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
LL f[MAX],inv[MAX];

LL C(int n,int m) { return f[n]*inv[m]%MOD*inv[n-m]%MOD; }

void create()
{
    f[0]=1;
    for(int i=1;i<=LEN;i++)
        f[i]=f[i-1]*i%MOD;

    inv[LEN]=qpow(f[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

void solve()
{
    cin>>n>>m;

    LL ans=0,base=C(n,m)*(n-1)%MOD;
    for(int j=0;j<=n-m;j++)
    {
        LL now=C(n-m,j)*qpow(m-1+j,n-1)%MOD*base%MOD;
        if((n-m-j)&1) now=(-now+MOD)%MOD;
        ans=(ans+now)%MOD;
    }

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