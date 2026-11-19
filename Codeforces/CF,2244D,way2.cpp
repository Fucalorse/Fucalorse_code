#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7;
const LL INF=1e18;

int n,m;
int b[MAX];
LL a[MAX],sum[MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }

    for(int i=1;i<=m;i++)
        cin>>b[i];

    sort(b+1,b+m+1);

    LL ans=sum[n]-sum[b[m]];
    for(int i=1;i<=m;i++)
    {
        LL now=sum[b[i]]-sum[b[i-1]];
        ans+=llabs(now);
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