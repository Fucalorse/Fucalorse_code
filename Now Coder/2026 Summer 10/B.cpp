#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

LL n,m,k;

void solve()
{
    cin>>n>>m>>k;

    LL p=m*k*(2*n+k-1),q=2*(n+k);

    cout<<fixed<<setprecision(20);
    cout<<1.00*p/q<<endl;
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