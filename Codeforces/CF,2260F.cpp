#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9,BIT_SIZE=3020;
const LL LINF=9e18;

struct fucalorse
{
    private:
        int n;
        vector<int>fa;
    public:
        fucalorse(int _n)
        {
            n=_n;
            fa.assign(n+1,0);
            for(int i=1;i<=n;i++)
                fa[i]=i;
        }

        void reset()
        {
            for(int i=1;i<=n;i++)
                fa[i]=i;
        }

        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }

        void merge(int x,int y) { fa[find(x)]=find(y); }
};

struct Edge
{
    int u,v,id;
}op[MAX];

int n,m;

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        op[i].id=i;
        cin>>op[i].u>>op[i].v;
    }

    vector<Edge>rest;
    fucalorse fu(n);
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=1;i<=m;i++)
    {
        auto [u,v,id]=op[i];
        if(fu.find(u)==fu.find(v))
        {
            rest.push_back(op[i]);
            continue;
        }
        fu.merge(u,v);
        adj[u].push_back({v,id});
        adj[v].push_back({u,id});
    }

    int pos,ed_node,len=rest.size();
    vector<int>wait;
    vector<bitset<BIT_SIZE>>bit(len);
    auto dfs=[&](auto &&self,int u,int from)->bool
    {
        for(auto &[v,id]:adj[u])
        {
            if(v==from) continue;
            wait.push_back(id);
            if(v==ed_node)
            {
                auto &now=bit[pos];
                for(auto &cur:wait)
                    now[cur]=1;
                return true;
            }
            if(self(self,v,u)) return true;
            wait.pop_back();
        }

        return false;
    };

    for(int i=0;i<len;i++)
    {
        pos=i;
        auto [u,v,id]=rest[i];
        ed_node=v;
        bit[pos][id]=1;
        wait.clear();
        dfs(dfs,u,0);
    }

    int S=1<<len,timer=0;
    vector<int>deg(n+1),vis(n+1,0);

    for(int mask=1;mask<S;mask++)
    {
        bitset<BIT_SIZE>cur;
        for(int k=0;k<len;k++)
            if((mask>>k)&1) cur^=bit[k];

        fu.reset();
        ++timer;
        for(int i=1;i<=m;i++)
            if(cur[i]==1)
            {
                auto [u,v,id]=op[i];
                fu.merge(u,v);
                if(vis[u]!=timer)
                {
                    deg[u]=0;
                    vis[u]=timer;
                }
                if(vis[v]!=timer)
                {
                    deg[v]=0;
                    vis[v]=timer;
                }
                ++deg[u];
                ++deg[v];
            }

        int root=-1;
        bool ok=true;
        for(int i=1;i<=n;i++)
            if(vis[i]==timer)
            {
                if(deg[i]!=2)
                {
                    ok=false;
                    break;
                }
                if(root==-1) root=fu.find(i);
                else if(fu.find(i)!=root)
                {
                    ok=false;
                    break;
                }
            }

        if(ok&&root!=-1)
        {
            fu.reset();
            int total=n;
            for(int i=1;i<=m;i++)
                if(cur[i]==0)
                {
                    auto [u,v,id]=op[i];
                    if(fu.find(u)==fu.find(v)) continue;
                    fu.merge(u,v);
                    if(--total==1) break;
                }

            if(total==1)
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    }

    cout<<"NO"<<endl;
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