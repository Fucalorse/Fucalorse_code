#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define endl '\n'
const int MAX=2e5+90;
const LL inf=1e17;

int t,n,l,r;
LL op[MAX],f[MAX];

LL cal(const LL &b,const LL &k) { return min(b+l*k,b+r*k); }

void peach()
{
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
        cin>>op[i];
    sort(op+1,op+n+1);
    f[0]=0;
    for(int i=1;i<=n;i++)
        f[i]=f[i-1]+op[i];
    LL ans=-inf;
    for(LL k=-n;k<=n;k++)
    {
        LL a=(n-k)/2,b=k+a;
        LL now=f[n]-f[n-a]-f[b];
        ans=max(ans,cal(now,k));
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) peach();
    return 0;
}