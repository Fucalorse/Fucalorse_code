#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2090,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int a[MAX][MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            a[i][j]=a[j][i];

        for(int j=i;j<=n;j++)
            cin>>a[i][j];
    }

    vector<int>indeg(n+1,0);
    vector<vector<int>>adj(n+1);
    for(int u=1;u<=n;u++)
        for(int v=u+1;v<=n;v++)
        {
            int lca=a[u][v]^a[1][u]^a[1][v];
            if(lca==u)
            {
                adj[u].push_back(v);
                ++indeg[v];
            }
            else if(lca==v)
            {
                adj[v].push_back(u);
                ++indeg[u];
            }
        }

    queue<int>q;
    q.push(1);
    while(q.size())
    {
        auto u=q.front();q.pop();

        for(auto &v:adj[u])
            if(--indeg[v]==0)
            {
                cout<<u<<' '<<v<<endl;
                q.push(v);
            }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}