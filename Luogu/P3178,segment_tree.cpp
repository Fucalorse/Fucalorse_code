#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90;

LL read()
{
    LL ans=0,f=1;
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
LL num[MAX],pre[MAX];
int f[MAX],path[MAX],son[MAX],depth[MAX],top[MAX],id[MAX],qwq=0;
vector<int>p[MAX];

struct furina
{
    private:
        struct tree
        {
            LL sum,lazy;
        }op[MAX<<2];
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id].sum=num[l];
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id].sum=op[hl].sum+op[hr].sum;
        }
        void down(int l,int r,int id)
        {
            if(op[id].lazy)
            {
                int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
                int lenl=mid-l+1,lenr=r-mid;
                op[hl].sum+=lenl*op[id].lazy;
                op[hl].lazy+=op[id].lazy;
                op[hr].sum+=lenr*op[id].lazy;
                op[hr].lazy+=op[id].lazy;
                op[id].lazy=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const LL &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].sum+=(r-l+1)*k;
                op[id].lazy+=k;
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id].sum=op[hl].sum+op[hr].sum;
        }
        LL query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].sum;
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }
    public:
        void debut() { create(1,n,1); }
        void update(const int &st,const int &ed,const LL &k)
        {
            dfs(1,n,1,st,ed,k);
        }
        LL get(const int &st,const int &ed) { return query(1,n,1,st,ed); }
}fu;

struct fucalorse
{
    void debut() { fu.debut(); }
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
        num[qwq]=pre[pos];
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    void update(int x,const int &p,const LL &k)
    {
        if(p==1) fu.update(id[x],id[x],k);
        else fu.update(id[x],id[x]+path[x]-1,k);
    }
    LL query(int u,int v)
    {
        LL ans=0;
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans+=fu.get(id[top[u]],id[u]);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return ans+fu.get(id[u],id[v]);
    }
}fufu;

int main()
{
    n=read(),q=read();
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
    while(q--)
    {
        int p=read();
        if(p<=2)
        {
            int x=read();
            LL k=read();
            fufu.update(x,p,k);
        }
        else
        {
            int x=read();
            printf("%lld\n",fufu.query(1,x));
        }
    }
    return 0;
}