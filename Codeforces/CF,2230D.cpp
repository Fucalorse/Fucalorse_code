#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int T,n;
int a[MAX],b[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];

    vector<int>dp(n+5,n+1),suf(n+5,n+1),pa(n+5,n+1),pb(n+5,n+1);
    for(int i=n;i>=1;i--)
    {
        if(a[i]==b[i])
        {
            if(pa[a[i]+1]==pb[a[i]+1]) dp[i]=dp[pa[a[i]+1]];
            else dp[i]=min(pa[a[i]+1],pb[b[i]+1]);
        }
        else dp[i]=i;

        pa[a[i]]=pb[b[i]]=i;
        suf[i]=min(pa[1],pb[1]);
    }

    // for(int i=1;i<=n;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;

    LL ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[suf[i]]-i;

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