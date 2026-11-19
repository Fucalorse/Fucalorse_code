#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=2e5+90,inf=2e9;

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
}edge[MAX<<2];

int t,n,m;
bool vis[MAX<<2];
int pre[MAX],num[MAX],qwq=0;
int f[MAX],depth[MAX],son[MAX],path[MAX],top[MAX],id[MAX];
vector<vector<pair<int,int>>>p;

struct furina
{
    private:
        struct qwq
        {
            int maxo,maxe;
        }op[MAX<<2];
        qwq merge(const qwq &a,const qwq &b)
        {
            if(a.maxe==inf) return b;
            if(b.maxe==inf) return a;
            return qwq{max(a.maxo,b.maxo),max(a.maxe,b.maxe)};
        }
        void create(int l,int r,int id)
        {
            op[id]={-inf,-inf};
            if(l==r)
            {
                if(num[l]%2==1) op[id].maxo=num[l];
                else op[id].maxe=num[l];
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=merge(op[hl],op[hr]);
        }
        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return {inf,inf};
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return merge(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void debut() { create(1,n,1); }
        pair<int,int> get(const int &st,const int &ed,const int &k)
        {
            if(st>ed) return {inf,inf};
            qwq now=query(1,n,1,st,ed);
            pair<int,int>ans={inf,inf};
            if(now.maxo!=-inf)
            {
                int a=k-now.maxo;
                if(a%2==1) ans.first=min(ans.first,a);
                else ans.second=min(ans.second,a);
            }
            if(now.maxe!=-inf)
            {
                int a=k-now.maxe;
                if(a%2==1) ans.first=min(ans.first,a);
                else ans.second=min(ans.second,a);
            }
            return ans;
        }
}fu;

struct peach
{
    private:
        int fa[MAX];
    public:
        void debut(int n)
        {
            for(int i=0;i<=n;i++)
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
    void debut() { fu.debut(); }
    int dfs(int ch,int fa)
    {
        f[ch]=fa;
        depth[ch]=depth[fa]+1;
        path[ch]=1;
        int maxn=-1;
        for(auto &[to,val]:p[ch])
        {
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
        for(auto &[to,val]:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    pair<int,int> query(int u,int v,const int &k)
    {
        pair<int,int>ans={inf,inf};
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            auto [odd,even]=fu.get(id[top[u]],id[u],k);
            if(odd!=inf) ans.first=min(ans.first,odd);
            if(even!=inf) ans.second=min(ans.second,even);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        auto [odd,even]=fu.get(id[u]+1,id[v],k);
        if(odd!=inf) ans.first=min(ans.first,odd);
        if(even!=inf) ans.second=min(ans.second,even);
        return ans;    
    }
}fufu;

void clear()
{
    memset(f,0,sizeof(int)*(n+5));
    memset(depth,0,sizeof(int)*(n+5));
    memset(path,0,sizeof(int)*(n+5));
    memset(son,0,sizeof(int)*(n+5));
    memset(top,0,sizeof(int)*(n+5));
    memset(id,0,sizeof(int)*(n+5));
    memset(pre,0,sizeof(int)*(n+5));
    memset(num,0,sizeof(int)*(n+5));
    memset(vis,false,sizeof(bool)*(m+5));
    qwq=0;
}

int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        clear();
        p.assign(n+5,vector<pair<int,int>>{});
        for(int i=1;i<=m;i++)
        {
            int u=read(),v=read(),val=read();
            edge[i]={u,v,val};
        }
        if(m<n-1)
        {
            printf("-1 -1\n");
            continue;
        }
        sort(edge+1,edge+m+1);
        op.debut(n);
        LL minn=0,odd=1e18,even=1e18;
        int total=n-1;
        for(int i=1;i<=m;i++)
        {
            auto &[u,v,val]=edge[i];
            if(op.find(u)==op.find(v)) continue;
            op.combine(u,v);
            minn+=(LL)val;
            vis[i]=true;
            p[u].push_back({v,val});
            p[v].push_back({u,val});
            if(--total==0) break;
        }
        if(total!=0)
        {
            printf("-1 -1\n");
            continue;
        }
        if(minn%2==1) odd=minn;
        else even=minn;
        fufu.dfs(1,0);
        fufu.find(1,1);
        fufu.debut();
        for(int i=1;i<=m;i++)
        {
            if(vis[i]) continue;
            auto &[u,v,val]=edge[i];
            auto [a,b]=fufu.query(u,v,val);
            if(a!=inf)
            {
                LL aft=minn+a;
                if(aft%2==1) odd=min(odd,aft);
                else even=min(even,aft);
            }
            if(b!=inf)
            {
                LL aft=minn+b;
                if(aft%2==1) odd=min(odd,aft);
                else even=min(even,aft);
            }
        }
        printf("%lld %lld\n",even==1e18?-1:even,odd==1e18?-1:odd);
    }
    return 0;
}