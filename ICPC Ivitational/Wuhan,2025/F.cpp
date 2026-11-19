#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e5+90,LEN=26,MOD=998244353;

LL cal(LL a,LL p)
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
LL m,a[MAX],b[MAX];

void solve()
{
    cin>>n>>m;

    LL total=0;
    map<LL,LL,greater<LL>>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        mp[b[i]]+=a[i];
        total+=a[i];
    }

    LL maxn=total+1,d=0,ans=0,pre=0;
    bool first=true;
    for(auto &[b,a]:mp)
    {
        if(!first)
        {
            LL gap=pre-b;

            if(d)
            {
                if(gap>=60) d=maxn;
                else
                {
                    i128 now=((i128)d<<gap);
                    d=now>=maxn?maxn:(LL)now;
                }
            }
        }

        d-=a;

        if(d<0)
        {
            LL need=(-d+m-1)/m;
            LL now=need%MOD*cal(2,b)%MOD;
            ans=(ans+now)%MOD;
            d+=need*m;
        }

        pre=b;
        first=false;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}