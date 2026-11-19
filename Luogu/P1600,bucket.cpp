#include <bits/stdc++.h>
using namespace std;

const int MAX=3e5+90;

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

int n,m;
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX],qwq=0;
int st[MAX<<2],ed[MAX<<2],h[MAX],t[MAX],dist[MAX],w[MAX],cnt[MAX],ans[MAX];
vector<int>p[MAX],pst[MAX],ped[MAX];

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
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto &to:p[pos])
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
    void cal(int pos)
    {
        int num1=st[w[pos]+depth[pos]],num2=ed[w[pos]-depth[pos]+MAX];
        for(auto &to:p[pos])
        {
            if(to==f[pos]) continue;
            cal(to);
        }
        st[depth[pos]]+=cnt[pos];
        for(auto &i:pst[pos])
            ed[dist[i]-depth[t[i]]+MAX]++;
        ans[pos]+=st[depth[pos]+w[pos]]-num1+ed[w[pos]-depth[pos]+MAX]-num2;
        for(auto &i:ped[pos])
        {
            st[depth[h[i]]]--;
            ed[dist[i]-depth[t[i]]+MAX]--;
        }
    }
}fu;

int main()
{
    n=read(),m=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        w[i]=read();
    fu.dfs(1,0);
    fu.find(1,1);
    for(int i=1;i<=m;i++)
    {
        h[i]=read(),t[i]=read();
        int fa=fu.query(h[i],t[i]);
        dist[i]=depth[h[i]]+depth[t[i]]-2*depth[fa];
        cnt[h[i]]++;
        pst[t[i]].push_back(i);
        ped[fa].push_back(i);
        if(depth[fa]+w[fa]==depth[h[i]]) ans[fa]--;
    }
    fu.cal(1);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}