#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e5,G=3,MOD=998244353;
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
};

int minp[MAX];
vector<int>op;

void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }
}

struct Edge
{
    int u,v;
}edge[MAX];

int n,m;
int a[MAX];

void solve()
{
    cin>>n>>m;

    auto split=[&](int num)
    {
        map<int,int>f;
        for(auto &prime:op)
        {
            if(num==1||1LL*prime*prime>num) break;
            while(num%prime==0)
            {
                ++f[prime];
                num/=prime;
            }
        }

        if(num>1) ++f[num];

        return f;
    };

    set<int>st;
    vector<map<int,int>>mp(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[i]=split(a[i]);
        for(auto &[prime,cnt]:mp[i])
            st.insert(prime);
    }

    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u%2==0) swap(u,v);
        edge[i]={u,v};
    }

    LL ans=0;
    for(auto &prime:st)
    {
        dinic fu(n+1,0,n+1);

        for(int i=1;i<=n;i++)
        {
            auto it=mp[i].find(prime);
            if(it!=mp[i].end())
            {
                if(i&1) fu.add_edge(0,i,it->second);
                else fu.add_edge(i,n+1,it->second);
            }
        }

        for(int i=1;i<=m;i++)
        {
            const auto &[u,v]=edge[i];
            auto it_u=mp[u].find(prime);
            auto it_v=mp[v].find(prime);

            if(it_u!=mp[u].end()&&it_v!=mp[v].end()) fu.add_edge(u,v,INF);
        }
        ans+=fu.max_flow();
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}