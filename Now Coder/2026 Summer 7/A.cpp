#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=30,MOD=998244353,INF=2e9;

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    auto check=[&](LL mask)
    {
        LL pre=0;
        for(int i=1;i<=n;i++)
        {
            LL now=a[i];

            for(int k=LEN;k>=0;k--)
                if((mask>>k)&1) now|=1<<k;

            for(int k=LEN;k>=0;k--)
                if((mask>>k)&1)
                {
                    if((now^(1LL<<k))>=pre) now^=1LL<<k;
                }

            if(now<pre) return false;

            pre=now;
        }

        return true;
    };

    LL ans=0;
    for(int k=LEN;k>=0;k--)
    {
        LL mask=ans|((1LL<<k)-1);
        if(!check(mask)) ans|=1LL<<k;
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