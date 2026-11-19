#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,mod=998244353;

int t,n;
LL a[MAX],b[MAX],sum[MAX];

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

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    LL total=0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        total=(total+b[i])%mod;
        sum[i]=(sum[i-1]+b[i])%mod;
    }
    LL ans=0,now=cal(2,mod-2);
    for(int i=1;i<=n;i++)
    {
        ans=(ans+a[i]*b[i]%mod*now%mod)%mod;
        ans=(ans+sum[i-1]*a[i]%mod)%mod;
    }
    cout<<ans*cal(total,mod-2)%mod<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}