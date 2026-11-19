#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum^=a[i];
    }

    if(!sum)
    {
        cout<<1<<endl;
        return;
    }

    if(n==1) cout<<0<<endl;
    else
    {
        LL ans=0;

        for(int i=1;i<=n;i++)
        {
            LL now=sum^a[i];
            if(a[i]>=now) ++ans;
        }

        cout<<ans<<endl;
    }
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