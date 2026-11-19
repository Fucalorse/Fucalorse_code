#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e5+90,LEN=30,MOD=998244353;
const LL INF=1e16;

struct edge
{
    int u,v,val;
    bool special;
}op[MAX];

struct qwq
{
    int pos;
    LL val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n,m,t,k,q;
int vis[MAX];
bool special_node[MAX];
vector<int>p[MAX],adj[MAX];

vector<LL> bfs(int st,int timer)
{
    queue<int>q;
    vector<LL>dist(n+1,INF);
    q.push(st),dist[st]=0;

    while(q.size())
    {
        int u=q.front();q.pop();
        if(vis[u]==timer) continue;
        vis[u]=timer;

        for(auto &v:p[u])
            if(dist[v]>dist[u]+t)
            {
                dist[v]=dist[u]+t;
                q.push(v);
            }
    }

    return dist;
}

void solve()
{
    cin>>n>>m>>t;

    for(int i=1;i<=m;i++)
    {
        cin>>op[i].u>>op[i].v;
        op[i].val=t;
    }

    cin>>k;

    for(int i=1;i<=k;i++)
    {
        int w,c;
        cin>>w>>c;
        op[w].val=c;
        op[w].special=true;
        special_node[op[w].u]=special_node[op[w].v]=true;
    }

    for(int i=1;i<=m;i++)
    {
        int u=op[i].u,v=op[i].v;

        if(op[i].special)
        {
            adj[u].push_back(i);
            adj[v].push_back(i);
        }
        else
        {
            p[u].push_back(v);
            p[v].push_back(u);
        }
    }

    vector<int>rest;
    vector<vector<LL>>dist(n+1);
    for(int i=1;i<=n;i++)
    {
        dist[i]=bfs(i,i);
        if(special_node[i]) rest.push_back(i);
    }

    int len=rest.size();
    vector<LL>dis(n+1,INF);
    vector<bool>vis(n+1,false);

    auto query=[&](int a,int b)
    {
        dis[a]=0,dis[b]=INF;
        for(auto &pos:rest)
        {
            dis[pos]=dist[a][pos];
            vis[pos]=false;
        }

        for(int r=0;r<len;r++)
        {
            int pos=-1;

            for(int i=0;i<len;i++)
                if(!vis[rest[i]]&&(pos==-1||dis[pos]>dis[rest[i]])) pos=rest[i];

            if(pos==-1||dis[pos]==INF) break;
            vis[pos]=true;

            for(int i=0;i<len;i++)
            {
                int to=rest[i];
                if(dist[pos][to]==INF) continue;

                if(dis[to]>dis[pos]+dist[pos][to]) dis[to]=dis[pos]+dist[pos][to];
            }

            for(auto &eid:adj[pos])
            {
                int to=pos^op[eid].u^op[eid].v,val=op[eid].val;
                if(dis[to]>dis[pos]+val) dis[to]=dis[pos]+val;
            }
        }

        LL ans=min(dist[a][b],dis[b]);
        for(auto &pos:rest)
        {
            LL now=dis[pos]+dist[pos][b];
            ans=min(ans,now);
        }

        return ans;
    };

    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;

        op[x].val=y;

        int len;
        cin>>len;
        while(len--)
        {
            int a,b;
            cin>>a>>b;
            cout<<query(a,b)<<endl;
        }
    }
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