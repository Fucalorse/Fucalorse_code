#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=3e5,G=3,MOD=998244353,INF=2e9;

int minp[MAX],rad[MAX];
vector<int>op;

void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }

    auto split=[&](int num)
    {
        set<int>st;
        while(num!=1)
        {
            st.insert(minp[num]);
            num/=minp[num];
        }
        return st;
    };

    for(int i=1;i<=n;i++)
    {
        rad[i]=1;
        set<int>st=split(i);
        for(auto &cur:st)
            rad[i]*=cur;
    }
}

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

struct fucalorse
{
    private:
        int n;
        vector<LL>op;
        vector<LL>base;

        void dfs(int l,int r,int id,const int &x,const LL &k)
        {
            if(l==r)
            {
                op[id]=base[l]*k%MOD;
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,k);
            else dfs(mid+1,r,hr,x,k);

            op[id]=(op[hl]+op[hr])%MOD;
        }
    public:
        fucalorse(int _n,const vector<LL>& _base)
        {
            n=_n;
            base=_base;
            op.assign((n+90)<<2,0LL);
        }

        void update(int x,LL k) { dfs(1,n,1,x,k); }

        LL get() { return op[1]; }
};

int n;
int a[MAX];
LL pw2[MAX],fac[MAX],inv[MAX];

void create()
{
    oula(LEN);

    fac[0]=1;
    for(int i=1;i<=LEN;i++)
        fac[i]=fac[i-1]*i%MOD;

    inv[LEN]=qpow(fac[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;

    pw2[0]=1;
    for(int i=1;i<=LEN;i++)
        pw2[i]=pw2[i-1]*2%MOD;
}

void solve()
{
    cin>>n;

    vector<int>cnt(n+1,0),sum(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }

    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+cnt[i];

    vector<LL>L(n+1,0LL),R(n+1,0LL);
    for(int i=1;i<=n;i++)
    {
        L[i]=(pw2[cnt[i]]-1+MOD)%MOD*qpow(pw2[sum[i]],MOD-2)%MOD;
        R[i]=(pw2[cnt[i]]-1+MOD)%MOD*pw2[sum[i-1]]%MOD;
    }

    LL ans=0;
    vector<int>dp(n+1,0);
    fucalorse fu(n,L);

    for(int r=1;r<=n;r++)
    {
        for(int l=rad[r];l<r;l+=rad[r])
        {
            dp[l]=dp[l-1];
            fu.update(l,(LL)dp[l]);
        }

        if(cnt[r])
        {
            LL con1=(pw2[cnt[r]]-1+MOD)%MOD*r%MOD;
            LL con2=R[r]%MOD*fu.get()%MOD;
            ans=(ans+con1+con2)%MOD;
        }

        dp[r]=r;
        fu.update(r,(LL)dp[r]);
    }

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