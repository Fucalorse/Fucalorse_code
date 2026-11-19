#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=32;
const LL INF=1e18;

struct fucalorse
{
    private:
        vector<int>f,depth,son,sz,top;

        int dfs(int ch,int fa,vector<vector<int>>& adj)
        {
            f[ch]=fa;
            depth[ch]=depth[fa]+1;
            sz[ch]=1;
            int maxn=-1;

            for(auto &to:adj[ch])
            {
                if(to==fa) continue;
                sz[ch]+=dfs(to,ch,adj);
                if(sz[to]>maxn) maxn=sz[to],son[ch]=to;
            }

            return sz[ch];
        }

        void find(int pos,int dfn,vector<vector<int>>& adj)
        {
            top[pos]=dfn;
            if(!son[pos]) return;
            find(son[pos],dfn,adj);

            for(auto &to:adj[pos])
            {
                if(to==f[pos]||to==son[pos]) continue;
                find(to,to,adj);
            }
        }
    public:
        fucalorse(int _n,vector<vector<int>>& adj)
        {
            f.assign(_n+3,0);
            depth.assign(_n+3,0);
            son.assign(_n+3,0);
            sz.assign(_n+3,0);
            top.assign(_n+3,0);

            dfs(1,0,adj);
            find(1,1,adj);
        }

        int LCA(int u,int v)
        {
            while(top[u]!=top[v])
            {
                if(depth[top[u]]<depth[top[v]]) swap(u,v);
                u=f[top[u]];
            }

            return depth[u]<depth[v]?u:v;
        }
};

int n,m;
LL c[MAX],dp[MAX],g[MAX],sum[MAX];

void dfs_first(int ch,int fa,vector<vector<int>>& adj)
{
    dp[ch]=c[ch];
    multiset<LL>st;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs_first(to,ch,adj);
        st.insert(dp[to]);
    }

    if((int)adj[ch].size()==1) return;

    //update dp
    auto it1=st.begin();
    auto it2=st.begin();++it2;
    dp[ch]=min(dp[ch],*it1+*it2);

    //update g
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        auto it=st.find(dp[to]);
        LL val=*it;
        st.erase(it);
        g[to]=*st.begin();
        st.insert(val);
    }
}

void dfs_second(int ch,int fa,vector<vector<int>>& adj)
{
    sum[ch]=sum[fa]+g[ch];

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs_second(to,ch,adj);
    }
}

void clear()
{
    for(int i=1;i<=n;i++)
        dp[i]=g[i]=sum[i]=0;
}

void solve()
{
    cin>>n>>m;clear();

    for(int i=1;i<=n;i++)
        cin>>c[i];

    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_first(1,0,adj);
    dfs_second(1,0,adj);
    fucalorse fu(n,adj);

    // for(int i=1;i<=n;i++)
    //     cout<<dp[i]<<' ';
    // cout<<endl;

    while(m--)
    {
        int x,y;
        cin>>x>>y;
        int lca=fu.LCA(x,y);

        if(lca!=y)
        {
            cout<<-1<<endl;
            continue;
        }

        cout<<sum[x]-sum[y]<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ J.cpp -O2 -o out.exe && .\out.exe < in.txt