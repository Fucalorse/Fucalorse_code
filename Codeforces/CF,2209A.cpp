#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int n;
LL c,k;
LL a[MAX];

void solve()
{
    cin>>n>>c>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);

    LL ans=c;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>ans) break;
        LL dx=min(k,ans-a[i]);
        a[i]+=dx;
        k-=dx;
        ans+=a[i];
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