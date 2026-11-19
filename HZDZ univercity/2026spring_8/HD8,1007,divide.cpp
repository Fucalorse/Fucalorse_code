#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,mod=1e9+7;

struct qwq
{
    int l,r;
}op[MAX];

int T,n;
int h[MAX],t[MAX];

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

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i]>>t[i];
    LL ans=0,inv2=cal(2,mod-2),inv3=cal(3,mod-2);

    auto sum=[&](qwq a,qwq b)
    {
        if(a.l==a.r||b.l==b.r) return llabs(1LL*b.l+b.r-a.l-a.r)%mod*inv2%mod;
        if(a.l>b.l) swap(a,b);
        LL ans;
        if(b.l>=a.r) ans=(1LL*b.l+b.r-a.l-a.r)%mod*inv2%mod;
        else ans=(1LL*b.r-b.l)%mod*inv3%mod;
        return (ans+mod)%mod;
    };

    for(int i=2;i<=n;i++)
    {
        qwq pre={h[i-1],t[i-1]},now={h[i],t[i]};
        if(pre.l>now.l||(pre.l==now.l&&pre.r>now.r)) swap(pre,now);
        
        if(now.l>=pre.r) ans=(ans+sum(pre,now))%mod;
        else
        {
            vector<qwq>f,g;
            if(now.r>=pre.r)
            {
                if(now.l-pre.l) f.push_back({pre.l,now.l});
                if(pre.r-now.l) f.push_back({now.l,pre.r}),g.push_back({now.l,pre.r});
                if(now.r-pre.r) g.push_back({pre.r,now.r});
            }
            else
            {
                if(now.l-pre.l) f.push_back({pre.l,now.l});
                if(now.r-now.l) f.push_back({now.l,now.r}),g.push_back({now.l,now.r});
                if(pre.r-now.r) f.push_back({now.r,pre.r});
            }

            if(pre.l==pre.r) f.push_back(pre);
            if(now.l==now.r) g.push_back(now);
            LL invp=cal(1LL*pre.r-pre.l,mod-2);
            LL invn=cal(1LL*now.r-now.l,mod-2);
            for(auto &i:f)
                for(auto &j:g)
                {
                    LL p1=i.r-i.l?(1LL*i.r-i.l)%mod*invp%mod:1;
                    LL p2=j.r-j.l?(1LL*j.r-j.l)%mod*invn%mod:1;
                    ans=(ans+sum(i,j)*p1%mod*p2%mod)%mod;
                }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}