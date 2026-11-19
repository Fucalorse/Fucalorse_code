#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=2e5,G=3,MOD=998244353,INF=2e9;

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
LL a[MAX],f[MAX],fac[MAX],inv[MAX];

void create()
{
    fac[0]=1;
    for(int i=1;i<=LEN;i++)
        fac[i]=fac[i-1]*i%MOD;

    inv[LEN]=qpow(fac[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL C(int n,int m) { return fac[n]*inv[n-m]%MOD*inv[m]%MOD; }
LL A(int n,int m) { return fac[n]*inv[n-m]%MOD; }

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1,greater<LL>());

    for(int i=1;i<=n;i++)
        f[i]=(f[i-1]+a[i])%MOD;

    LL ans=0;
    for(int i=2;i<=n;i++)
    {
        LL base=fac[i-2]*A(n-1,n-i)%MOD;
        LL now=(f[i-1]-a[i]*(i-1)%MOD)%MOD*base%MOD;
        // cout<<base<<' '<<now<<endl;
        now=(now+MOD)%MOD;
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