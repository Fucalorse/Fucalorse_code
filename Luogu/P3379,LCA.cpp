#include <bits/stdc++.h>
using namespace std;

const int MAX=5e5+90,LEN=20;

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

int n,q,st;
int depth[MAX],f[MAX][LEN+2];
vector<int>p[MAX];

struct fucalorse
{
    void dfs(int ch,int fa)
    {
        depth[ch]=depth[fa]+1;
        f[ch][0]=fa;
        for(auto i:p[ch])
            if(i!=fa) dfs(i,ch);
    }
    void create()
    {
        dfs(st,0);
        for(int k=1;k<=LEN;k++)
            for(int i=1;i<=n;i++)
                f[i][k]=f[f[i][k-1]][k-1];
    }
    int query(int u,int v)
    {
        if(depth[u]<depth[v]) swap(u,v);
        int d=depth[u]-depth[v];
        for(int i=0;i<=LEN;i++)
            if((d>>i)&1) u=f[u][i];
        if(u==v) return u;
        for(int i=LEN;i>=0;i--)
            if(f[u][i]!=f[v][i])
            {
                u=f[u][i];
                v=f[v][i];
            }
        return f[u][0];
    }
}fu;

int main()
{
    n=read(),q=read(),st=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fu.create();
    while(q--)
    {
        int u=read(),v=read();
        printf("%d\n",fu.query(u,v));
    }
    return 0;
}