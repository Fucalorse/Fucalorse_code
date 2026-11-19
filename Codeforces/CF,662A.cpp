#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=64,MOD=998244353,INF=2e9;

int n;
LL a[MAX],b[MAX],f[LEN+3],d[MAX];

void clear()
{
    for(int i=0;i<=64;i++)
        f[i]=0;
}

bool update(LL x)
{
    for(int i=LEN;i>=0;i--)
        if((x>>i)&1)
        {
            if(!f[i])
            {
                f[i]=x;
                return true;
            }

            x^=f[i];
        }

    return false;
}

void solve()
{
    cin>>n;clear();

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        d[i]=a[i]^b[i];
    }

    int r=0;
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        sum^=a[i];
        if(update(d[i])) ++r;
    }

    if(update(sum)) cout<<1<<'/'<<1<<endl;
    else
    {
        LL total=1LL<<r;
        cout<<total-1<<'/'<<total<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}