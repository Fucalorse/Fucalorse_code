#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,m;
int a[MAX];

void solve()
{
    cin>>n>>m;

    vector<LL>cnt(m+1,0),f(m+3,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }

    for(int i=1;i<=m;i++)
        f[i]=f[i-1]+cnt[i];

    LL ans=-INF;
    for(int each=1;each<=m;each++)
    {
        LL now=f[m]-f[each-1];
        if(each*2<=m) now+=cnt[each*2];
        ans=max(ans,now);
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