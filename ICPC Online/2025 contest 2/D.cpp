#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=998244353;

LL cal(LL a,int p)
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
LL a[MAX],f[MAX],inv[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);

    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        LL now=(cal(3,i-1)+1)*cal(2,MOD-2)%MOD*cal(2,n-i)%MOD;
        ans=(ans+now*a[i]%MOD)%MOD;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}