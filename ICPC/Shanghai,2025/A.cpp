#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int ask(int u,int dist)
{
    cout<<'?'<<' '<<u<<' '<<dist<<endl<<flush;
    int col;
    cin>>col;
    return col;
}

int n;
bool vis[MAX];
int f[MAX],depth[MAX],sz[MAX],w[MAX];

void initial()
{
    for(int i=1;i<=n;i++)
        vis[i]=false;
}

void dfs_first(int ch,int fa,vector<vector<int>>& adj)
{
    f[ch]=fa;
    depth[ch]=depth[fa]+1;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs_first(to,ch,adj);
    }
}

void get_size(int ch,int fa,vector<vector<int>>& adj)
{
    sz[ch]=w[ch];

    for(auto &to:adj[ch])
    {
        if(to==fa||vis[to]) continue;
        get_size(to,ch,adj);
        sz[ch]+=sz[to];
    }
}

int get_sent(int root,vector<vector<int>>& adj)
{
    get_size(root,0,adj);
    int half=sz[root]>>1,u=root,fa=0;

    while(1)
    {
        int nxt=-1;

        for(auto &v:adj[u])
        {
            if(v==fa||vis[v]) continue;
            if(sz[v]>half)
            {
                nxt=v;
                break;
            }
        }

        if(nxt==-1) return u;
        fa=u;
        u=nxt;
    }
}

void mark(int ch,int fa,vector<vector<int>>& adj)
{
    vis[ch]=true;

    for(auto &to:adj[ch])
    {
        if(to==fa||vis[to]) continue;
        mark(to,ch,adj);
    }
}

void solve()
{
    cin>>n;initial();

    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++)
    {
        int fa;
        cin>>fa;
        adj[fa].push_back(i);
        adj[i].push_back(fa);
    }

    depth[0]=-1;
    dfs_first(1,0,adj);
    int l=0,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        int col=ask(1,mid);
        if(col==1) r=mid-1;
        else l=mid+1;
    }

    int target=l;
    if(!target)
    {
        cout<<'!'<<' '<<1<<endl<<flush;
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(depth[i]==target) w[i]=1;
        else w[i]=0;
    }

    int now=1;
    while(1)
    {
        int sent=get_sent(now,adj);
        get_size(sent,0,adj);

        if(sz[sent]==1)
        {
            for(int i=1;i<=n;i++)
                if(w[i]==1&&!vis[i])
                {
                    cout<<'!'<<' '<<i<<endl<<flush<<endl;
                    return;
                }
        }

        vector<int>son;
        for(auto &to:adj[sent])
        {
            if(vis[to]) continue;
            son.push_back(to);
        }

        sort(son.begin(),son.end(),[&](const int &i,const int &j){
            return sz[i]>sz[j];
        });

        int ask_node=son.front(),col;
        if(ask_node==f[sent])
        {
            col=ask(sent,target-depth[sent]);
            if(col==1)
            {
                mark(ask_node,sent,adj);
                now=sent;
            }
            else
            {
                vis[sent]=true;
                for(auto &cur:son)
                {
                    if(cur==ask_node) continue;
                    mark(cur,sent,adj);
                }
                now=ask_node;
            }
        }
        else
        {
            col=ask(ask_node,target-depth[ask_node]);
            if(col==1)
            {
                mark(sent,ask_node,adj);
                now=ask_node;
            }
            else
            {
                mark(ask_node,sent,adj);
                now=sent;
            }
        }
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