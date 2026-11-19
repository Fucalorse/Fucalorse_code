#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;

int t,n;
char s[3][MAX];

void solve()
{
    cin>>n>>(s[1]+1)>>(s[2]+1);
    vector<int>dp(n+3,inf);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=min(dp[i],dp[i-1]+(s[1][i]!=s[2][i]));
        if(i>=2)
        {
            int cost=(s[1][i]!=s[1][i-1])+(s[2][i]!=s[2][i-1]);
            dp[i]=min(dp[i],dp[i-2]+cost);
        }
    }
    // for(int i=1;i<=n;i++)
    //     cout<<dp[i]<<' ';
    // cout<<endl;
    cout<<dp[n]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}