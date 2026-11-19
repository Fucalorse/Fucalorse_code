#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int n;
int a[MAX],f[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n-4;i++)
        f[i]=a[i]+a[i+2]-a[i+4];

    LL ans=0;
    map<int,LL>cnt;
    for(int i=1;i<=n-4;i++)
    {
        if(i-6>=1) ++cnt[f[i-6]];

        if(i-1>=1&&f[i]==f[i-1]) ++ans;
        if(i-3>=1&&f[i]==f[i-3]) ++ans;
        if(i-5>=1&&f[i]==f[i-5]) ++ans;
        ans+=cnt[f[i]];
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