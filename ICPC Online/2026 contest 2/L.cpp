#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353;
const LL INF=1e18;

int n;
LL a[MAX],f[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    if(n==1)
    {
        cout<<a[1]<<endl;
        return;
    }

    if(n==2)
    {
        cout<<2*a[1]+a[2]<<endl;
        return;
    }

    int m=n+1;
    a[n+1]=a[1];

    vector<LL>pre(m+3,INF),suf(m+3,INF);
    for(int i=1;i<=m;i++)
        f[i]=f[i-1]+a[i];

    for(int i=1;i<m;i++)
    {
        LL now=a[i]+a[i+1];
        pre[i]=min(pre[i-1],now);
    }

    for(int i=m;i>1;i--)
    {
        LL now=a[i]+a[i-1];
        suf[i]=min(suf[i+1],now);
    }

    LL minn=INF;
    for(int i=2;i<=n;i++)
    {
        LL now=(f[i-1]-f[1])*2+2*a[1]+a[i];
        now+=(n-i)*pre[i-1];
        minn=min(minn,now);
    }

    for(int i=m-1;i>1;i--)
    {
        LL now=(f[n]-f[i])*2+2*a[1]+a[i];
        now+=(n-1-m+i)*suf[i+1];
        minn=min(minn,now);
    }

    cout<<minn<<endl;
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