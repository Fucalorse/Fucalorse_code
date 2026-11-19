#include <bits/stdc++.h>
using namespace std;

#define LL long long
typedef pair<int,int> qwq;

const int MAX=1e5+90,LEN=17,inf=2e9;

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
    bool operator<(const ovo &a)const { return val<a.val; }
};
vector<ovo>edge;

struct ui
{
    int nxt,maxa,maxb;
    ui(int k=0,int a=-inf,int b=-inf):nxt(k),maxa(a),maxb(b){}
}f[MAX][LEN+2];

int n,m;
int depth[MAX];
bool vis[MAX<<4];
vector<qwq>p[MAX];

struct furina
{
    private:
        int fa[MAX];
    public:
        furina()
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
            f[to][0]=ui(ch,val,-inf);
            dfs(to,ch);
        }
    }
    void create()
    {
        dfs(1,0);
        for(int k=1;(1<<k)<=n;k++)
            for(int i=1;i<=n;i++)
            {
                int to=f[i][k-1].nxt;
                f[i][k].nxt=f[to][k-1].nxt;
                f[i][k].maxa=max(f[i][k-1].maxa,f[to][k-1].maxa);
                int now=max(f[i][k-1].maxb,f[to][k-1].maxb);
                if(f[i][k-1].maxa!=f[to][k-1].maxa)
                    f[i][k].maxb=min(f[i][k-1].maxa,f[to][k-1].maxa);
                f[i][k].maxb=max(f[i][k].maxb,now);
            }
    }
    void merge(qwq &ans,int maxa,int maxb)
    {
        if(maxa>ans.first)
        {
            ans.second=max(ans.first,maxb);
            ans.first=maxa;
        }
        else if(maxa<ans.first) ans.second=max(ans.second,maxa);
        ans.second=max(ans.second,maxb);
    }
    qwq query(int u,int v)
    {
        if(depth[u]<depth[v]) swap(u,v);
        int d=depth[u]-depth[v];
        qwq ans={-inf,-inf};
        for(int k=LEN;k>=0;k--)
            if((d>>k)&1)
            {
                merge(ans,f[u][k].maxa,f[u][k].maxb);
                u=f[u][k].nxt;
            }
        if(u==v) return ans;
        for(int k=LEN;k>=0;k--)
            if(f[u][k].nxt!=f[v][k].nxt)
            {
                merge(ans,f[u][k].maxa,f[u][k].maxb);
                merge(ans,f[v][k].maxa,f[v][k].maxb);
                u=f[u][k].nxt,v=f[v][k].nxt;
            }
        merge(ans,f[u][0].maxa,f[u][0].maxb);
        merge(ans,f[v][0].maxa,f[v][0].maxb);
        return ans;
    }
}fu;

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        if(u==v) continue;
        edge.push_back({u,v,val});
    }
    sort(edge.begin(),edge.end());
    LL total=0;
    for(size_t pos=0;pos<edge.size();pos++)
    {
        auto &i=edge[pos];
        if(op.find(i.u)==op.find(i.v)) continue;
        vis[pos]=true;
        total+=i.val;
        op.combine(i.u,i.v);
        p[i.u].push_back({i.v,i.val});
        p[i.v].push_back({i.u,i.val});
    }
    fu.create();
    LL ans=inf;
    for(size_t pos=0;pos<edge.size();pos++)
    {
        if(vis[pos]) continue;
        auto &i=edge[pos];
        auto now=fu.query(i.u,i.v);
        if(i.val!=now.first) ans=min(ans,(LL)i.val-now.first);
        else if(now.second!=-inf) ans=min(ans,(LL)i.val-now.second);
    }
    printf("%lld\n",total+ans);
    return 0;
}