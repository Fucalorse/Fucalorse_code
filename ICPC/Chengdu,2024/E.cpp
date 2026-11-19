#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct fucalorse
{
    private:
        vector<int>f,sz,son,top,depth;

        int dfs(int ch,int fa,vector<vector<int>>& adj)
        {
            f[ch]=fa;
            sz[ch]=1;
            depth[ch]=depth[fa]+1;
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
            sz.assign(_n+3,0);
            son.assign(_n+3,0);
            top.assign(_n+3,0);
            depth.assign(_n+3,0);

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

int n,q;
int p[MAX],pre_id[MAX],suf_id[MAX];
LL dp[MAX],all[MAX],up[MAX],pre[MAX],suf[MAX],sum[MAX];

void dfs_first(int ch,int fa,vector<vector<int>>& adj)
{
    dp[ch]=1;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs_first(to,ch,adj);
        dp[ch]=dp[ch]*(dp[to]+1)%MOD;
    }

    int id=0;
    pre[0]=suf[0]=1;
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        pre[to]=pre[id]*(dp[to]+1)%MOD;
        pre_id[to]=id;
        id=to;
    }

    id=0;
    for(auto it=adj[ch].rbegin();it!=adj[ch].rend();++it)
    {
        int to=*it;
        if(to==fa) continue;
        suf[to]=suf[id]*(dp[to]+1)%MOD;
        suf_id[to]=id;
        id=to;
    }
}

void dfs_second(int ch,int fa,vector<vector<int>>& adj)
{
    sum[ch]=(sum[fa]+dp[ch])%MOD;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        up[to]=(1+up[ch])*pre[pre_id[to]]%MOD*suf[suf_id[to]]%MOD;
        dfs_second(to,ch,adj);
    }

    all[ch]=dp[ch]*(up[ch]+1)%MOD;
}

void solve()
{
    cin>>n>>q;

    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }

    dfs_first(1,0,adj);
    dfs_second(1,0,adj);
    fucalorse fu(n,adj);

    auto cal=[&](int u,int v)
    {
        int lca=fu.LCA(u,v);
        LL ans=((sum[u]+sum[v])%MOD-2*sum[lca]%MOD)%MOD;
        ans=(ans+all[lca])%MOD;
        return (ans+MOD)%MOD;
    };

    while(q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<cal(u,v)<<endl;
    }
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