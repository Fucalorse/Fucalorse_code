#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353;
const LL INF=1e18;

struct dinic
{
    private:
        struct Edge
        {
            int to;
            LL cap;
        };

        int n,s,t;
        vector<Edge>edge;
        vector<vector<int>>adj;
        vector<int>level,cur;

        bool bfs()
        {
            fill(level.begin(),level.end(),-1);

            queue<int>q;
            q.push(s),level[s]=0;

            while(q.size())
            {
                int u=q.front();q.pop();

                for(auto &id:adj[u])
                {
                    auto [v,cap]=edge[id];
                    if(cap>0&&level[v]==-1)
                    {
                        level[v]=level[u]+1;
                        q.push(v);
                    }
                }
            }

            return level[t]!=-1;
        }

        LL dfs(int u,LL limit)
        {
            if(u==t) return limit;

            for(int &i=cur[u];i<(int)adj[u].size();i++)
            {
                int id=adj[u][i];
                auto [v,cap]=edge[id];

                if(cap==0||level[v]!=level[u]+1) continue;

                LL pushed=dfs(v,min(limit,cap));
                if(pushed>0)
                {
                    edge[id].cap-=pushed;
                    edge[id^1].cap+=pushed;
                    return pushed;
                }
            }

            return 0;
        }
    public:
        dinic(int _n,int _s,int _t):n(_n),s(_s),t(_t),adj(_n+1),level(_n+1),cur(_n+1){}

        void add_edge(int u,int v,LL cap)
        {
            int id=edge.size();

            edge.push_back({v,cap});
            edge.push_back({u,0});

            adj[u].push_back(id);
            adj[v].push_back(id^1);
        }

        LL max_flow()
        {
            LL ans=0;
            while(bfs())
            {
                fill(cur.begin(),cur.end(),0);
                while(LL pushed=dfs(s,INF)) ans+=pushed;
            }
            return ans;
        }

        vector<vector<LL>> get(int number)
        {
            vector<vector<LL>>ans(number+1,vector<LL>(number+1,0LL));

            for(int u=1;u<=number;u++)
                for(auto &id:adj[u])
                {
                    if(id&1) continue;
                    auto [v,cap]=edge[id];
                    ans[u][v-number]=INF-cap;
                }

            return ans;
        }
};

int n,m;
LL a[MAX],b[MAX];

void solve()
{
    cin>>n>>m;

    LL suma=0,sumb=0;
    dinic fu(2*n+1,0,2*n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        suma+=a[i];
        fu.add_edge(0,i,a[i]);
        fu.add_edge(i,i+n,INF);
    }

    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        sumb+=b[i];
        fu.add_edge(i+n,2*n+1,b[i]);
    }

    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        fu.add_edge(u,v+n,INF);
        fu.add_edge(v,u+n,INF);
    }

    if(suma!=sumb)
    {
        cout<<"NO"<<endl;
        return;
    }

    if(fu.max_flow()==suma)
    {
        cout<<"YES"<<endl;

        vector<vector<LL>>ans=fu.get(n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<ans[i][j]<<' ';
            cout<<endl;
        }
    }
    else cout<<"NO"<<endl;
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