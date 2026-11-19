#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
int p[MAX],depth[MAX],maxn[MAX];
LL dp[MAX];

void dfs(int ch,int fa,vector<vector<int>> &adj)
{
    dp[ch]=1;
    maxn[ch]=depth[ch]=depth[fa]+1;

    vector<int>rest;
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);
        dp[ch]+=dp[to];
        maxn[ch]=max(maxn[ch],maxn[to]);
        rest.push_back(maxn[to]-depth[ch]);
    }

    if((int)rest.size()>=2)
    {
        sort(rest.begin(),rest.end(),greater<int>());
        dp[ch]+=rest[1];
    }
}

void solve()
{
    cin>>n;

    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
        adj[p[i]].push_back(i);
    }

    dfs(1,0,adj);

    cout<<dp[1]<<endl;
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