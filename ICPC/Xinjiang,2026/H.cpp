#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=2090,inf=2e9,mod=998244353,LEN=2000;

int n,k;
LL x[MAX],y[MAX],f[MAX],inv[MAX];

LL cal(LL a,int p)
{
    LL ans=1;
    
    while(p)
    {
        if(p&1) ans=ans*a%mod;
        a=a*a%mod;
        p>>=1;
    }

    return ans;
}

void create()
{
    f[0]=f[1]=1;
    for(int i=2;i<=LEN;i++)
        f[i]=f[i-1]*i%mod;
    
    inv[LEN]=cal(f[LEN],mod-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
}

LL C(int n,int m) { return f[n]*inv[n-m]%mod*inv[m]%mod; }

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        LL a,b,c,d;

        cin>>a>>b>>c>>d;

        x[i]=(a*c%mod+b*(d-c)%mod)%mod*cal(d,mod-2)%mod;
        y[i]=(b*c%mod+a*(d-c)%mod)%mod*cal(d,mod-2)%mod;
    }

    vector<LL>dp(k+1,0);
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        vector<LL>ndp(k+1,0);

        for(int j=0;j<=k;j++)
        {
            ndp[j]=dp[j]*x[i]%mod;
            if(j>0) ndp[j]=(ndp[j]+dp[j-1]*y[i]%mod)%mod;
        }

        dp=ndp;
    }

    LL ans=dp[k]*cal(C(n,k),mod-2)%mod;

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    solve();

    return 0;
}

// g++ H2.cpp -O2 -o out.exe && out.exe < in.txt