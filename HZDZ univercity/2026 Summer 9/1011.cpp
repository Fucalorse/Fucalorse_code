#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

LL qpow(LL a,int p)
{
    LL ans=1;

    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }

    return ans;
}

int n;
int depth[MAX],f[MAX],sz[MAX],son[MAX],top[MAX];

struct peach
{
    int dfs(int ch,int fa,vector<int> &op,vector<vector<int>> &adj)
    {
        son[ch]=top[ch]=0;
        f[ch]=fa;
        depth[ch]=depth[fa]+1;
        sz[ch]=1;

        if((int)adj[ch].size()==1&&ch!=1) op.push_back(ch);

        int maxn=-1;
        for(auto &to:adj[ch])
        {
            if(to==fa) continue;
            sz[ch]+=dfs(to,ch,op,adj);
            if(sz[to]>maxn) maxn=sz[to],son[ch]=to;
        }

        return sz[ch];
    }

    void find(int pos,int dfn,vector<vector<int>> &adj)
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

    int query(int u,int v)
    {
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            u=f[top[u]];
        }

        return depth[u]<depth[v]?u:v;
    }
}fu;

void solve()
{
    cin>>n;

    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>op;
    fu.dfs(1,0,op,adj);
    fu.find(1,1,adj);

    int len=op.size();
    vector<pair<int,int>>rest;

    for(int i=0;i<len;i++)
    {
        int best;
        pair<LL,LL>ans={0,1};

        for(int j=0;j<len;j++)
        {
            if(i==j) continue;
            
            int lca=fu.query(op[i],op[j]);
            LL x=depth[op[i]]-depth[lca],y=depth[op[j]]-depth[lca];

            if(x*ans.second-y*ans.first>0)
            {
                ans={x,y};
                best=op[j];
            }
        }

        rest.push_back({op[i],best});
    }

    pair<LL,LL>ans={1,1};
    for(auto &[u,v]:rest)
    {
        int lca=fu.query(u,v);
        LL x=depth[u]-depth[lca],y=depth[v]-depth[lca];

        if(x*ans.second-y*ans.first<0) ans={x,y};
    }

    auto [x,y]=ans;
    cout<<y*qpow(x+y,MOD-2)%MOD<<endl;
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