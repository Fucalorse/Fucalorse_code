#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e6,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int minp[MAX];
vector<int>prime;
vector<vector<int>>primes(LEN+1);
void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            prime.push_back(i);
        }
        for(auto &j:prime)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }

    for(int i=2;i<=n;i++)
    {
        int x=i;
        while(x>1)
        {
            int p=minp[x];
            primes[i].push_back(p);
            while(x%p==0) x/=p;
        }
    }
}

int timer=0;
int f[MAX],depth[MAX],top[MAX],dfn[MAX],son[MAX],sz[MAX];

void dfs(int ch,int fa,vector<vector<int>>& adj)
{
    f[ch]=fa;
    depth[ch]=depth[fa]+1;
    sz[ch]=1;
    int maxn=-1;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);
        sz[ch]+=sz[to];
        if(sz[to]>maxn) maxn=sz[to],son[ch]=to;
    }
}

void find(int pos,int head,vector<vector<int>>& adj)
{
    top[pos]=head;
    dfn[pos]=++timer;
    if(!son[pos]) return;
    find(son[pos],head,adj);

    for(auto &to:adj[pos])
    {
        if(to==f[pos]||to==son[pos]) continue;
        find(to,to,adj);
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

struct Bit
{
    private:
        int n;
        vector<int>pos,op;
    public:
        void assign(const vector<int>& _pos)
        {
            pos=_pos;
            sort(pos.begin(),pos.end());
            pos.erase(unique(pos.begin(),pos.end()),pos.end());
            n=(int)pos.size();
            op.assign((int)pos.size()+1,0);
        }
        
        void update(int x,int k)
        {
            int rank=lower_bound(pos.begin(),pos.end(),x)-pos.begin()+1;
            for(int i=rank;i<=n;i+=i&-i)
                op[i]+=k;
        }

        int query(int x)
        {
            int ans=0,rank=upper_bound(pos.begin(),pos.end(),x)-pos.begin();
            for(int i=rank;i;i-=i&-i)
                ans+=op[i];
            return ans;
        }

        void update_range(int l,int r,int k) { update(l,k),update(r+1,-k); }
        int query_range(int l,int r) { return query(r)-query(l-1); }
};

struct prime_data
{
    int prime,cnt;
};

struct node_data
{
    int a,u,v;
}op[MAX];

int n;
int c[MAX];

vector<prime_data> split(int x)
{
    vector<prime_data>op;
    while(x>1)
    {
        int p=minp[x];
        prime_data cur={p,0};
        while(x%p==0)
        {
            cur.cnt++;
            x/=p;
        }
        op.push_back(cur);
    }
    return op;
}

void solve()
{
    cin>>n>>c[1];

    op[1].a=c[1];
    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>op[i].a>>op[i].u>>op[i].v;
        adj[i].push_back(op[i].v);
        adj[op[i].v].push_back(i);
    }

    dfs(1,0,adj);
    find(1,1,adj);

    vector<Bit>fu(LEN+1);
    vector<vector<int>>pos(LEN+1);
    for(int i=1;i<=n;i++)
    {
        for(auto &prime:primes[op[i].a])
        {
            pos[prime].push_back(dfn[i]);
            pos[prime].push_back(dfn[i]+sz[i]);
        }
    }

    for(int i=2;i<=LEN;i++)
        if(!pos[i].empty()) fu[i].assign(pos[i]);

    auto update_sub_tree=[&](int pos,const vector<prime_data>& op)->void
    {
        for(auto &[prime,cnt]:op)
        {
            if(cnt==0) continue;
            fu[prime].update_range(dfn[pos],dfn[pos]+sz[pos]-1,cnt);
        }
    };
    update_sub_tree(1,split(c[1]));

    auto cal=[&](int u,int v,Bit& fu)->int
    {
        int lca=LCA(u,v);
        return fu.query(dfn[u])+fu.query(dfn[v])-fu.query(dfn[lca])-fu.query(dfn[f[lca]]);
    };

    for(int i=2;i<=n;i++)
    {
        c[i]=1;
        const auto &[a,u,v]=op[i];
        auto cur=split(a);
        for(auto &[prime,cnt]:cur)
        {
            int now=cal(u,v,fu[prime]);
            cnt=max(0,cnt-now);

            for(int round=1;round<=cnt;++round)
                c[i]*=prime;
        }
        update_sub_tree(i,cur);
    }

    for(int i=1;i<=n;i++)
        cout<<c[i]<<' ';
    cout<<endl;
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