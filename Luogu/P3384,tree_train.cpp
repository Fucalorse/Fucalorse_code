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

struct edge
{
    int next,to;
}p[MAX<<1];

int head[MAX],cnt=1;
void add(int from,int to)
{
    p[cnt].to=to;
    p[cnt].next=head[from];
    head[from]=cnt;
    cnt++;
}

int n,q,st,mod;
LL pre[MAX],num[MAX];
int f[MAX],son[MAX],depth[MAX],top[MAX],path[MAX],id[MAX],qwq=0;

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
                op[id].sum=num[l]%mod;
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id].sum=(op[hl].sum+op[hr].sum)%mod;
        }
        void down(int l,int r,int id)
        {
            if(op[id].lazy)
            {
                int mid=(l+r)>>1;
                int hl=id<<1,hr=id<<1|1;
                int lenl=mid-l+1,lenr=r-mid;

                op[hl].sum=(op[hl].sum+lenl*op[id].lazy)%mod;
                op[hl].lazy=(op[hl].lazy+op[id].lazy)%mod;

                op[hr].sum=(op[hr].sum+lenr*op[id].lazy)%mod;
                op[hr].lazy=(op[hr].lazy+op[id].lazy)%mod;

                op[id].lazy=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const LL &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].sum=(op[id].sum+(r-l+1)*k)%mod;
                op[id].lazy=(op[id].lazy+k)%mod;
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id].sum=(op[hl].sum+op[hr].sum)%mod;
        }
        LL query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].sum;
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            return (query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed))%mod;
        }
    public:
        void debut() { create(1,n,1); }
        void update(const int &st,const int &ed,const LL &k)
        {
            dfs(1,n,1,st,ed,k);
        }
        LL get(const int &st,const int &ed) { return query(1,n,1,st,ed); }
};

struct fucalorse
{
    furina op;
    void debut() { op.debut(); }
    int dfs(int ch,int fa)
    {
        f[ch]=fa;
        depth[ch]=depth[fa]+1;
        path[ch]=1;
        int maxn=-1;
        for(int i=head[ch];i;i=p[i].next)
        {
            int &to=p[i].to;
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
        for(int i=head[pos];i;i=p[i].next)
        {
            int &to=p[i].to;
            if(to==son[pos]||to==f[pos]) continue;
            find(to,to);
        }
    }
    void update_path(int u,int v,const LL &k)
    {
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            op.update(id[top[u]],id[u],k);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        op.update(id[u],id[v],k);
    }
    LL query_path(int u,int v)
    {
        LL ans=0;
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans=(ans+op.get(id[top[u]],id[u]))%mod;
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return (ans+op.get(id[u],id[v]))%mod;
    }
    void update_tree(int x,const LL &k)
    {
        op.update(id[x],id[x]+path[x]-1,k);
    }
    LL query_tree(int x)
    {
        return op.get(id[x],id[x]+path[x]-1);
    }
}fu;

int main()
{
    n=read(),q=read(),st=read(),mod=read();
    for(int i=1;i<=n;i++)
        pre[i]=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    fu.dfs(st,0);
    fu.find(st,st);
    fu.debut();
    while(q--)
    {
        int p=read();
        if(p==1)
        {
            int st=read(),ed=read();
            LL k=read();
            fu.update_path(st,ed,k);
        }
        else if(p==2)
        {
            int st=read(),ed=read();
            printf("%lld\n",fu.query_path(st,ed));
        }
        else if(p==3)
        {
            int x=read();
            LL k=read();
            fu.update_tree(x,k);
        }
        else
        {
            int x=read();
            printf("%lld\n",fu.query_tree(x));
        }
    }
    return 0;
}