#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5090,MOD=998244353,LEN=1000;

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

struct edge
{
    int u,v;
}op[MAX];

int n,m;
LL P[MAX],f[MAX],inv[MAX],pre[MAX],suf[MAX];

void create()
{
    f[0]=1;
    for(int i=1;i<=LEN;i++)
        f[i]=f[i-1]*i%MOD;
    
    inv[LEN]=cal(f[LEN],MOD-2);
    for(int i=LEN-1;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL ask(int s,int t,int c)
{
    cout<<'?'<<' '<<s<<' '<<t<<' '<<c<<endl<<flush;

    LL val;
    cin>>val;

    return val;
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
        cin>>op[i].u>>op[i].v;

    for(int i=1;i<=n-1;i++)
        P[i]=ask(1,n,i);

    cout<<'!'<<endl<<flush;

    LL k;
    cin>>k;

    for(int i=0;i<=n-1;i++)
    {
        pre[i]=((k-i)%MOD+MOD)%MOD;
        if(i>0) pre[i]=((pre[i-1]*pre[i]%MOD)+MOD)%MOD;
    }

    for(int i=n-1;i>=0;i--)
    {
        suf[i]=((k-i)%MOD+MOD)%MOD;
        if(i!=n-1) suf[i]=((suf[i+1]*suf[i]%MOD)+MOD)%MOD;
    }

    LL ans=0;
    for(int i=0;i<=n-1;i++)
    {
        LL up,down;

        if(i==0)
        {
            up=suf[i+1];
            down=f[n-1];
            if((n-1)&1) down=(-down+MOD)%MOD;
        }
        else if(i==n-1)
        {
            up=pre[i-1];
            down=f[n-1];
        }
        else
        {
            up=pre[i-1]*suf[i+1]%MOD;
            down=f[i]*f[n-i-1]%MOD;
            if((n-i-1)&1) down=(-down+MOD)%MOD;
        }

        LL now=P[i]*up%MOD*cal(down,MOD-2)%MOD;
        ans=(ans+now)%MOD;
    }

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