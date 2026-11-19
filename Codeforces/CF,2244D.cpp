#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7;
const LL INF=1e18;

struct qwq
{
    LL b,val;
    bool operator<(const qwq &a)const { return b>a.b; }
}op[MAX];

int T,n,m;
LL a[MAX],b[MAX],sum[MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }

    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        op[i]={b[i],sum[b[i]]};
    }

    sort(op+1,op+m+1);

    LL extra=0;
    vector<vector<LL>>dp(m+1,vector<LL>(2,-INF));
    dp[0][0]=0;
    for(int i=1;i<=m;i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+2*op[i].val);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]-2*op[i].val);

        extra=max(extra,max(dp[i][0],dp[i][1]));
    }

    cout<<sum[n]+extra<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}