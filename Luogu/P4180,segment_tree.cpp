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
    int u,v,val;
    bool operator<(const ovo &a)const { return val<a.val; }
};
vector<ovo>edge;

int n,m;
bool vis[MAX<<4];
int pre[MAX],num[MAX],qwq=0;
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX],id[MAX];
vector<pair<int,int>>p[MAX];

struct furina
{
    private:
        struct peach
        {
            int maxa,maxb;
            peach(int a=-inf,int b=-inf):maxa(a),maxb(b){}
        }op[MAX<<2];
        peach merge(const peach &a,const peach &b)
        {
            if(a.maxa==-inf) return b;
            if(b.maxa==-inf) return a;
            peach ans=peach(max(a.maxa,b.maxa),-inf);
            int now=max(a.maxb,b.maxb);
            if(a.maxa!=b.maxa) ans.maxb=min(a.maxa,b.maxa);
            ans.maxb=max(ans.maxb,now);
            return ans;
        }
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id].maxa=num[l];
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=merge(op[hl],op[hr]);
        }
        peach query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return {-inf,-inf};
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return merge(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void debut() { create(1,n,1); }
        LL get(const int &st,const int &ed,const int &val)
        {
            if(st>ed) return inf;
            peach now=query(1,n,1,st,ed);
            if(now.maxa!=val) return (LL)val-now.maxa;
            else if(now.maxb!=-inf) return (LL)val-now.maxb;
            return inf;
        }
}op;

struct cake
{
    private:
        int fa[MAX];
    public:
        cake()
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
}fu;

struct fucalorse
{
    void debut() { op.debut(); }
    int dfs(int ch,int fa)
    {
        f[ch]=fa;
        depth[ch]=depth[fa]+1;
        path[ch]=1;
        int maxn=-1;
        for(auto &i:p[ch])
        {
            int &to=i.first,&val=i.second;
            if(to==fa) continue;
            pre[to]=val;
            path[ch]+=dfs(to,ch);
            if(path[to]>maxn) maxn=path[to],son[ch]=to;
        }
        return path[ch];
    }
    void find(int pos,int dfn)
    {
        id[pos]=++qwq;
        num[qwq]=pre[pos];
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto &i:p[pos])
        {
            int &to=i.first;
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    LL query(int u,int v,const int &x)
    {
        LL ans=inf;
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans=min(ans,op.get(id[top[u]],id[u],x));
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return min(ans,op.get(id[u]+1,id[v],x));
    }
}fufu;

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        if(u==v) continue;
        edge.push_back({u,v,val});
    }
    sort(edge.begin(),edge.end());
    LL total=0;
    for(size_t pos=0;pos<edge.size();pos++)
    {
        auto &i=edge[pos];
        if(fu.find(i.u)==fu.find(i.v)) continue;
        vis[pos]=true;
        total+=i.val;
        fu.combine(i.u,i.v);
        p[i.u].push_back({i.v,i.val});
        p[i.v].push_back({i.u,i.val});
    }
    fufu.dfs(1,0);
    fufu.find(1,1);
    fufu.debut();
    LL ans=inf;
    for(size_t pos=0;pos<edge.size();pos++)
    {
        if(vis[pos]) continue;
        auto &i=edge[pos];
        ans=min(ans,(LL)fufu.query(i.u,i.v,i.val));
    }
    printf("%lld\n",total+ans);
    return 0;
}