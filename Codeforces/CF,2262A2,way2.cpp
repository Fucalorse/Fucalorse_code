#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=1e9+7,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    vector<int>f(n+3,0),pre(n+3);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        LL l=1LL*i*a[i]+1,r=1LL*(a[i]+1)*i;
        if(l<=n)
        {
            ++f[l];
            --f[min(r+1,1LL*n+1)];
        }
        for(int num=0;num<a[i];num++)
        {
            LL l=1LL*i*num+1,r=1LL*(num+1)*i;
            if(l<=n)
            {
                r=min(1LL*n,r);
                pre[r]=max(pre[r],(int)l);
            }
        }
    }

    LL sum=0;
    int bound=0,pos=0;
    vector<LL>dp(n+1,0LL);
    bool updated=false;
    dp[0]=sum=1;

    for(int i=1;i<=n;i++)
    {
        f[i]+=f[i-1];

        if(f[i]==0)
        {
            dp[i]=(dp[i]+sum)%MOD;
            sum=(sum+dp[i])%MOD;
            updated=true;
        }

        if(updated)
        {
            bound=max(bound,pre[i]);
            while(pos<bound)
            {
                sum=(sum-dp[pos]+MOD)%MOD;
                ++pos;
            }
        }
    }

    cout<<sum<<endl;
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