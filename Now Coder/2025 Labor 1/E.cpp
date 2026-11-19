#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,INF=2e9,MOD=998244353;

struct Edge
{
    int u,v;
}edge[MAX];

int T,n,m;

struct fucalorse
{
    private:
        int f[MAX],dfn[MAX],rev[MAX],semi[MAX],idom[MAX],anc[MAX],best[MAX],tot;
        int tin[MAX],tout[MAX],timer;
    public:
        void clear(int n)
        {
            tot=timer=0;
            for(int i=1;i<=n;i++)
                f[i]=dfn[i]=rev[i]=semi[i]=idom[i]=best[i]=anc[i]=0;
        }

        void dfs(int ch,int fa,vector<vector<int>>& p)
        {
            f[ch]=fa;
            dfn[ch]=++tot;
            rev[tot]=ch;

            for(auto &to:p[ch])
            {
                if(to==fa||dfn[to]) continue;

                dfs(to,ch,p);
            }
        }

        void dfs_time(int u,vector<vector<int>>& p)
        {
            tin[u]=++timer;

            for(auto &v:p[u])
                dfs_time(v,p);
            
            tout[u]=timer;
        }

        void compress(int u)
        {
            if(anc[anc[u]])
            {
                compress(anc[u]);

                if(semi[best[anc[u]]]<semi[best[u]])
                    best[u]=best[anc[u]];
                
                anc[u]=anc[anc[u]];
            }
        }

        int eval(int u)
        {
            if(!anc[u]) return best[u];

            compress(u);
            return best[u];
        }

        void link(int u,int p) { anc[u]=p; }

        void create(vector<vector<int>> &p,vector<vector<int>>& pre)
        {
            dfs(1,0,p);
            for(int i=1;i<=tot;i++)
            {
                int u=rev[i];
                best[u]=u;
                semi[u]=i;
            }

            vector<vector<int>>bucket(n+1);
            for(int i=tot;i>=2;i--)
            {
                int u=rev[i];

                for(auto &v:pre[u])
                {
                    int x=eval(v);
                    semi[u]=min(semi[u],semi[x]);
                }

                int s=rev[semi[u]];
                bucket[s].push_back(u);

                int father=f[u];
                link(u,father);

                for(auto &v:bucket[father])
                {
                    int x=eval(v);

                    if(semi[x]<semi[v]) idom[v]=x;
                    else idom[v]=father;
                }

                bucket[father].clear();
            }

            for(int i=2;i<=tot;i++)
            {
                int u=rev[i];

                if(idom[u]!=rev[semi[u]]) idom[u]=idom[idom[u]];
            }

            vector<vector<int>>tree(tot+1);
            for(int u=2;u<=tot;u++)
                tree[idom[u]].push_back(u);

            dfs_time(1,tree);
        }

        bool check(int u,int v)
        {
            return tin[v]<=tin[u]&&tout[u]<=tout[v];
        }
}fu;

void solve()
{
    cin>>n>>m;

    vector<vector<int>>p(n+1),pre(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;

        edge[i]={u,v};
        p[u].push_back(v);
        pre[v].push_back(u);
    }

    fu.clear(n);
    fu.create(p,pre);

    auto bfs=[&]()
    {
        queue<int>q;
        vector<int>dist(n+1,INF);
        dist[1]=0;
        q.push(1);

        while(q.size())
        {
            int u=q.front();q.pop();

            for(auto &v:p[u])
                if(dist[v]>dist[u]+1)
                {
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
        }

        return dist;
    };

    vector<int>dist=bfs();
    for(int i=1;i<=m;i++)
    {
        auto [u,v]=edge[i];

        if(dist[v]==dist[u]+1) continue;
        if(!fu.check(u,v))
        {
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    
    cin>>T;
    while(T--) solve();

    return 0;
}