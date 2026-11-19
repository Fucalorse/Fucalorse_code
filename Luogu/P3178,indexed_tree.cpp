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
        LL op[MAX],g[MAX];
        int lowbit(int pos) { return pos&-pos; }
        LL query(int n)
        {
            int i=n+1;
            LL ans=0;
            while(n)
            {
                ans+=i*op[n]-g[n];
                n-=lowbit(n);
            }
            return ans;
        }
    public:
        void update(int pos,const LL &k)
        {
            int i=pos;
            while(pos<=n)
            {
                op[pos]+=k;
                g[pos]+=i*k;
                pos+=lowbit(pos);
            }
        }
        LL get(const int &l,const int &r) { return query(r)-query(l-1); }
}op;

struct fucalorse
{
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
    void update(int x,const int &p,const LL &k)
    {
        if(p==1) op.update(id[x],k),op.update(id[x]+1,-k);
        else op.update(id[x],k),op.update(id[x]+path[x],-k);
    }
    LL query(int u,int v)
    {
        LL ans=0;
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans+=op.get(id[top[u]],id[u]);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return ans+op.get(id[u],id[v]);
    }
}fu;

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
    fu.dfs(1,0);
    fu.find(1,1);
    fu.debut();
    while(q--)
    {
        int p=read();
        if(p<=2)
        {
            int x=read();
            LL k=read();
            fu.update(x,p,k);
        }
        else
        {
            int x=read();
            printf("%lld\n",fu.query(1,x));
        }
    }
    return 0;
}