#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m;

void solve()
{
    cin>>n>>m;

    vector<vector<pair<int,int>>>adj(n+1);
    vector<pair<int,int>>edge(m+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        edge[i]={u,v};
    }

    int timer=0;
    vector<int>dfn(n+1,0),low(n+1,0),st,deg(n+1,0);
    vector<vector<pair<int,int>>>bcc;
    vector<vector<int>>bcc_edge;
    auto tarjin=[&](auto &&self,int u,int from)->void
    {
        low[u]=dfn[u]=++timer;

        if(adj[u].empty())
        {
            vector<pair<int,int>>now={{u,0}};
            bcc.push_back(now);
            bcc_edge.emplace_back();
            return;
        }

        for(auto &[v,id]:adj[u])
        {
            if(id==from) continue;

            if(!dfn[v])
            {
                st.push_back(id);
                self(self,v,id);
                low[u]=min(low[u],low[v]);

                if(low[v]>=dfn[u])
                {
                    vector<int>node,ids;
                    while(1)
                    {
                        int cur_id=st.back();st.pop_back();
                        auto [x,y]=edge[cur_id];
                        ids.push_back(cur_id);

                        if(!deg[x]) node.push_back(x);
                        if(!deg[y]) node.push_back(y);
                        ++deg[x],++deg[y];
                        if(cur_id==id) break;
                    }

                    vector<pair<int,int>>now;
                    for(auto &cur:node)
                    {
                        now.push_back({cur,deg[cur]});
                        deg[cur]=0;
                    }

                    bcc.push_back(move(now));
                    bcc_edge.push_back(move(ids));
                }
            }
            else if(dfn[v]<dfn[u])
            {
                st.push_back(id);
                low[u]=min(low[u],dfn[v]);
            }
        }
    };
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjin(tarjin,i,-1);

    timer=0;
    vector<int>vis(n+1);
    set<int>circle;
    vector<vector<int>>g(n+1);
    auto check=[&](vector<pair<int,int>>& op,vector<int>& edge_id)->bool
    {
        if((int)op.size()<3) return true;

        map<int,int>f;
        for(auto &[u,deg]:op)
            ++f[deg];

        if((int)f.size()>2) return false;

        if((int)f.size()==1)
        {
            if(f.begin()->first==2)
            {
                circle.insert((int)op.size());
                return true;
            }
            else return false;
        }
        else
        {
            if((int)f.begin()->first==2&&f.rbegin()->second==2)
            {
                ++timer;
                int st=-1,ed=-1;
                for(auto &[u,deg]:op)
                {
                    vis[u]=timer;
                    g[u].clear();

                    if(deg>2)
                    {
                        if(st==-1) st=u;
                        else ed=u;
                    }
                }

                for(auto &id:edge_id)
                {
                    auto [u,v]=edge[id];
                    g[u].push_back(v);
                    g[v].push_back(u);
                }

                set<int>path;
                auto dfs=[&](auto &&self,int u,int from,int length)->void
                {
                    if((int)path.size()>=2) return;
                    if(u==ed)
                    {
                        path.insert(length);
                        return;
                    }

                    for(auto &v:g[u])
                        if(vis[v]==timer&&v!=from) self(self,v,u,length+1);
                };
                dfs(dfs,st,-1,0);

                if((int)path.size()>=2) return false;
                else
                {
                    circle.insert(2*(*path.begin()));
                    return true;
                }
            }
            else return false;
        }
    };

    for(int i=0;i<(int)bcc.size();i++)
    {
        if(!check(bcc[i],bcc_edge[i]))
        {
            cout<<"No"<<endl;
            return;
        }

        if((int)circle.size()>=2)
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

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}