#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e6+90,LEN=2e6,MOD=998244353,INF=2e9;

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

int n,m,c,a,b;
LL f[MAX],inv[MAX];

LL C(int n,int m) { return f[n]*inv[n-m]%MOD*inv[m]%MOD; }

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
    cin>>n>>m>>c>>a>>b;

    if(m<n||(m-n)%c!=0)
    {
        cout<<0<<endl;
        return;
    }

    int k=(m-n)/c;
    LL ans=n*qpow(m,MOD-2)%MOD*C(m,k)%MOD*qpow(a,k)%MOD*qpow(b-a,m-k)%MOD*qpow(qpow(b,m),MOD-2)%MOD;

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