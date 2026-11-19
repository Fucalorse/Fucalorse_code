#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

int fa[MAX],fb[MAX];
string a,b;

void solve()
{
    cin>>a>>b;

    int n=a.size(),m=b.size();
    a=' '+a,b=' '+b;

    for(int i=1;i<=n;i++)
        fa[i]=(fa[i-1]+a[i]-'0')%10;
    for(int i=1;i<=m;i++)
        fb[i]=(fb[i-1]+b[i]-'0')%10;

    if(fa[n]!=fb[m])
    {
        cout<<-1<<endl;
        return;
    }
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(fa[i]==fb[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }

    cout<<dp[n][m]<<endl;
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