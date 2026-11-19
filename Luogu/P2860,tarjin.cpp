#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,m,tot,qwq;
int dfn[MAX],low[MAX],belong[MAX];
vector<int>st;

void dfs(int u,int pid,vector<vector<pair<int,int>>> &adj)
{
    dfn[u]=low[u]=++tot;
    st.push_back(u);

    for(auto &[v,id]:adj[u])
    {
        if(id==pid) continue;

        if(!dfn[v])
        {
            dfs(v,id,adj);
            low[u]=min(low[u],low[v]);

            if(low[v]>dfn[u])
            {
                ++qwq;
                while(1)
                {
                    int x=st.back();st.pop_back();
                    belong[x]=qwq;
                    if(x==v) break;
                }
            }
        }
        else if(dfn[v]<dfn[u]) low[u]=min(low[u],dfn[v]);
    }
}

void solve()
{
    cin>>n>>m;

    vector<pair<int,int>>edge;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        edge.push_back({u,v});
    }

    for(int i=1;i<=n;i++)
        if(!dfn[i])
        {
            dfs(i,-1,adj);
            
            ++qwq;
            while(st.size())
            {
                belong[st.back()]=qwq;
                st.pop_back();
            }
        }

    vector<int>deg(n+1,0);
    for(auto &[u,v]:edge)
    {
        if(belong[u]==belong[v]) continue;
        ++deg[belong[u]],++deg[belong[v]];
    }

    int leaf=0;
    for(int i=1;i<=n;i++)
        leaf+=deg[i]==1;

    cout<<(leaf+1)/2<<endl;
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