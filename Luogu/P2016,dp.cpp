#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int n;
int dp[MAX][2];
vector<int>p[MAX];

void dfs(int ch,int fa)
{
    dp[ch][1]=1;
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
        dp[ch][1]+=min(dp[to][1],dp[to][0]);
        dp[ch][0]+=dp[to][1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u,k;
        cin>>u>>k;
        ++u;
        for(int j=1;j<=k;j++)
        {
            int v;
            cin>>v;
            ++v;
            p[u].push_back(v);
            p[v].push_back(u);
        }
    }
    dfs(1,0);
    cout<<min(dp[1][0],dp[1][1])<<endl;
    return 0;
}