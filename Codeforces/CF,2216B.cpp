#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=2e5,MOD=1e9+7,INF=INT_MAX;

LL T,H,U;

void solve()
{
    cin>>T>>H>>U;

    LL ans=0,first=min(T,U);
    ans+=first*4,T-=first,U-=first;

    if(T)
    {
        LL second=min(T>>1,H);
        ans+=second*7,T-=second<<1,H-=second;

        LL trird=min(T,H);
        ans+=trird*5,T-=trird,H-=trird;

        if(T) ans+=2*T+1;
        else ans+=H*3;
    }
    else ans+=(H+U)*3;

    cout<<ans<<endl;
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