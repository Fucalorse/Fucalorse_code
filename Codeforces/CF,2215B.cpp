#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=60,G=3,MOD=998244353,INF=2e9;

int minp[MAX];
LL fac_cnt[MAX];
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
        map<int,int>f;
        while(num!=1)
        {
            ++f[minp[num]];
            num/=minp[num];
        }

        LL ans=1;
        for(auto &[val,cnt]:f)
            ans*=cnt+1;
        return ans;
    };

    for(int i=2;i<=n;i++)
        fac_cnt[i]=split(i);
}

LL n;

void solve()
{
    cin>>n;

    LL ans=0;
    for(LL i=1;i*i<=n;i++)
    {
        if(n%i!=0) continue;
        if(i*i!=n)
        {
            LL base=n/i-1;
            if(base>=2&&(i128)base*base>n) ++ans;
        }
    }

    auto cal=[&](LL k)
    {
        int g=0,cnt=0;
        LL num=n,pre=-1;

        while(num)
        {
            LL now=num%k;
            if(now==pre) ++cnt;
            else
            {
                g=__gcd(g,cnt);
                pre=now;
                cnt=1;
            }
            num/=k;
        }

        return __gcd(g,cnt);
    };

    for(LL k=2;k*k<=n;k++)
    {
        LL now=cal(k);
        if(now>1) ans+=fac_cnt[now]-1;
    }

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