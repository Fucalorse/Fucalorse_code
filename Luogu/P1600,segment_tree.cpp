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

struct ovo
{
    int l,r;
    int sum;
}op[MAX<<5];
int root[MAX][2],qwq=0;

int n,m;
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX];
int h[MAX],t[MAX],w[MAX],ans[MAX];
vector<int>p[MAX];

struct peach
{
    void dfs(int &pos,int l,int r,const int &x,const int &k)
    {
        if(!pos) pos=++qwq;
        op[pos].sum+=k;
        if(l==r) return;
        int mid=(l+r)>>1;
        if(x<=mid) dfs(op[pos].l,l,mid,x,k);
        else dfs(op[pos].r,mid+1,r,x,k);
    }
    int query(int pos,int l,int r,const int &x)
    {
        if(!pos||x<l||x>r) return 0;
        if(l==r) return op[pos].sum;
        int mid=(l+r)>>1;
        if(x<=mid) return query(op[pos].l,l,mid,x);
        else return query(op[pos].r,mid+1,r,x);
    }
    int merge(int x,int y,int l,int r)
    {
        if(!x||!y) return x|y;
        if(l==r)
        {
            op[x].sum+=op[y].sum;
            return x;
        }
        int mid=(l+r)>>1;
        op[x].l=merge(op[x].l,op[y].l,l,mid);
        op[x].r=merge(op[x].r,op[y].r,mid+1,r);
        op[x].sum=op[op[x].l].sum+op[op[x].r].sum;
        return x;
    }
}fu;

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
        for(auto &to:p[pos])
        {
            if(to==f[pos]) continue;
            cal(to);
            root[pos][0]=fu.merge(root[pos][0],root[to][0],1,n);
            root[pos][1]=fu.merge(root[pos][1],root[to][1],-n,2*n);
        }
        ans[pos]=fu.query(root[pos][0],1,n,w[pos]+depth[pos]);
        ans[pos]+=fu.query(root[pos][1],-n,2*n,depth[pos]-w[pos]);
    }
}fufu;

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
    fufu.dfs(1,0);
    fufu.find(1,1);
    for(int i=1;i<=m;i++)
    {
        h[i]=read(),t[i]=read();
        int fa=fufu.query(h[i],t[i]);
        fu.dfs(root[h[i]][0],1,n,depth[h[i]],1);
        fu.dfs(root[f[fa]][0],1,n,depth[h[i]],-1);
        fu.dfs(root[t[i]][1],-n,2*n,2*depth[fa]-depth[h[i]],1);
        fu.dfs(root[fa][1],-n,2*n,2*depth[fa]-depth[h[i]],-1);
    }
    fufu.cal(1);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}