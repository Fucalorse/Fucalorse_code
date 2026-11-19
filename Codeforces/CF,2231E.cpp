#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2090;

int T,n,d;
int f[MAX],depth[MAX],sz[MAX],son[MAX],top[MAX],dist[MAX][MAX];
LL cnt[MAX][MAX],sub[MAX][MAX],sum_node[MAX][MAX],sum_edge[MAX][MAX];
vector<int>p[MAX];

struct peach
{
    int dfs(int ch,int fa)
    {
        f[ch]=fa;
        depth[ch]=depth[fa]+1;

        sz[ch]=1;
        son[ch]=0;
        int maxn=-1;

        sub[ch][0]=1;

        for(auto &to:p[ch])
        {
            if(to==fa) continue;

            sz[ch]+=dfs(to,ch);
            if(sz[to]>maxn) son[ch]=to,maxn=sz[to];

            for(int r=1;r<=d;r++)
                sub[ch][r]+=sub[to][r-1];
        }

        return sz[ch];
    }

    void find(int pos,int dfn)
    {
        top[pos]=dfn;

        if(!son[pos]) return;
        find(son[pos],dfn);

        for(auto &to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
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

    LL query_node(int u,int v,int r)
    {
        int lca=LCA(u,v);

        return sum_node[u][r]+sum_node[v][r]-2*sum_node[lca][r]+cnt[lca][r];
    }

    LL query_edge(int u,int v,int r)
    {
        int lca=LCA(u,v);

        return sum_edge[u][r]+sum_edge[v][r]-2*sum_edge[lca][r];
    }
}fu;

void clear()
{
    for(int i=0;i<=n;i++)
    {
        p[i].clear();
        for(int j=0;j<=n;j++)
            cnt[i][j]=sub[i][j]=sum_node[i][j]=sum_edge[i][j]=0;
    }
}

void get_dist(int root,int ch,int fa,int dep)
{
    dist[root][ch]=dep;

    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        get_dist(root,to,ch,dep+1);
    }
}

void get_con(int ch,int fa)
{
    for(int r=0;r<=d;r++)
    {
        sum_node[ch][r]=sum_node[fa][r]+cnt[ch][r];

        if(!fa) sum_edge[ch][r]=0;
        else
        {
            LL child_con=sub[ch][r];
            LL father_con=cnt[fa][r];
            if(r>0) father_con-=sub[ch][r-1];

            sum_edge[ch][r]=child_con+father_con+sum_edge[fa][r];
        }
    }

    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        get_con(to,ch);
    }
}

void solve()
{
    cin>>n>>d;
    --d,clear();

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
        get_dist(i,i,0,0);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cnt[i][dist[i][j]]++;

    fu.dfs(1,0),fu.find(1,1);
    get_con(1,0);

    LL ans=0;
    for(int u=1;u<=n;u++)
        for(int v=u+1;v<=n;v++)
        {
            int h=d-dist[u][v];
            if(h<0) continue;

            if(h==0) ans+=dist[u][v]-1;
            else ans+=fu.query_node(u,v,h)-fu.query_edge(u,v,h-1);
        }

    cout<<ans/3<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}