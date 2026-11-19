#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

int T,n;
int dp[MAX][2],cnt[MAX];

void dfs(int ch,int fa,vector<vector<int>>& p)
{
    dp[ch][0]=0;
    dp[ch][1]=(int)p[ch].size()==1?0:INF;
    cnt[ch]=(int)p[ch].size()==1?1:0;

    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        dfs(to,ch,p);
        cnt[ch]+=cnt[to];
        
        dp[ch][0]+=dp[to][0]+(cnt[to]&1);
    }

    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dp[ch][1]=min(dp[ch][1],dp[ch][0]-dp[to][0]-(cnt[to]&1)+dp[to][1]+((cnt[to]-1)&1));
    }
}

void solve()
{
    cin>>n;

    vector<vector<int>>p(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }

    if(n==2)
    {
        cout<<1<<endl;
        return;
    }

    int root=1;
    while(root<=n&&(int)p[root].size()==1) ++root;

    dfs(root,0,p);

    // for(int i=1;i<=n;i++)
    //     cout<<cnt[i]<<' ';
    // cout<<endl;

    // for(int i=1;i<=n;i++)
    //     cout<<i<<":"<<dp[i][0]<<' '<<dp[i][1]<<endl;

    if(cnt[root]&1) cout<<dp[root][1]<<endl;
    else cout<<dp[root][0]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}