#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,q;
int a[MAX];

void solve()
{
    cin>>n>>q;

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(__builtin_popcount(a[i])%2==0) ++ans;
    }

    auto update=[&](int p,int x)
    {
        if(__builtin_popcount(a[p])%2==0) --ans;
        if(__builtin_popcount(x)%2==0) ++ans;
        a[p]=x;
    };

    cout<<ans<<' ';
    while(q--)
    {
        int p,x;
        cin>>p>>x;
        
        update(p,x);
        cout<<ans<<' ';
    }
    cout<<endl;
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