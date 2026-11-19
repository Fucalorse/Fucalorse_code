#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=17,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int a[MAX],tmp[MAX];

int f(int x) { return __builtin_popcount(x)+31-__builtin_clz(x); }

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    LL ans=LINF;
    for(int k=0;k<=LEN;k++)
    {
        int bit=1<<k;
        for(int i=1;i<=n;i++)
            tmp[i]=(a[i]+bit-1)/bit*bit;

        LL sum=k;
        for(int i=1;i<=n;i++)
        {
            LL cost=LINF;
            for(int dx=0;dx<=34;++dx)
            {
                int num=tmp[i]+dx;
                if(num%bit==0)
                {
                    LL now=num-a[i]+f(num/bit);
                    cost=min(cost,now);
                }
            }
            sum+=cost;
        }

        ans=min(ans,sum);
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