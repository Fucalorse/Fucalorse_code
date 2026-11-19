#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;
const LL inf=1e18;

int t,n,k,p,q;
LL a[MAX],f[MAX],g[MAX],op[MAX];

void solve()
{
    cin>>n>>k>>p>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i]%p;
        g[i]=g[i-1]+a[i]%q%p;
        op[i]=op[i-1]+min(f[i]-f[i-1],g[i]-g[i-1]);
    }
    LL ans=inf;
    for(int l=1,r=k;r<=n;l++,r++)
    {
        LL numl=op[l-1]-op[0],numr=op[n]-op[r],mid=min(f[r]-f[l-1],g[r]-g[l-1]);
        ans=min(ans,numl+numr+mid);
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}