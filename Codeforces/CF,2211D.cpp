#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=29,G=3,MOD=1e9+7,INF=2e9;

LL qpow(LL a,LL p)
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
LL b[MAX],a[MAX],fac[MAX],inv[MAX];

void create()
{
    const int SIZE=1e5;

    fac[0]=1;
    for(int i=1;i<=SIZE;i++)
        fac[i]=fac[i-1]*i%MOD;

    inv[SIZE]=qpow(fac[SIZE],MOD-2);
    for(int i=SIZE-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL C(int n,int m) { return fac[n]*inv[n-m]%MOD*inv[m]%MOD; }
LL A(int n,int m) { return fac[n]*inv[n-m]%MOD; }

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>b[i];

    vector<int>exist(LEN+1);
    vector<LL>mask(n+3);
    for(int i=n;i>=1;i--)
    {
        for(int k=0;k<=LEN;k++)
            if(exist[k])
            {
                LL now=(1LL<<k)*C(exist[k],i)%MOD;
                b[i]=(b[i]-now+MOD)%MOD;
            }
        
        for(int k=0;k<=LEN;k++)
        {
            if((b[i]>>k)&1)
            {
                mask[i]|=1LL<<k;
                exist[k]=i;
            }
        }
    }

    for(int i=n;i>=1;i--)
    {
        mask[i]|=mask[i+1];
        a[i]=mask[i];
    }

    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}