#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,mod=998244353,inf=2e9;

int t,n,maxn;
int depth[MAX],f[MAX];
LL dp[MAX],sum[MAX];
vector<int>p[MAX],op[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear(),op[i].clear();
}

void dfs(int ch,int fa)
{
    f[ch]=fa;
    depth[ch]=depth[fa]+1;
    maxn=max(maxn,depth[ch]);
    op[depth[ch]].push_back(ch);
    for(auto &to:p[ch])
        dfs(to,ch);  
}

void solve()
{
    cin>>n;
    clear();
    maxn=-inf;
    memset(dp,0,sizeof(LL)*(n+5));
    memset(sum,0,sizeof(LL)*(n+5));
    for(int i=2;i<=n;i++)
    {
        int fa;
        cin>>fa;
        p[fa].push_back(i);
    }
    dfs(1,0);
    for(int i=maxn;i>=1;i--)
        for(auto &pos:op[i])
        {
            dp[pos]=(dp[pos]+sum[depth[pos]+1]+1)%mod;
            sum[depth[pos]]=(sum[depth[pos]]+dp[pos])%mod;
            if(f[pos]!=1) dp[f[pos]]=(dp[f[pos]]-dp[pos]+mod)%mod;
        }
    // for(int i=1;i<=n;i++)
    //     cout<<dp[i]<<' ';
    // cout<<endl;
    cout<<dp[1]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}