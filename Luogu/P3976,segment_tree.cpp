#include <bits/stdc++.h>
using namespace std;

const int MAX=5e4+90,inf=2e9;

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

int n,q;
int pre[MAX],num[MAX],tot=0;
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX],id[MAX];
vector<int>p[MAX];

struct qwq
{
    int maxn,minn;
    int lmax,rmax;
    int lazy;
}op[MAX<<2];

struct peach
{
    qwq merge(const qwq &a,const qwq &b)
    {
        if(a.lmax==inf) return b;
        if(b.lmax==inf) return a;
        int lmax=max(max(a.lmax,b.lmax),b.maxn-a.minn);
        int rmax=max(max(a.rmax,b.rmax),a.maxn-b.minn);
        return {max(a.maxn,b.maxn),min(a.minn,b.minn),lmax,rmax,0};
    }
    void down(int id)
    {
        if(op[id].lazy)
        {
            int hl=id<<1,hr=id<<1|1;
            int &k=op[id].lazy;
            op[hl].maxn+=k,op[hl].minn+=k,op[hl].lazy+=k;
            op[hr].maxn+=k,op[hr].minn+=k,op[hr].lazy+=k;
            op[id].lazy=0;
        }
    }
    void create(int l,int r,int id)
    {
        if(l==r)
        {
            op[id]={num[l],num[l],0,0,0};
            return;
        }
        int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
        create(l,mid,hl);
        create(mid+1,r,hr);
        op[id]=merge(op[hl],op[hr]);
    }
    void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
    {
        if(st<=l&&r<=ed)
        {
            op[id].maxn+=k,op[id].minn+=k,op[id].lazy+=k;
            return;
        }
        down(id);
        int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
        if(st<=mid) dfs(l,mid,hl,st,ed,k);
        if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
        op[id]=merge(op[hl],op[hr]);
    }
    qwq query(int l,int r,int id,const int &st,const int &ed)
    {
        if(r<st||l>ed) return {inf,inf,inf,inf,0};
        if(st<=l&&r<=ed) return op[id];
        down(id);
        int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
        return merge(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
    }

    void update(const int &st,const int &ed,const int &k) { dfs(1,n,1,st,ed,k); }
    qwq get(const int &st,const int &ed) { return query(1,n,1,st,ed); }
    int maxn(qwq r,qwq l)
    {
        swap(r.lmax,r.rmax);
        return merge(r,l).lmax;
    }
}fu;

struct fucalorse
{
    void debut() { fu.create(1,n,1); }
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
        id[pos]=++tot;
        num[tot]=pre[pos];
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto &to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    int query(int u,int v,const int &k)
    {
        qwq l={inf,inf,inf,inf,0},r={inf,inf,inf,inf,0};
        while(top[u]!=top[v])
        {
            if(depth[top[u]]>depth[top[v]])
            {
                r=fu.merge(fu.get(id[top[u]],id[u]),r);
                fu.update(id[top[u]],id[u],k);
                u=f[top[u]];
            }
            else
            {
                l=fu.merge(fu.get(id[top[v]],id[v]),l);
                fu.update(id[top[v]],id[v],k);
                v=f[top[v]];
            }
        }
        if(depth[u]<depth[v])
        {
            l=fu.merge(fu.get(id[u],id[v]),l);
            fu.update(id[u],id[v],k);
        }
        else
        {
            r=fu.merge(fu.get(id[v],id[u]),r);
            fu.update(id[v],id[u],k);
        }
        return fu.maxn(r,l);
    }
}fufu;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        pre[i]=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fufu.dfs(1,0);
    fufu.find(1,1);
    fufu.debut();
    q=read();
    while(q--)
    {
        int u=read(),v=read(),k=read();
        printf("%d\n",fufu.query(u,v,k));
    }
    return 0;
}