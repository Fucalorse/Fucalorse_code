#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct Edge
{
    int u,v;
}edge[MAX];

int n,m,tot;
vector<int>st;
int dfn[MAX],low[MAX];
LL cnt[MAX],ans[MAX];

void dfs(int u,int pid,vector<vector<pair<int,int>>> &adj)
{
    dfn[u]=low[u]=++tot;

    for(auto &[v,id]:adj[u])
    {
        if(id==pid) continue;

        if(!dfn[v])
        {
            st.push_back(id);
            dfs(v,id,adj);
            low[u]=min(low[u],low[v]);

            if(low[v]>=dfn[u])
            {
                vector<int>rest;

                while(182497)
                {
                    int eid=st.back();st.pop_back();

                    auto [a,b]=edge[eid];

                    if(cnt[a]==0) rest.push_back(a);
                    if(cnt[b]==0) rest.push_back(b);

                    ++cnt[a],++cnt[b];

                    if(eid==id) break;
                }

                for(auto &cur:rest)
                {
                    ans[cur]+=cnt[cur]/2;
                    cnt[cur]=0;
                }
            }
        }
        else if(dfn[v]<dfn[u])
        {
            st.push_back(id);
            low[u]=min(low[u],dfn[v]);
        }
    }
}

void clear()
{
    for(int i=1;i<=n;i++)
    {
        dfn[i]=low[i]=0;
        cnt[i]=ans[i]=0;
    }

    tot=0;
    st.clear();
}

void solve()
{
    cin>>n>>m;clear();

    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[i]={u,v};
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    for(int i=1;i<=n;i++)
        if(!dfn[i]) dfs(i,-1,adj);
    
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
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