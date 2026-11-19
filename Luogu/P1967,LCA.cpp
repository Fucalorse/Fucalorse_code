#include <bits/stdc++.h>
using namespace std;

const int MAX=1e4+90,LEN=14,inf=2e9;

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
    int u,v,val;
    bool operator<(const ovo &a)const { return val>a.val; }
};
vector<ovo>edge;

struct qwq
{
    int nxt,minn;
    qwq(int k=0,int val=inf):nxt(k),minn(val){}
}f[MAX][LEN+2];

int n,m,q;
int depth[MAX];
vector<pair<int,int>>p[MAX];

struct peach
{
    private:
        int fa[MAX];
    public:
        peach()
        {
            for(int i=0;i<MAX;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x])
                fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
}op;

struct fucalorse
{
    void dfs(int ch,int fa)
    {
        depth[ch]=depth[fa]+1;
        for(auto &i:p[ch])
        {
            int &to=i.first,&val=i.second;
            if(to==fa) continue;
            f[to][0]=qwq(ch,val);
            dfs(to,ch);
        }
    }
    void create()
    {
        for(int i=1;i<=n;i++)
        {
            if(f[i][0].nxt) continue;
            dfs(i,0);
        }
        for(int k=1;(1<<k)<=n;k++)
            for(int i=1;i<=n;i++)
            {
                f[i][k].nxt=f[f[i][k-1].nxt][k-1].nxt;
                f[i][k].minn=min(f[i][k-1].minn,f[f[i][k-1].nxt][k-1].minn);
            }
    }
    int query(int u,int v)
    {
        if(op.find(u)!=op.find(v)) return -1;
        int ans=inf;
        if(depth[u]<depth[v]) swap(u,v);
        int d=depth[u]-depth[v];
        for(int k=LEN;k>=0;k--)
            if((d>>k)&1)
            {
                ans=min(ans,f[u][k].minn);
                u=f[u][k].nxt;
            }
        if(u==v) return ans;
        for(int k=LEN;k>=0;k--)
            if(f[u][k].nxt!=f[v][k].nxt)
            {
                ans=min(ans,min(f[u][k].minn,f[v][k].minn));
                u=f[u][k].nxt,v=f[v][k].nxt;
            }
        return min(ans,min(f[u][0].minn,f[v][0].minn));
    }
}fu;

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        edge.push_back({u,v,val});
    }
    sort(edge.begin(),edge.end());
    for(auto &i:edge)
    {
        if(op.find(i.u)==op.find(i.v)) continue;
        p[i.u].push_back({i.v,i.val});
        p[i.v].push_back({i.u,i.val});
        op.combine(i.u,i.v);
    }
    fu.create();
    q=read();
    while(q--)
    {
        int st=read(),ed=read();
        printf("%d\n",fu.query(st,ed));
    }   
    return 0;
}