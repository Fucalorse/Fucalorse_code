#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

LL n,k;

void solve()
{
    cin>>n>>k;

    LL now=1;
    while(now<=n)
    {
        LL d=(now+k-2)/(k-1);
        LL cnt=min((d*(k-1)-now)/d+1,(n-now)/d);
        if(!cnt) break;
        now+=d*cnt;
    }

    cout<<now<<endl;
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