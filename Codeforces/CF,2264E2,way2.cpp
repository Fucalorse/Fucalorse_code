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

int n;
int a[MAX];
LL pw2[MAX];

void create()
{
    oula(LEN);

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

    LL ans=0,base=0;
    vector<int>dp(n+1,0);

    for(int r=1;r<=n;r++)
    {
        for(int l=rad[r];l<r;l+=rad[r])
        {
            base=(base-dp[l]*L[l]%MOD)%MOD;
            base=(base+dp[l-1]*L[l]%MOD)%MOD;
            base=(base+MOD)%MOD;
            dp[l]=dp[l-1];
        }

        if(cnt[r])
        {
            LL con1=(pw2[cnt[r]]-1+MOD)%MOD*r%MOD;
            LL con2=R[r]%MOD*base%MOD;
            ans=(ans+con1+con2)%MOD;
        }

        dp[r]=r;
        base=(base+dp[r]*L[r]%MOD)%MOD;
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