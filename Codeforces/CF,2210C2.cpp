#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e5,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int minp[MAX];
vector<int>op,nop;

void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
            if((int)op.size()==20) break;
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }

    nop.push_back(1);
    for(auto &cur:op)
        nop.push_back(cur);
}

template <typename T>
T __lcm(T a,T b) { return a/__gcd(a,b)*b; }

int n;
LL a[MAX],b[MAX],f[MAX],num[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    
    a[0]=num[0]=1;
    for(int i=0;i<n;i++)
        f[i]=__gcd(a[i],a[i+1]);

    vector<vector<int>>dp(n+1,vector<int>(21,-INF));
    dp[0][0]=0;

    for(int i=1;i<=n;i++)
    {
        LL lcm=1;
        if(i>1) lcm=__lcm(lcm,f[i-1]);
        if(i<n) lcm=__lcm(lcm,f[i]);
        num[i]=lcm<=b[i]?lcm:a[i];

        for(int u=0;u<(int)nop.size();u++)
        {
            if(dp[i-1][u]==-INF) continue;
            int pre=nop[u];
            LL pre_num=1LL*pre*num[i-1];

            if(__gcd(pre_num,num[i])==f[i-1])
                dp[i][0]=max(dp[i][0],dp[i-1][u]+(num[i]!=a[i]));
            for(int v=0;v<(int)op.size();v++)
            {
                int cur=op[v];
                LL cur_num=1LL*cur*num[i];
                if(cur_num>b[i]) break;
                if(cur_num!=a[i]&&__gcd(pre_num,cur_num)==f[i-1])
                    dp[i][v+1]=max(dp[i][v+1],dp[i-1][u]+1);
            }
        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<=20;j++)
    //         cout<<dp[i][j]<<' ';
    //     cout<<endl<<endl;
    // }

    int ans=0;
    for(int i=0;i<=20;i++)
        ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}