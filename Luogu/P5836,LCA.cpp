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
    int nxt,p;
}f[MAX][LEN+2];

int n,q;
int depth[MAX],kind[MAX];
vector<int>p[MAX];

struct fucalorse
{
    void dfs(int ch,int fa)
    {
        depth[ch]=depth[fa]+1;
        f[ch][0]={fa,kind[fa]};
        for(auto to:p[ch])
            if(to!=fa) dfs(to,ch);
    }
    void create()
    {
        dfs(1,0);
        for(int k=1;(1<<k)<=n;k++)
            for(int i=1;i<=n;i++)
            {
                f[i][k].nxt=f[f[i][k-1].nxt][k-1].nxt;
                if(f[i][k-1].p!=f[f[i][k-1].nxt][k-1].p) f[i][k].p=-1;
                else f[i][k].p=f[i][k-1].p;
            }
    }
    int query(int u,int v)
    {
        if(depth[u]<depth[v]) swap(u,v);
        int d=depth[u]-depth[v],pu=kind[u],pv=kind[v];
        for(int k=0;k<=LEN;k++)
            if((d>>k)&1)
            {
                if(pu!=-1&&pu!=f[u][k].p) pu=-1;
                u=f[u][k].nxt;
            }
        if(u==v) return pu;
        for(int k=LEN;k>=0;k--)
            if(f[u][k].nxt!=f[v][k].nxt)
            {
                if(pu!=-1&&pu!=f[u][k].p) pu=-1;
                if(pv!=-1&&pv!=f[v][k].p) pv=-1;
                u=f[u][k].nxt;
                v=f[v][k].nxt;
            }
        if(pu!=-1&&pu!=f[u][0].p) pu=-1;
        if(pv!=-1&&pv!=f[v][0].p) pv=-1;
        return pu==pv?pu:-1;
    }
}fu;

int main()
{
    n=read(),q=read();
    for(int i=1;i<=n;i++)
    {
        char c;
        scanf(" %c",&c);
        if(c=='H') kind[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fu.create();
    string ans="";
    while(q--)
    {
        int u=read(),v=read(),p=0;
        char c;
        scanf(" %c",&c);
        if(c=='H') p=1;
        int now=fu.query(u,v);
        if(now==-1||now==p) ans+='1';
        else ans+='0';
    }
    cout<<ans<<'\n';
    return 0;
}