#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=30,LEN=22,MOD=998244353,INF=2e9;

LL cal(LL a,int p)
{
    LL ans=1;

    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }

    return ans;
}

int n;
LL f[MAX],dp[1<<23],inv[MAX];
int a[MAX],pre[MAX];

void create()
{
    f[0]=1;
    for(int i=1;i<=LEN;i++)
        f[i]=f[i-1]*i%MOD;

    inv[LEN]=cal(f[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

void solve()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
        cin>>a[i];

    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j])
            {
                pre[i-1]|=1<<(j-1);
                ++cnt;
            }

    if(!cnt)
    {
        cout<<f[n]<<endl;
        return;
    }

    dp[0]=1;
    int len=1<<n;
    for(int s=0;s<len;s++)
        for(int u=0;u<n;u++)
        {
            if((s>>u)&1) continue;

            if((pre[u]&s)==pre[u])
            {
                int mask=s|(1<<u);
                dp[mask]=(dp[mask]+dp[s])%MOD;
            }
        }

    // for(int i=0;i<len;i++)
    //     cout<<dp[i]<<' ';
    // cout<<endl;

    cout<<dp[len-1]*2%MOD<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}