#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

LL n,k,m;

void solve()
{
    cin>>n>>k>>m;

    LL multiple_cnt=n/k-1,ans=1,rest=n-(n/k);
    if(m<=rest) ans+=m+multiple_cnt/2;
    else
    {
        ans+=min(m,multiple_cnt+rest);
        multiple_cnt=max(0LL,multiple_cnt-(m-rest));
        ans+=multiple_cnt/2;
    }

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