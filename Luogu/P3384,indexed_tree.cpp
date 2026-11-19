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
        LL op[MAX],g[MAX];
        int lowbit(int pos) { return pos&-pos; }
        LL query(int pos)
        {
            int i=pos+1;
            LL ans=0;
            while(pos)
            {
                ans=(ans+i*op[pos]-g[pos]+mod)%mod;
                pos-=lowbit(pos);
            }
            return (ans+mod)%mod;
        }
    public:
        void update(int pos,const LL &k)
        {
            int i=pos;
            while(pos<=n)
            {
                op[pos]=(op[pos]+k+mod)%mod;
                g[pos]=(g[pos]+i*k+mod)%mod;
                pos+=lowbit(pos);
            }
        }
        LL find(const int &st,const int &ed)
        {
            return (query(ed)-query(st-1)+mod)%mod;
        }
};

struct fucalorse
{
    furina op;
    void debut()
    {
        for(int i=1;i<=n;i++)
            op.update(i,num[i]-num[i-1]);
    }
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
            op.update(id[top[u]],k);
            op.update(id[u]+1,-k);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        op.update(id[u],k);
        op.update(id[v]+1,-k);
    }
    LL query_path(int u,int v)
    {
        LL ans=0;
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans=(ans+op.find(id[top[u]],id[u]))%mod;
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return (ans+op.find(id[u],id[v]))%mod;
    }
    void update_tree(int x,const LL &k)
    {
        op.update(id[x],k);
        op.update(id[x]+path[x],-k);
    }
    LL query_tree(int x)
    {
        return op.find(id[x],id[x]+path[x]-1);
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