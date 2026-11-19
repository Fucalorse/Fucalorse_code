#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128

i128 floor_sum(i128 n, i128 mod, i128 a, i128 b)
{
    i128 ans=0;

    while(true)
    {
        if(a>=mod)
        {
            ans+=n*(n-1)/2*(a/mod);
            a%=mod;
        }

        if(b>=mod)
        {
            ans+=n*(b/mod);
            b%=mod;
        }

        i128 y=a*n+b;

        if(y<mod) return ans;

        n=y/mod;
        b=y%mod;
        swap(a,mod);
    }
}

void solve()
{
    LL p,m;
    cin>>p>>m;

    LL B=1;
    while(B<p) B<<=1;

    LL d=B-p;
    LL Q=m/B;
    LL R=m%B;
    i128 ans=Q;

    if(d>0)
    {
        LL a=p-d;

        i128 ge=floor_sum(Q,p,a,1+p-d)-floor_sum(Q,p,a,1);
        ans+=(i128)Q-ge;
    }

    LL s=(1-(i128)Q*d%p+p)%p;

    if((s^(p-1))<=R) ans++;

    if(s+p<B && ((s+p)^(p-1))<=R) ans++;

    cout<<(LL)ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    while(T--) solve();

    return 0;
}