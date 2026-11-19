#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,mod=998244353;

int t,n;
LL a[MAX],b[MAX],sa[MAX],sb[MAX];

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

LL inv(LL a) { return cal(a,mod-2); }

void clear()
{
    for(int i=1;i<=2*n;i++)
        a[i]=b[i]=sa[i]=sb[i]=0;
}

void solve()
{
    cin>>n;
    clear();
    for(int i=n-1;i>=1;i--)
    {
        LL now=inv(2*i);
        a[i]=(now*(1-sa[2*i+1])%mod+mod)%mod,b[i]=((1-now*sb[2*i+1])%mod+mod)%mod;
        sa[i]=(sa[i+1]+a[i])%mod,sb[i]=(sb[i+1]+b[i])%mod;
    }
    LL s=sb[1]*inv(((1-sa[1])%mod+mod)%mod)%mod;
    cout<<(a[1]*s+b[1])%mod<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}