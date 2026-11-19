#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;
const LL INF=1e18;

int n;
int a[MAX];
LL dp[MAX][4];

void dfs(int ch,int fa,vector<vector<int>>& p)
{
    dp[ch][0]=dp[ch][3]=0;
    dp[ch][1]=a[ch];
    dp[ch][2]=-a[ch];

    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        dfs(to,ch,p);

        vector<LL>ndp(4,-INF);

        for(int i=0;i<4;i++)
            for(int j=0;i+j<4;j++)
                if((i&j)==0) ndp[i+j]=max(ndp[i+j],dp[ch][i]+dp[to][j]);

        for(int i=0;i<4;i++)
            dp[ch][i]=ndp[i];
    }

    dp[ch][0]=max(dp[ch][0],dp[ch][3]);
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<vector<int>>p(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;

        p[u].push_back(v);
        p[v].push_back(u);
    }

    dfs(1,0,p);

    cout<<dp[1][0]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}