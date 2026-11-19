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
        int op[MAX],g[MAX];
        int lowbit(int pos) { return pos&-pos; }
        int query(int pos)
        {
            int ans=0,i=pos+1;
            while(pos)
            {
                ans+=i*op[pos]-g[pos];
                pos-=lowbit(pos);
            }
            return ans;
        }
        void insert(int pos,const int &k)
        {
            int i=pos;
            while(pos<=n)
            {
                op[pos]+=k;
                g[pos]+=i*k;
                pos+=lowbit(pos);
            }
        }
    public:
        void update(const int &l,const int &r) { insert(l,1),insert(r+1,-1); }
        int find(const int &l,const int &r) { return query(r)-query(l-1); }
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
            ans+=op.find(id[top[u]],id[u]);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return ans+op.find(id[u]+1,id[v]);
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