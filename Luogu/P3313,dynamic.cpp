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

struct ui
{
    int w,c;
}pre[MAX],num[MAX];

int n,q;
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX],id[MAX],qwq=0;
vector<int>p[MAX];

struct furina
{
    private:
        struct tree
        {
            int l,r;
            int sum,maxn;
        }op[MAX*20];
        int root[MAX],cnt;
        
        void insert(int &pos,int l,int r,const int &x,const int &k)
        {
            if(!pos) pos=++cnt;
            op[pos].sum+=k,op[pos].maxn=max(op[pos].maxn,k);
            if(l==r) return;
            int mid=(l+r)>>1;
            if(x<=mid) insert(op[pos].l,l,mid,x,k);
            else insert(op[pos].r,mid+1,r,x,k);
        }
        void del(int &pos,int l,int r,const int &x)
        {
            if(l==r)
            {
                op[pos].maxn=op[pos].sum=0;
                return;
            }
            int mid=(l+r)>>1;
            if(x<=mid) del(op[pos].l,l,mid,x);
            else del(op[pos].r,mid+1,r,x);
            op[pos].sum=op[op[pos].l].sum+op[op[pos].r].sum;
            op[pos].maxn=max(op[op[pos].l].maxn,op[op[pos].r].maxn);
        }
        int get_max(int pos,int l,int r,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[pos].maxn;
            int mid=(l+r)>>1;
            return max(get_max(op[pos].l,l,mid,st,ed),get_max(op[pos].r,mid+1,r,st,ed));
        }
        int get_sum(int pos,int l,int r,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[pos].sum;
            int mid=(l+r)>>1;
            return get_sum(op[pos].l,l,mid,st,ed)+get_sum(op[pos].r,mid+1,r,st,ed); 
        }
    public:
        void update(const int &pos,const int &x,const int &k) { insert(root[pos],1,n,x,k); }
        void remove(const int &pos,const int &x) { del(root[pos],1,n,x); }
        int query_max(const int &pos,const int &st,const int &ed)
        {
            return get_max(root[pos],1,n,st,ed);
        }
        int query_sum(const int &pos,const int &st,const int &ed)
        {
            return get_sum(root[pos],1,n,st,ed);
        }
}op;

struct fucalorse
{
    void debut()
    {
        for(int i=1;i<=n;i++)
            op.update(num[i].c,i,num[i].w);
    }
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
        for(auto &to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    void update_cul(const int &x,const int &new_c)
    {
        op.remove(num[id[x]].c,id[x]);
        num[id[x]].c=new_c;
        op.update(new_c,id[x],num[id[x]].w);
    }
    void update_val(const int &x,const int &new_w)
    {
        op.remove(num[id[x]].c,id[x]);
        num[id[x]].w=new_w;
        op.update(num[id[x]].c,id[x],new_w);
    }
    int maxn(const int &x,int u,int v)
    {
        int ans=0,pos=num[id[x]].c;
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans=max(ans,op.query_max(pos,id[top[u]],id[u]));
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return max(ans,op.query_max(pos,id[u],id[v]));
    }
    int sum(const int &x,int u,int v)
    {
        int ans=0,pos=num[id[x]].c;
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans+=op.query_sum(pos,id[top[u]],id[u]);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return ans+op.query_sum(pos,id[u],id[v]);
    }
}fu;

int main()
{
    n=read(),q=read();
    for(int i=1;i<=n;i++)
        pre[i]={read(),read()};
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fu.dfs(1,0),fu.find(1,1);
    fu.debut();
    for(int i=1;i<=q;i++)
    {
        char s[5];
        scanf(" %s",s);
        if(s[1]=='C')
        {
            int x=read(),c=read();
            fu.update_cul(x,c);
        }
        else if(s[1]=='W')
        {
            int x=read(),w=read();
            fu.update_val(x,w);
        }
        else if(s[1]=='S')
        {
            int u=read(),v=read();
            printf("%d\n",fu.sum(u,u,v));
        }
        else
        {
            int u=read(),v=read();
            printf("%d\n",fu.maxn(u,u,v));
        }
    }
    return 0;
}