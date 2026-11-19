#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

struct ovo
{
    int u,v;
}edge[MAX];

int n,m;
stack<int>st;
bool vis[MAX],is_anc[MAX];
int dfn[MAX],low[MAX],comb[MAX],tot=0,scc=0;
vector<pair<int,int>>p[MAX];

void dfs(int u)
{
    low[u]=dfn[u]=++tot;
    st.push(u);
    vis[u]=true;

    for(auto &[v,id]:p[u])
    {
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
        {
            is_anc[id]=true;
            low[u]=min(low[u],dfn[v]);
        }
    }

    if(low[u]==dfn[u])
    {
        ++scc;

        while(1)
        {
            int v=st.top();st.pop();
            vis[v]=false;

            comb[v]=scc;

            if(u==v) break;
        }
    }
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;

        edge[i]={u,v};
        p[u].push_back({v,i});
    }

    vector<vector<int>>pre(n+1);
    for(int i=1;i<=n;i++)
        if(!dfn[i]) dfs(i);
    for(int i=1;i<=m;i++)
        if(!is_anc[i])
        {
            auto &[u,v]=edge[i];
            pre[u].push_back(v);
        }

    bool ok=false;
    for(int i=1;i<=m;i++)
        if(is_anc[i])
        {
            ok=true;
            break;
        }

    auto bfs=[&](vector<vector<int>>& p)
    {
        vector<int>indeg(n+1,0);
        vector<bool>vis(n+1,false);
        for(int u=1;u<=n;u++)
            for(auto &v:p[u])
            {
                ++indeg[v];
                vis[u]=vis[v]=true;
            }

        queue<int>q;
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) ans.push_back(i);
            else if(indeg[i]==0) q.push(i);
        }

        while(q.size())
        {
            auto u=q.front();q.pop();
            ans.push_back(u);

            for(auto &v:p[u])
                if(--indeg[v]==0) q.push(v);
        }

        return ans;
    };

    cout<<(ok?2:1)<<endl;
    vector<int>ans=bfs(pre);

    for(auto &cur:ans)
        cout<<cur<<' ';
    cout<<endl;

    if(ok)
    {
        for(auto it=ans.rbegin();it!=ans.rend();++it)
            cout<<*it<<' ';
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}