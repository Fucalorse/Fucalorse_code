#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353;
const LL INF=1e18;
const double EPS=1e-7;

struct dinic
{
    private:
        struct Edge
        {
            int to;
            LL cap;
        };

        int n,s,t;
        vector<Edge>pre,edge;
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

            pre.push_back({v,cap});
            pre.push_back({u,0});
            edge.push_back({v,cap});
            edge.push_back({u,0});

            adj[u].push_back(id);
            adj[v].push_back(id^1);
        }

        LL max_flow(const double &mid,LL x)
        {
            for(int i=0;i<(int)pre.size();i++)
            {
                if(i&1) edge[i].cap=0;
                else
                {
                    LL ncap=pre[i].cap/mid;
                    edge[i].cap=min(ncap,x);
                }
            }

            LL ans=0;
            while(bfs())
            {
                fill(cur.begin(),cur.end(),0);
                while(LL pushed=dfs(s,INF)) ans+=pushed;
            }
            return ans;
        }
};

int n,m;
LL x;

void solve()
{
    cin>>n>>m>>x;

    double l=0,r=0;
    dinic fu(n,1,n);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        LL cap;
        cin>>u>>v>>cap;

        fu.add_edge(u,v,cap);
        r+=cap;
    }

    for(int i=1;i<=100;i++)
    {
        double mid=(l+r)/2;
        if(fu.max_flow(mid,x)>=x) l=mid;
        else r=mid;
    }

    cout<<fixed<<setprecision(20)<<l*x<<endl;
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