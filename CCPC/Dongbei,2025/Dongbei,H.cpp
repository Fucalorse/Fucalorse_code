#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n;
int a[MAX];
LL b[MAX],c[MAX],op[MAX],sumb;

bool check(const LL &mid)
{
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        op[i]=mid/c[i];
        sum+=op[i];
    }
    if(sum<sumb) return false;
    for(int i=1;i<=n;i++)
        if(sum-op[a[i]]<b[i]) return false;
    return true;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    sumb=accumulate(b+1,b+n+1,0LL);
    LL l=0,r=1e13;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}