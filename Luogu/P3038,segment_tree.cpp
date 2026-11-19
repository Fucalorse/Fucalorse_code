#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

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
int f[MAX],depth[MAX],son[MAX],top[MAX],path[MAX],id[MAX],qwq=0;
vector<int>p[MAX];

struct furina
{
    private:
        struct tree
        {
            int sum,lazy;
        }op[MAX<<2];
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
        void dfs(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed)
            {
                op[id].sum+=r-l+1;
                op[id].lazy++;
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed);
            if(mid<ed) dfs(mid+1,r,hr,st,ed);
            op[id].sum=op[hl].sum+op[hr].sum;
        }
        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].sum;
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }
    public:
        void update(const int &st,const int &ed) { dfs(1,n,1,st,ed); }
        int get(const int &st,const int &ed) { return query(1,n,1,st,ed); }
};

struct fucalorse
{
    furina op;
    int dfs(int ch,int fa)
    {
        f[ch]=fa;
        depth[ch]=depth[fa]+1;
        path[ch]=1;
        int maxn=-1;
        for(auto to:p[ch])
            if(to!=fa)
            {
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
        for(auto to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    void update(int u,int v)
    {
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            op.update(id[top[u]],id[u]);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        op.update(id[u]+1,id[v]);
    }
    int query(int u,int v)
    {
        int ans=0;
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans+=op.get(id[top[u]],id[u]);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return ans+op.get(id[u]+1,id[v]);
    }
}fu;

int main()
{
    n=read(),q=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fu.dfs(1,0);
    fu.find(1,1);
    for(int i=1;i<=q;i++)
    {
        char c;
        scanf(" %c",&c);
        int st=read(),ed=read();
        if(c=='P') fu.update(st,ed);
        else printf("%d\n",fu.query(st,ed));
    }
    return 0;
}