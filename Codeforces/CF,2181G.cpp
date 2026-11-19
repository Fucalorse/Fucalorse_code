#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=1e9;
const LL LINF=9e18;

int n;
LL a[MAX],f[MAX];

void solve()
{
    cin>>n;

    LL max_odd=-LINF,max_even=-LINF,sum=0;
    LL min_odd=LINF,min_even=LINF;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(i&1)
        {
            f[i]=f[i-1]+a[i];
            max_odd=max(max_odd,f[i]);
            min_odd=min(min_odd,f[i]);
        }
        else
        {
            f[i]=f[i-1]-a[i];
            max_even=max(max_even,-f[i]);
            min_even=min(min_even,-f[i]);
        }
    }
    sum>>=1;

    LL l=0,r=min_odd,minn=LINF;
    if(min_even<0) l=-min_even;
    if(n&1) l=r=f[n]>>1;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        LL odd=max_odd-mid,even=max_even+mid;
        minn=min(minn,max(odd,even));
        if(odd>even) l=mid+1;
        else r=mid-1;
    }

    cout<<max((sum+n-2)/(n-1),minn)<<endl;
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