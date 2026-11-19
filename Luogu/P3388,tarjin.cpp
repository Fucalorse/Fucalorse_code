#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,m,tot;
int dfn[MAX],low[MAX];
vector<int>st,cut;
vector<vector<int>>bcc;

void dfs(int u,int pid,vector<vector<pair<int,int>>> &adj)
{
    dfn[u]=low[u]=++tot;
    st.push_back(u);

    int child=0;
    for(auto &[v,id]:adj[u])
    {
        if(id==pid) continue;

        if(!dfn[v])
        {
            ++child;
            dfs(v,id,adj);
            low[u]=min(low[u],low[v]);

            if(low[v]>=dfn[u])
            {
                if(pid!=-1||child>1) cut.push_back(u);

                vector<int>comb;
                comb.push_back(u);

                while(1)
                {
                    int x=st.back();st.pop_back();
                    comb.push_back(x);

                    if(x==v) break;
                }

                bcc.push_back(comb);
            }
        }
        else if(dfn[v]<dfn[u]) low[u]=min(low[u],dfn[v]);
    }

    if(pid==-1&&child==0)
    {
        st.pop_back();
        bcc.push_back(vector<int>{u});
    }
    else if(pid==-1) st.pop_back();
}

void solve()
{
    cin>>n>>m;

    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    for(int i=1;i<=n;i++)
        if(!dfn[i]) dfs(i,-1,adj);

    sort(cut.begin(),cut.end());
    cut.erase(unique(cut.begin(),cut.end()),cut.end());

    cout<<cut.size()<<endl;
    for(auto &cur:cut)
        cout<<cur<<' ';
    cout<<endl;
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