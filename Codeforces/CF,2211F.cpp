#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e6+90,LEN=2e6,G=3,MOD=676767677,INF=2e9;
const LL LINF=1e18;

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

struct interval { int l,r; };

int n,m;
LL fac[MAX],inv[MAX];

void create()
{
    fac[0]=1;
    for(int i=1;i<=LEN;i++)
        fac[i]=fac[i-1]*i%MOD;

    inv[LEN]=qpow(fac[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL C(int n,int m)
{
    if(n<0||m<0||m>n) return 0LL;
    return fac[n]*inv[n-m]%MOD*inv[m]%MOD;
}
LL A(int n,int m) { return fac[n]*inv[n-m]%MOD; }

void solve()
{
    cin>>n>>m;

    auto cal=[&](const interval& left,const interval& right)
    {
        auto [la,ra]=left;
        auto [lb,rb]=right;

        LL con1=C(n-lb+ra-1+m,n-lb+ra),con2=0,con3=0,con4=0;
        if(rb<n) con2=C(ra-1+n-rb-1+m,ra-1+n-rb);
        if(la>1) con3=C(la-2+n-lb+m,la-1+n-lb);
        if(rb<n&&la>1) con4=C(la-2+n-rb-1+m,la-2+n-rb);

        return ((con1-con2-con3+con4)%MOD+MOD)%MOD;
    };

    LL ans=0;
    auto dfs=[&](auto &&self,int l,int r,int L,int R,int cnt)->void
    {   
        if(l>r) return;

        int mid=(l+r)>>1;
        interval left={L+1,mid},right={mid,R-1};
        ans=(ans+cal(left,right)*cnt%MOD)%MOD;
        if(l==r) return;

        self(self,l,mid-1,L,min(R,mid),cnt+1);
        self(self,mid+1,r,max(L,mid),R,cnt+1);
    };
    dfs(dfs,1,n,0,n+1,1);

    cout<<ans<<endl;
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