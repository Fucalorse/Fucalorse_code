#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,d;
LL a[MAX],sum[MAX];

void solve()
{
    cin>>n>>d;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i+2*n]=a[i];
    }

    for(int i=1;i<=3*n;i++)
        sum[i]=sum[i-1]+a[i];

    LL ans=0;

    for(int i=1,l=n+1-d,r=n+1+d;i<=n;i++,l++,r++)
    {
        LL add=a[i],sub=sum[r]-sum[l-1]-a[i];
        LL now=add*2*d-sub;
        if(now>0) ans+=now;
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