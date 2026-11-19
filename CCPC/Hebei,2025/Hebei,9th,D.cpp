#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int n;
LL a[MAX],s[MAX],k;

LL cal(const LL &mid)
{
    LL ans=0;
    for(int l=1,r=1;l<=n;l++)
    {
        while(r<=n&&a[r]-a[l]<=mid) r++;
        ans+=r-l-1;
    }
    return ans;
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];

    LL l=0,r=a[n]-a[1];
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        LL now=cal(mid);
        if(now>=k) r=mid-1;
        else l=mid+1;
    }
    // cout<<l<<endl;
    // cout<<cal(l)<<endl;

    LL cnt=0,ans=0;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n&&a[j]-a[i]<l) j++;
        int st=i,ed=j-1;
        ans+=(s[ed]-s[st])-a[st]*(ed-st);
        cnt+=ed-st;
    }
    ans+=(k-cnt)*l;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}