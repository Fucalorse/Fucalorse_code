#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9,LEN=100;

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

int T,n;
LL k,a[MAX],f[MAX],inv[MAX];

LL gcd(LL a,LL b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

LL lcm(LL a,LL b) { return a/gcd(a,b)*b; }

void create()
{
    f[0]=1;
    for(int i=1;i<=LEN;i++)
        f[i]=f[i-1]*i%MOD;

    inv[LEN]=qpow(f[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL cal(const vector<LL>& y,LL x)
{
    int m=y.size();

    if(x<m) return y[x];

    x%=MOD;
    vector<LL>pre(m+1,0),suf(m+1,0);
    pre[0]=suf[m]=1;
    for(int i=0;i<m;i++)
    {
        LL val=(x-i+MOD)%MOD;
        pre[i+1]=pre[i]*val%MOD;
    }

    for(int i=m-1;i>=0;i--)
    {
        LL val=(x-i+MOD)%MOD;
        suf[i]=suf[i+1]*val%MOD;
    }

    LL ans=0;
    for(int i=0;i<m;i++)
    {
        LL now=pre[i]*suf[i+1]%MOD;

        LL term=y[i]*now%MOD*inv[i]%MOD*inv[m-i-1]%MOD;

        if((m-i-1)&1) term=(-term+MOD)%MOD;
        ans=(ans+term)%MOD;
    }

    return ans;
}

void solve()
{
    cin>>n>>k;

    int L=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        L=lcm(L,a[i]);
    }

    int limit=n*L;
    vector<LL>f(limit+1,0);
    f[0]=1;

    for(int i=1;i<=n;i++)
        for(int s=a[i];s<=limit;s++)
            f[s]=(f[s]+f[s-a[i]])%MOD;

    LL r=k%L,q=k/L;
    vector<LL>y(n);
    for(int i=0;i<n;i++)
        y[i]=f[i*L+r];

    cout<<cal(y,q)<<endl;    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    cin>>T;
    while(T--) solve();

    return 0;
}