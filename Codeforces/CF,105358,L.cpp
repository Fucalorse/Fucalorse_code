#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

LL n;

pair<LL,LL> cal(LL x)
{
    LL p=2*n+x*x-x,q=2*x;
    LL r=__gcd(p,q);

    return {p/r,q/r};
}

void solve()
{
    cin>>n;

    LL best=sqrt(2*n);
    auto ans1=cal(best),ans2=cal(best+1);

    if(ans1.first*ans2.second<ans1.second*ans2.first) cout<<ans1.first<<' '<<ans1.second<<endl;
    else cout<<ans2.first<<' '<<ans2.second<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}