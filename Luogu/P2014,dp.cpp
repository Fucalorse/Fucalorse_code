#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=350;

int n,m;
int dp[MAX][MAX],a[MAX],sz[MAX],f[MAX];
vector<int>p[MAX];

void dfs(int ch)
{
    sz[ch]=1;
    dp[ch][1]=a[ch];
    for(auto &to:p[ch])
    {
        dfs(to);
        sz[ch]+=sz[to];
        for(int i=m;i>=0;i--)
            for(int j=i-1;j>=0;j--)
                dp[ch][i]=max(dp[ch][i],dp[to][j]+dp[ch][i-j]);
    }
}

void solve()
{
    cin>>n>>m;
    ++m;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i]>>a[i];
        p[f[i]].push_back(i);
    }
    dfs(0);
    cout<<dp[0][m]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}