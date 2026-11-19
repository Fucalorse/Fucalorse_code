#include <bits/stdc++.h>
using namespace std;

const int MAX=1e4+90;

int n,m;
stack<int>st;
bool vis[MAX];
int pre[MAX],num[MAX],f[MAX];
int dfn[MAX],low[MAX],indeg[MAX],comb[MAX],scc=0,qwq=0;
vector<int>p[MAX],np[MAX];
queue<int>q;

void dfs(int u)
{
    dfn[u]=low[u]=++qwq;
    st.push(u);
    vis[u]=true;
    for(auto &v:p[u])
    {
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        ++scc;
        while(1)
        {
            int v=st.top();st.pop();
            vis[v]=false;
            comb[v]=scc;
            num[scc]+=pre[v];
            if(u==v) break;
        }
    }
}

void bfs()
{
    int ans=0;
    for(int i=1;i<=scc;i++)
        if(!indeg[i])
        {
            f[i]=num[i];
            ans=max(ans,f[i]);
            q.push(i);
        }
    while(q.size())
    {
        int cur=q.front();q.pop();
        for(auto &to:np[cur])
        {
            f[to]=max(f[to],f[cur]+num[to]);
            ans=max(ans,f[to]);
            if(--indeg[to]==0) q.push(to);
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>pre[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) dfs(i);
    for(int u=1;u<=n;u++)
        for(auto &v:p[u])
        {
            if(comb[u]==comb[v]) continue;
            np[comb[u]].push_back(comb[v]);
            indeg[comb[v]]++;
        }
    bfs();
    return 0;
}