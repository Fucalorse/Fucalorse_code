#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90;

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
    int u,v,lca,depth;
    bool operator<(const ovo &a)const { return depth>a.depth; }
}num[MAX];

int n,q;
int city[MAX];
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX],id[MAX],node[MAX],qwq=0;
vector<int>p[MAX];

struct peach
{
    private:
        int op[MAX];
    public:
        void update(int pos,const int &k)
        {
            while(pos<=n)
            {
                op[pos]+=k;
                pos+=pos&-pos;
            }
        }
        int query(int pos)
        {
            int ans=0;
            while(pos)
            {
                ans+=op[pos];
                pos-=pos&-pos;
            }
            return ans;
        }
}op;

struct fucalorse
{
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
        // cout<<pos<<' '<<id[pos]<<endl;
        node[qwq]=pos;
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto &to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    int LCA(int u,int v)
    {
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            u=f[top[u]];
        }
        return depth[u]<depth[v]?u:v;
    }
    int up(int u,int k)
    {
        while(182497)
        {
            if(depth[u]-depth[top[u]]>=k) return node[id[u]-k];
            k-=depth[u]-depth[top[u]]+1;
            u=f[top[u]];
        }
        return -10086;
    }
    void update(int u,const int &k)
    {
        op.update(id[u],k);
        op.update(id[u]+path[u],-k);
    }
    int query(int u,int v)
    {
        int fa=LCA(u,v);
        return op.query(id[u])+op.query(id[v])-op.query(id[fa])-op.query(id[f[fa]]);
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
    while(q--)
    {
        int k=read();
        for(int i=1;i<=k;i++)
        {
            city[i]=read();
            fu.update(city[i],1);
        }
        vector<int>rest;
        int len=0,ans=0;
        for(int i=2;i<=k;i++)
            if(fu.query(city[i-1],city[i])==2)
            {
                int fa=fu.LCA(city[i],city[i-1]),u=city[i],v=city[i-1];
                if(depth[u]>depth[v]) swap(u,v);
                if(u==fa)
                {
                    v=f[v];
                    if(u==v) ans++;
                    else
                    {
                        u=fu.up(v,depth[v]-depth[u]-1);
                        num[++len]={u,v,u,depth[u]};
                    }
                }
                else num[++len]={f[u],f[v],fa,depth[fa]};
            }
        for(int i=1;i<=k;i++)
            fu.update(city[i],-1);
        sort(num+1,num+len+1);
        for(int i=1;i<=len;i++)
            if(fu.query(num[i].u,num[i].v)==0)
            {
                ans++;
                fu.update(num[i].lca,1);
                rest.push_back(num[i].lca);
            }
        for(auto &i:rest)
            fu.update(i,-1);
        printf("%d\n",k-1-ans);
    }
    return 0;
}