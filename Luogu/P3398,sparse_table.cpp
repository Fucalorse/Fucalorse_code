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
int f[MAX][LEN+2],depth[MAX];
vector<int>p[MAX];

struct fucalorse
{
    void dfs(int ch,int fa)
    {
        depth[ch]=depth[fa]+1;
        f[ch][0]=fa;
        for(auto to:p[ch])
            if(to!=fa) dfs(to,ch);
    }
    void create()
    {
        dfs(1,0);
        for(int k=1;(1<<k)<=n;k++)
            for(int i=1;i<=n;i++)
                f[i][k]=f[f[i][k-1]][k-1];
    }
    int query(int u,int v)
    {
        if(depth[u]<depth[v]) swap(u,v);
        int d=depth[u]-depth[v];
        for(int k=LEN;k>=0;k--)
            if((d>>k)&1) u=f[u][k];
        if(u==v) return u;
        for(int k=LEN;k>=0;k--)
            if(f[u][k]!=f[v][k])
            {
                u=f[u][k];
                v=f[v][k];
            }
        return f[u][0];
    }
    bool dis(qwq f,qwq g)
    {
        int x=query(f.u,f.v),y=query(g.u,g.v);
        if(depth[x]<depth[y]) swap(x,y),swap(f,g);
        if(query(x,g.v)==x||query(x,g.u)==x) return true;
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
    fu.create();
    for(int i=1;i<=q;i++)
    {
        qwq f={read(),read()},g={read(),read()};
        if(fu.dis(f,g)) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}