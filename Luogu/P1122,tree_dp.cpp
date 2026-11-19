#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;
const LL inf=1e17;

int n;
int f[MAX];
LL a[MAX],dp[MAX],g[MAX];
vector<int>p[MAX];

void dfs(int ch,int fa)
{
    f[ch]=fa;
    dp[ch]=a[ch];
    g[ch]=max(g[fa]+a[ch],a[ch]);
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
        dp[ch]+=max(dp[to],0LL);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    memset(dp,-0x3f,sizeof(dp)),memset(g,-0x3f,sizeof(g));
    dp[0]=g[0]=0;
    dfs(1,0);
    LL ans=-inf;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]+g[i]-a[i]);
    cout<<ans<<endl;
    return 0;
}