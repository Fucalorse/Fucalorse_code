#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=26,MOD=998244353,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    int m=n*2;
    vector<int>first(n+1,0),second(n+1,0);
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        if(!first[a[i]]) first[a[i]]=i;
        else second[a[i]]=i;
    }

    vector<LL>dp(m+1,0);
    for(int i=1;i<=m;i++)
    {
        dp[i]=max(dp[i],dp[i-1]+1);

        int l=first[a[i]],r=second[a[i]];
        if(l==i) continue;

        LL now=1LL*(r-l+1)*(r-l+1);
        dp[i]=max(dp[i],dp[first[a[i]]-1]+now);
    }

    cout<<dp[m]<<endl;
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