#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    LL ans=-LINF;
    vector<LL>dp(2,0LL),ndp(2);
    for(int i=1;i<=n;i++)
    {
        ndp[0]=ndp[1]=a[i];
        LL max_interval=max(llabs(dp[0]),llabs(dp[1]));
        ans=max(ans,a[i]+max_interval);
        for(auto col:{0,1})
        {
            vector<LL>op={a[i]+dp[col],a[i]+2*dp[col]};
            ndp[0]=min(ndp[0],*min_element(op.begin(),op.end()));
            ndp[1]=max(ndp[1],*max_element(op.begin(),op.end()));
        }
        swap(dp,ndp);
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