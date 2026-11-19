#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

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

int n,q;
int f[MAX],path[MAX],depth[MAX],son[MAX],id[MAX],top[MAX],num[MAX],qwq=0;
vector<int>p[MAX];

struct furina
{
    private:
        int op[MAX<<2];
        void dfs(int l,int r,int id,const int &x)
        {
            if(l==r)
            {
                op[id]=l;
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x);
            else dfs(mid+1,r,hr,x);
            op[id]=max(op[hl],op[hr]);
        }
        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return max(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void update(const int &x) { dfs(1,n,1,x); }
        int get(const int &st,const int &ed) { return query(1,n,1,st,ed); }
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
        num[qwq]=pos;
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto &to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    void update(const int &x) { op.update(id[x]); }
    int query(int x)
    {
        while(top[x])
        {
            int now=op.get(id[top[x]],id[x]);
            if(now) return num[now];
            x=f[top[x]];
        }
        return 1;
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
    fu.update(1);
    for(int i=1;i<=q;i++)
    {
        char c;
        scanf(" %c",&c);
        int x=read();
        if(c=='C') fu.update(x);
        else printf("%d\n",fu.query(x));
    }
    return 0;
}