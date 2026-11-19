#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
typedef pair<int,LL> ovo;
const int MAX=1e4+90,TRAIL=100;
const LL inf=1e18;

mt19937 rng(random_device{}());

struct peach
{
    private:
        vector<int>fa,sz;
    public:
        peach(int n)
        {
            fa.assign(n+5,0);
            sz.assign(n+5,1);
            for(int i=1;i<=n;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y)
        {
            int px=find(x),py=find(y);
            if(px==py) return;
            fa[px]=py;
            sz[py]+=sz[px];
        }
        int get(int x) { return sz[find(x)]; }
};

struct qwq
{
    int u,v;
    LL val;
};

int t,n,m,k,root;
LL ans;
int sz[MAX],maxn[MAX],a[MAX];
bool vis[MAX];
vector<ovo>p[MAX];
vector<qwq>edge;
vector<LL>cur,dp;

int get_size(int ch,int fa)
{
    sz[ch]=1;
    for(auto &[to,val]:p[ch])
    {
        if(to==fa||vis[to]) continue;
        sz[ch]+=get_size(to,ch);
    }
    return sz[ch];
}

int get_root(int pos)
{
    get_size(pos,-1);
    int fa=-1,half=sz[pos]>>1;
    while(1)
    {
        bool ok=true;
        for(auto &[to,val]:p[pos])
        {
            if(to==fa||vis[to]) continue;
            if(sz[to]>half)
            {
                ok=false;
                fa=pos;
                pos=to;
                break;
            }
        }
        if(ok) break;
    }
    return pos;
}

void dfs(int ch,int fa,LL dis,int s)
{
    cur[s%k]=min(cur[s%k],dis);
    for(auto &[to,val]:p[ch])
    {
        if(to==fa||vis[to]) continue;
        dfs(to,ch,dis+val,(s+a[to])%k);
    }
}

void get_cent(int pos)
{
    vis[pos]=true;
    dp=vector<LL>(k+3,inf);
    for(auto &[to,val]:p[pos])
    {
        if(vis[to]) continue;
        cur=vector<LL>(k+3,inf);
        dfs(to,pos,val,a[to]);
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                if((i+j+a[pos])%k==0&&dp[i]!=inf&&cur[j]!=inf) 
                    ans=min(ans,dp[i]+cur[j]);
        for(int i=0;i<k;i++)
        {
            if((i+a[pos])%k==0&&cur[i]!=inf) ans=min(ans,cur[i]);
            dp[i]=min(dp[i],cur[i]);
        }
    }
    for(auto &[to,val]:p[pos])
    {
        if(vis[to]) continue;
        get_cent(get_root(to));
    }
}

void clear()
{
    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        vis[i]=false;
    }
}

void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=k;
    }
    edge.clear();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        LL val;
        cin>>u>>v>>val;
        edge.push_back({u,v,val});
    }
    for(int i=1;i<=n;i++)
        if(!a[i])
        {
            cout<<0<<endl;
            return;
        }
    ans=inf;
    for(int _=1;_<=TRAIL;_++)
    {
        shuffle(edge.begin(),edge.end(),rng);
        clear();
        peach fu(n);
        for(auto &[u,v,val]:edge)
        {
            if(fu.find(u)==fu.find(v)) continue;
            fu.combine(u,v);
            p[u].push_back({v,val});
            p[v].push_back({u,val});
        }
        for(int i=1;i<=n;i++)
            if(!vis[i]) get_cent(get_root(i));
    }
    // cout<<ans<<endl;
    cout<<(ans==inf?-1:ans)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}