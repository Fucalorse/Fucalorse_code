#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=5e5,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

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

struct interval
{
    LL val;
    LL interval_cnt;
    bool operator<(const interval &a)const { return val<a.val; }
}op[MAX];

int n,m;
int a[MAX],k[MAX],L[MAX],R[MAX];
LL fac[MAX],fac_inv[MAX];

LL C(int n,int m) { return fac[n]*fac_inv[n-m]%MOD*fac_inv[m]%MOD; }
LL A(int n,int m) { return fac[n]*fac_inv[n-m]%MOD; }

void create()
{
    fac[0]=1;
    for(int i=1;i<=LEN;i++)
        fac[i]=fac[i-1]*i%MOD;

    fac_inv[LEN]=qpow(fac[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        fac_inv[i]=fac_inv[i+1]*(i+1)%MOD;
}

void cal_L()
{
    vector<int>st;
    for(int i=n;i>=1;i--)
    {
        while(st.size()&&a[i]<a[st.back()])
        {
            L[st.back()]=i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while(st.size())
    {
        L[st.back()]=0;
        st.pop_back();
    }
}

void cal_R()
{
    vector<int>st;
    for(int i=1;i<=n;i++)
    {
        while(st.size()&&a[i]<=a[st.back()])
        {
            R[st.back()]=i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while(st.size())
    {
        R[st.back()]=n+1;
        st.pop_back();
    }
}

void solve()
{
    cin>>n>>m;

    LL base=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        LL now=1LL*i*(n-i+1)%MOD*qpow(a[i],MOD-2)%MOD;
        base=(base+now)%MOD;
    }
    for(int i=1;i<=m;i++)
        cin>>k[i];

    cal_L(),cal_R();
    for(int i=1;i<=n;i++)
    {
        LL interval_cnt=1LL*(i-L[i])*(R[i]-i)%MOD;
        op[i]={a[i],interval_cnt};
    }
    sort(op+1,op+n+1);

    vector<LL>small(n+1,0LL),big(n+1,0LL),sum_len(n+1,0LL);
    for(int i=1;i<=n;i++)
    {
        small[i]=(small[i-1]+qpow(op[i].val,MOD-2)*op[i].interval_cnt%MOD)%MOD;
        big[i]=(big[i-1]+(2-op[i].val)*op[i].interval_cnt%MOD)%MOD;
        big[i]=(big[i]+MOD)%MOD;
        sum_len[i]=(sum_len[i-1]+op[i].interval_cnt)%MOD;
    }

    for(int i=1,l=1,r=1;i<=m;i++)
    {
        while(l<=n&&k[i]+1>op[l].val) l++;
        if(r<l) r=l;
        if(k[i]+1==op[l].val)
        {
            while(r<=n&&op[l].val==op[r].val) ++r;
        }
        
        LL ans=0;
        //left
        {
            LL now=(sum_len[l-1]*k[i]%MOD+big[l-1])%MOD;
            ans=(ans+now)%MOD;
        }

        //middle
        {
            int len_mid=sum_len[r-1]-sum_len[l-1];
            ans=(ans+len_mid)%MOD;
        }

        //right
        {
            LL now=1LL*(1+k[i])*(small[n]-small[r-1])%MOD;
            now=(now+MOD)%MOD;
            ans=(ans+now)%MOD;
        }

        ans=(ans+base-small[n])%MOD;
        ans=(ans+MOD)%MOD;
        cout<<ans<<endl;
    }
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