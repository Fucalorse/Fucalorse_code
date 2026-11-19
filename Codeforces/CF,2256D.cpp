#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e6,MOD=998244353,INF=2e9;

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

int n;
LL f[MAX],inv[MAX];
string s;

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
    cin>>n>>s;s=' '+s;

    int c0=0,c1=0,f0=0,f1=0;
    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&s[l]==s[r]) ++r;
        if(s[l]=='0')
        {
            ++f0;
            c0+=r-l;
        }
        else
        {
            ++f1;
            c1+=r-l;
        }
    }

    LL ans=1;
    if(c0) ans=ans*C(c0-1,f0-1)%MOD;
    if(c1) ans=ans*C(c1-1,f1-1)%MOD;
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