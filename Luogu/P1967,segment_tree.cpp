#include <bits/stdc++.h>
using namespace std;

const int MAX=1e4+90,inf=2e9;

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
    bool operator<(const ovo &a)const { return val>a.val; }
};
vector<ovo>edge;

int n,m,q;
int pre[MAX],num[MAX],qwq=0;
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX],id[MAX];
vector<pair<int,int>>p[MAX];

struct furina
{
    private:
        int op[MAX<<2];
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id]=num[l];
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=min(op[hl],op[hr]);
        }
        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return inf;
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return min(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void debut() { create(1,n,1); }
        int get(const int &st,const int &ed)
        {
            if(st>ed) return inf;
            else return query(1,n,1,st,ed);
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
            if(x!=fa[x])
                fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
}op;

struct fucalorse
{
    void debut() { fu.debut(); }
    int dfs(int ch,int fa)
    {
        f[ch]=fa;
        depth[ch]=depth[fa]+1;
        path[ch]=1;
        int maxn=-1;
        for(auto &i:p[ch])
        {
            int &to=i.first;
            if(to==fa) continue;
            pre[to]=i.second;
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
    int query(int u,int v)
    {
        if(op.find(u)!=op.find(v)) return -1;
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
        edge.push_back({u,v,val});
    }
    sort(edge.begin(),edge.end());
    for(auto &i:edge)
    {
        if(op.find(i.u)==op.find(i.v)) continue;
        p[i.u].push_back({i.v,i.val});
        p[i.v].push_back({i.u,i.val});
        op.combine(i.u,i.v);
    }
    for(int i=1;i<=n;i++)
    {
        if(id[i]) continue;
        fufu.dfs(i,0);
        fufu.find(i,i);
    }
    fufu.debut();
    q=read();
    while(q--)
    {
        int st=read(),ed=read();
        printf("%d\n",fufu.query(st,ed));
    }
    return 0;
}