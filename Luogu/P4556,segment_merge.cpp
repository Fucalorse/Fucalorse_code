#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,LEN=1e5;

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
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX];
int h[MAX],t[MAX],w[MAX],ans[MAX];
vector<int>p[MAX];

struct peach
{
    private:
        struct tree
        {
            int l,r;
            int sum,maxn,col;
        }op[MAX<<7];
        int root[MAX],qwq;

        void up(const int &pos)
        {
            int hl=op[pos].l,hr=op[pos].r;
            op[pos].sum=op[hl].sum+op[hr].sum;
            if(!op[hl].maxn&&!op[hr].maxn)
            {
                op[pos].col=0;
                op[pos].maxn=0;
                return;
            }
            if(op[hl].maxn>=op[hr].maxn)
            {
                op[pos].maxn=op[hl].maxn;
                op[pos].col=op[hl].col;
            }
            else
            {
                op[pos].maxn=op[hr].maxn;
                op[pos].col=op[hr].col;
            }           
        }
        void dfs(int &pos,int l,int r,const int &x,const int &k)
        {
            if(!pos) pos=++qwq;
            op[pos].sum+=k;
            if(l==r)
            {
                op[pos].maxn=op[pos].sum;
                op[pos].col=op[pos].sum?l:0;
                return;
            }
            int mid=(l+r)>>1;
            if(x<=mid) dfs(op[pos].l,l,mid,x,k);
            else dfs(op[pos].r,mid+1,r,x,k);
            up(pos);
        }
        int merge(int x,int y,int l,int r)
        {
            if(!x||!y) return x|y;
            if(l==r)
            {
                op[x].sum+=op[y].sum;
                op[x].maxn=op[x].sum;
                op[x].col=op[x].sum?l:0;
                // cout<<op[x].col<<endl;
                return x;
            }
            int mid=(l+r)>>1;
            op[x].l=merge(op[x].l,op[y].l,l,mid);
            op[x].r=merge(op[x].r,op[y].r,mid+1,r);
            up(x);
            return x;
        }
    public:
        void debut(const int &x,const int &y)
        {
            root[x]=merge(root[x],root[y],1,LEN);
        }
        void update(const int &pos,const int &x,const int &k)
        {
            dfs(root[pos],1,LEN,x,k);
        }
        int get(const int &pos)
        {
            int &x=root[pos];
            return op[x].maxn?op[x].col:0;
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
            fu.debut(pos,to);
        }
        ans[pos]=fu.get(pos);
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
    fufu.dfs(1,0);
    fufu.find(1,1);
    for(int i=1;i<=m;i++)
    {
        h[i]=read(),t[i]=read(),w[i]=read();
        int fa=fufu.query(h[i],t[i]);
        // printf("%d %d %d\n",h[i],t[i],fa);
        fu.update(h[i],w[i],1);
        fu.update(t[i],w[i],1);
        fu.update(fa,w[i],-1);
        if(f[fa]) fu.update(f[fa],w[i],-1);
    }
    fufu.cal(1);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}