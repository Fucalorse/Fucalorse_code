#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5e5+90,inf=1e9;

struct qwq
{
    int d1,d2;
    int dfn1,dfn2;
}op[MAX<<2];

int n,k,q;
int dist[MAX],a[MAX];
int f[MAX],depth[MAX],sz[MAX],son[MAX],id[MAX],top[MAX],pre[MAX],tot=0;
vector<int>p[MAX];

struct peach
{
    private:
        qwq merge(const qwq &a,const qwq &b)
        {
            if(a.d1==inf) return b;
            if(b.d1==inf) return a;
            int p1=a.d1<b.d1?a.dfn1:b.dfn1;
            int p2=a.d2<b.d2?a.dfn2:b.dfn2;
            return {min(a.d1,b.d1),min(a.d2,b.d2),p1,p2};
        }
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id]={3*dist[pre[l]]-depth[pre[l]],3*dist[pre[l]]+depth[pre[l]],l,l};
                // cout<<pre[l]<<' '<<dist[pre[l]]<<endl;
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=merge(op[hl],op[hr]);
        }
        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return {inf,inf,inf,inf};
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return merge(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        qwq combine(const qwq &a,const qwq &b)
        {
            if(a.d1==inf) return b;
            if(b.d1==inf) return a;
            int p1=a.d1<b.d1?a.dfn1:b.dfn1;
            int p2=a.d2<b.d2?a.dfn2:b.dfn2;
            return {min(a.d1,b.d1),min(a.d2,b.d2),p1,p2};            
        }
        void debut() { create(1,n,1); }
        qwq get(int st,int ed) { return query(1,n,1,st,ed); }
}fu;

struct fucalorse
{
    int dfs(int ch,int fa)
    {
        f[ch]=fa;
        depth[ch]=depth[fa]+1;
        sz[ch]=1;
        int maxn=-1;
        for(auto &to:p[ch])
        {
            if(to==fa) continue;
            sz[ch]+=dfs(to,ch);
            if(sz[to]>maxn) maxn=sz[to],son[ch]=to;
        }
        return sz[ch];
    }
    void find(int pos,int dfn)
    {
        id[pos]=++tot;
        pre[tot]=pos;
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto &to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    int lca(int u,int v)
    {
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            u=f[top[u]];
        }
        return depth[u]<depth[v]?u:v;
    }
    qwq find_min(int u,int fa)
    {
        qwq ans={inf,inf,inf,inf};
        if(u==fa) return ans;
        while(depth[top[u]]>depth[fa])
        {
            ans=fu.combine(ans,fu.get(id[top[u]],id[u]));
            u=f[top[u]];
        }
        return fu.combine(ans,fu.get(id[fa],id[u]));
    }
    int query(int u,int v)
    {
        int fa=lca(u,v);
        // cout<<"::"<<u<<' '<<v<<' '<<fa<<endl;
        int ans=depth[u]+depth[v]-2*depth[fa];
        qwq path1=find_min(u,fa),path2=find_min(v,fa);
        int a=path1.d1+depth[u],b=path2.d2+depth[u]-2*depth[fa];
        // cout<<ans<<' '<<path1.d1<<' '<<path2.d2<<endl;
        // cout<<a<<' '<<b<<endl;
        return min(2*ans,ans+min(a,b));
    }
}fufu;

void bfs()
{
    memset(dist,0x3f,sizeof(dist));
    queue<pair<int,int>>q;
    for(int i=1;i<=k;i++)
    {
        q.push({a[i],0});
        dist[a[i]]=0;
    }
    while(q.size())
    {
        auto [pos,val]=q.front();q.pop();
        for(auto &to:p[pos])
        {
            if(dist[to]>val+1)
            {
                dist[to]=val+1;
                q.push({to,dist[to]});
            }
        }
    }
    // for(int i=1;i<=n;i++)
    //     cout<<dist[i]<<' ';
    // cout<<endl;
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for(int i=1;i<=k;i++)
        cin>>a[i];
    bfs();
    fufu.dfs(1,0);
    fufu.find(1,1);
    fu.debut();
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<fufu.query(u,v)<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}