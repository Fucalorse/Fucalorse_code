#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e7+90,LEN=1e7,MOD=998244353;
const LL INF=1e18;

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int l,r,n;
LL dp[MAX];
int minp[MAX],mu[MAX],pre[MAX];
vector<int>op;

void oula(int n)
{
    mu[1]=1;
    minp[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            mu[i]=-1;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            
            minp[i*j]=j;
            if(i%j==0) break;
            mu[i*j]=-mu[i];
        }
    }

    int len=op.size();
    for(int i=2,pos=0;i<=n;i++)
    {
        while(pos<len&&op[pos]<=i) ++pos;
        pre[i]=op[pos-1];
    }
}

LL cal(int p)
{
    if(p<l) return 0LL;

    LL cnt=0;

    auto update=[&](int x)
    {
        if(x<=p) cnt+=(p/x-(l-1)/x)*mu[x];
    };

    for(int i=1;i*i<=n;i++)
    {
        if(n%i!=0) continue;

        update(i);
        if(i*i!=n) update(n/i);
    }

    return 2LL*(p-l+1)-cnt;
}

void solve()
{
    cin>>l>>r>>n;

    if(minp[n]==n) cout<<r-l+1<<endl;
    else
    {
        int p=pre[n];
        LL cost1=cal(min(p,r)),cost2=0;

        if(r>p)
        {
            for(int i=n-1;i>p;i--)
                dp[i]=INF;
            dp[n]=0;

            for(int i=n;i>p;i--)
                for(int j=n;j>i;j--)
                    dp[i]=min(dp[i],gcd(i,j)+dp[j]);

            for(int i=max(l,p+1);i<=r;i++)
                cost2+=dp[i];
        }

        cout<<cost1+cost2<<endl;
    }
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