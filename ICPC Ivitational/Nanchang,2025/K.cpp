#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e6+90,MOD=1e9+7;
const LL INF=1e18;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    LL ans=INF;
    for(int i=0;i<4;i++)
    {
        LL sum=0;
        for(int j=1;j<=n;j++)
            sum+=(i+a[j])%4;
        LL now=(i-sum%4+4)%4;
        // cout<<now<<' '<<sum<<endl;
        ans=min(ans,now+sum);
    }

    cout<<ans<<endl;
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