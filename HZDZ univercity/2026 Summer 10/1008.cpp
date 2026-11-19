#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353;
const LL INF=1e18;

int n;
LL a[MAX],sum[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }

    LL minn=0,total=0;
    vector<LL>suf(n+3,-INF);
    for(int i=n;i>=1;i--)
    {
        total+=a[i];
        suf[i]=max(suf[i+1],total-minn);
        minn=min(minn,total);
    }

    LL maxn=-INF;
    for(int i=1;i<=n;i++)
    {
        LL now=sum[i-1]+suf[i];
        maxn=max(maxn,now);
    }

    cout<<maxn<<endl;
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