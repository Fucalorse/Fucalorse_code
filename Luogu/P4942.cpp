#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i128 __int128_t
#define LL long long
const int MAX=2e5+90,mod=9;

int t;
LL l,r;

void solve()
{
    cin>>l>>r;
    i128 ans=((i128)l+r)*((i128)r-l+1)/2%mod;
    cout<<(LL)ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}