#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90,inf=2e9;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

struct ovo
{
    int u,v,val,id;
    bool operator<(const ovo &a)const { return val<a.val; }
};
vector<ovo>edge;

int n,m;
bool vis[MAX];
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX],id[MAX],qwq=0;
LL ans[MAX];
vector<int>p[MAX];

struct furina
{
    private:
        struct tree
        {
            int minn,lazy;
            tree() { minn=lazy=inf; }
        }op[MAX<<2];
        void down(int id)
        {
            if(op[id].lazy!=inf)
            {
                int hl=id<<1,hr=id<<1|1;
                op[hl].minn=min(op[hl].minn,op[id].lazy);
                op[hl].lazy=min(op[hl].lazy,op[id].lazy);
                op[hr].minn=min(op[hr].minn,op[id].lazy);
                op[hr].lazy=min(op[hr].lazy,op[id].lazy);
                op[id].lazy=inf;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].minn=min(op[id].minn,k);
                op[id].lazy=min(op[id].lazy,k);
                return;
            }
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id].minn=min(op[hl].minn,op[hr].minn);
        }
        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return inf;
            if(st<=l&&r<=ed) return op[id].minn;
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return min(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void update(const int &st,const int &ed,const int &k)
        {
            if(st>ed) return;
            dfs(1,n,1,st,ed,k);
        }
        int get(const int &st,const int &ed)
        {
            if(st>ed) return inf;
            return query(1,n,1,st,ed);
        }
}fu;

struct peach
{
    private:
        int fa[MAX];
    public:
        peach()
        {
            for(int i=0;i<MAX;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
}op;

struct fucalorse
{
    int dfs(int ch,int fa)
    {
        f[ch]=fa;
        depth[ch]=depth[fa]+1;
        path[ch]=1;
        int maxn=-1;
        for(auto &to:p[ch])
        {
            if(to==fa) continue;
            path[ch]+=dfs(to,ch);
            if(path[to]>maxn) maxn=path[to],son[ch]=to;
        }
        return path[ch];
    }
    void find(int pos,int dfn)
    {
        id[pos]=++qwq;
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto &to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    void update(int u,int v,const int &x)
    {
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            fu.update(id[top[u]],id[u],x);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        fu.update(id[u]+1,id[v],x);
    }
    int query(int u,int v)
    {
        int ans=inf;
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans=min(ans,fu.get(id[top[u]],id[u]));
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return min(ans,fu.get(id[u]+1,id[v]));
    }
}fufu;

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        edge.push_back({u,v,val,i});
    }
    sort(edge.begin(),edge.end());
    LL minn=0;
    for(size_t j=0;j<edge.size();j++)
    {
        auto &i=edge[j];
        if(op.find(i.u)==op.find(i.v)) continue;
        vis[j]=true;
        p[i.u].push_back(i.v);
        p[i.v].push_back(i.u);
        op.combine(i.u,i.v);
        minn+=i.val;
    }
    fufu.dfs(1,0);
    fufu.find(1,1);
    for(size_t j=0;j<edge.size();j++)
    {
        if(vis[j]) continue;
        auto &i=edge[j];
        fufu.update(i.u,i.v,i.val);
    }
    for(size_t j=0;j<edge.size();j++)
    {
        auto &i=edge[j];
        if(!vis[j]) ans[i.id]=minn;
        else
        {
            int now=fufu.query(i.u,i.v);
            if(now==inf) ans[i.id]=-1;
            else ans[i.id]=minn+now-i.val;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}