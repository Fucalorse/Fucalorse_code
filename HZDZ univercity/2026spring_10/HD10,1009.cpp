#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e7+90,mod=1e9+7,LEN=1e7;

LL cal(LL a,int p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=ans*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ans;
}

int t,n;
LL f[MAX],INV[MAX];

LL inv(LL a) { return cal(a,mod-2); }

void create()
{
    f[1]=1;
    for(int i=2;i<=LEN;i++)
        f[i]=f[i-1]*i%mod;
    INV[LEN]=inv(f[LEN]);
    for(int i=LEN-1;i>=1;i--)
        INV[i]=INV[i+1]*(i+1)%mod;
}

LL C(LL n,LL m) { return f[n]*INV[n-m]%mod*INV[m]%mod; }

void solve()
{
    cin>>n;
    LL ans=inv(cal(2,n-1))%mod;
    if(n%2==0) ans=(ans+C(n,n>>1)*inv(cal(2,n))%mod)%mod;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    create();
    cin>>t;
    while(t--) solve();
    return 0;
}