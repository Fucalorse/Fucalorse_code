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

int T;
LL n,m;

void solve()
{
    cin>>n>>m;

    LL q=cal(2,m);
    LL x=(q-1+MOD)%MOD;

    LL ans=cal(x,n-1);

    if(n%2==0)
    {
        LL extra=cal(q-1,n/2);

        if((n/2)&1) extra=-extra;

        ans=(ans+extra+MOD)%MOD;
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