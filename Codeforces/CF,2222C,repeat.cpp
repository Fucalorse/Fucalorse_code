#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
int a[MAX],b[MAX],f[MAX],g[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }

    sort(b+1,b+n+1);
    int x=b[(n+1)>>1];

    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        g[i]=g[i-1];
        if(a[i]<x) f[i]++;
        else if(a[i]>x) g[i]++;
    }

    vector<int>dp(n+1,-INF);
    dp[0]=0;

    for(int i=1;i<=n;i++)
        for(int j=i;j>=1;j-=2)
        {
            int len=i-j+1,small=f[i]-f[j-1],big=g[i]-g[j-1];
            if(len-small-big>abs(small-big)&&dp[j-1]!=-INF) dp[i]=max(dp[i],dp[j-1]+1);
        }

    cout<<dp[n]<<endl;
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