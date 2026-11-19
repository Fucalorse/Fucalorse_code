#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,LEN=17;

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

struct qwq
{
    int u,v;
};

int n,q;
int depth[MAX],path[MAX],f[MAX],top[MAX],son[MAX];
vector<int>p[MAX];

struct fucalorse
{
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
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    int query(int u,int v)
    {
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            u=f[top[u]];
        }
        return depth[u]<depth[v]?u:v;
    }
    bool dis(qwq f,qwq g)
    {
        int x=query(f.u,f.v),y=query(g.u,g.v);
        if(depth[x]<depth[y]) swap(x,y),swap(f,g);
        if(query(x,g.u)==x||query(x,g.v)==x) return true;
        return false;
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
        qwq f={read(),read()},g={read(),read()};
        if(fu.dis(f,g)) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}