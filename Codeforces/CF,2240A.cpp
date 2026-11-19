#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,k;

void solve()
{
    cin>>n>>k;

    int bit=0;
    while(1)
    {
        int each=(1<<(bit+1))-1;
        if(each*k>n) break;
        ++bit;
    }

    LL each=(1LL<<bit)-1;
    LL ans=bit*k,rest=n-each*k;
    ans+=rest/(1LL<<bit);

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