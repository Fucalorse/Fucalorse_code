#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m;

void solve()
{
    cin>>n>>m;

    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    vector<pair<int,int>>ans={{2,min(3,n)}};
    for(int l=3;l<n;l+=2)
        ans.push_back({l,min(l+2,n)});
    if(n&1) ans.push_back({n,n});

    cout<<ans.size()<<endl;
    for(auto &[l,r]:ans)
        cout<<l<<' '<<r<<endl;
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