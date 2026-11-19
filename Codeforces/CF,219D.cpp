#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

struct qwq
{
    int to;
    bool reverse;
};

int n;
int dp[MAX],sz[MAX],path[MAX];

void dfs_root(int ch,int fa,vector<vector<qwq>>& p)
{
    sz[ch]=1;

    for(auto [to,reverse]:p[ch])
    {
        if(to==fa) continue;

        dfs_root(to,ch,p);

        dp[ch]+=dp[to]+reverse;
    }
}

void change_root(int ch,int fa,vector<vector<qwq>>& p)
{
    for(auto &[to,reverse]:p[ch])
    {
        if(to==fa) continue;

        if(reverse) dp[to]=dp[ch]-1;
        else dp[to]=dp[ch]+1;
        change_root(to,ch,p);
    }
}

void solve()
{
    cin>>n;

    vector<vector<qwq>>p(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;

        p[u].push_back({v,false});
        p[v].push_back({u,true});
    }

    dfs_root(1,0,p);
    change_root(1,0,p);
    vector<int>id;

    int minn=INF;
    for(int i=1;i<=n;i++)
    {
        // cout<<dp[i]<<' ';
        minn=min(minn,dp[i]);
    }
    // cout<<endl;

    for(int i=1;i<=n;i++)
        if(dp[i]==minn) id.push_back(i);

    sort(id.begin(),id.end());
    
    cout<<minn<<endl;
    for(auto &cur:id)
        cout<<cur<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}