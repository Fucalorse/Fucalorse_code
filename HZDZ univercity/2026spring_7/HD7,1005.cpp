#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define endl '\n'
const int MAX=2e5+90;

int t,n,k;
LL a[MAX],sum[MAX];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    if(k*2<n)
    {
        vector<LL>suf(n+3,0),pre(n+3,0);
        for(int i=k;i<=n;i++)
            pre[i]=max(pre[i-1],sum[i]-sum[i-k]);
        for(int i=n-k+1;i>=1;i--)
            suf[i]=max(suf[i+1],sum[i+k-1]-sum[i-1]);
        LL ans=0;
        for(int i=k;i<=n-k;i++)
            ans=max(ans,pre[i]+suf[i+1]);
        cout<<ans+(LL)(1+k)*k<<endl;
    }
    else
    {
        LL l=n/2,r=(n+1)/2;
        LL ans=sum[n]+(k-l+1+k)*(l)/2+(k-r+1+k)*r/2;
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}