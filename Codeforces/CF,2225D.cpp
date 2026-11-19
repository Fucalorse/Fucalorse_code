#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;
const LL mod=998244353;

int t;
LL n,x;

void solve()
{
    cin>>n>>x;
    LL a=(x+2)/4%mod*((n+3)/4%mod-(x+2)/4%mod+mod)%mod;
    LL b=(x/4%mod+1)%mod*((n+1)/4%mod-x/4%mod+mod)%mod;
    cout<<(a+b)%mod<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}