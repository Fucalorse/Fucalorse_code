#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

LL n,d,s;

void solve()
{
    cin>>n>>d>>s;

    LL A=n/s,B=d/s;

    auto get=[&](LL l)
    {
        LL up1=A/(A/l),up2=B/(B/l);
        return min({up1,up2,B});
    };

    LL ans=s;
    for(LL l=1,r;l<=B;l=r+1)
    {
        r=get(l);
        LL now=s*r*min({A/r,1+B/r});
        ans=max(ans,now);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}