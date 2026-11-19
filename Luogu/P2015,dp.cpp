#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=150;

int n,m;
int f[MAX],sz[MAX];
LL dp[MAX][MAX];
vector<pair<int,LL>>p[MAX];

void dfs(int ch,int fa)
{
    for(auto &[to,val]:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
        sz[ch]+=sz[to]+1;
        for(int i=min(m,sz[ch]);i>=0;i--)
            for(int j=min(i-1,sz[to]);j>=0;j--)
                dp[ch][i]=max(dp[ch][i],dp[ch][i-j-1]+dp[to][j]+val);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int u,v;
        LL val;
        cin>>u>>v>>val;
        p[u].push_back({v,val});
        p[v].push_back({u,val});
    }
    dfs(1,0);
    cout<<dp[1][m]<<endl;
    return 0;
}