#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=30,G=3,MOD=998244353,INF=2e9;

LL x,y;

void solve()
{
    cin>>x>>y;

    LL sum=x+y,ans=0;
    for(int k=LEN;k>=0;k--)
        if((sum>>k)&1)
        {
            LL now=ans|(1LL<<k);
            if(now<=x) ans=now;
        }

    cout<<x+y<<' '<<x-ans<<endl;
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