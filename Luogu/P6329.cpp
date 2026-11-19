#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int n,m,root;
int num[MAX],sz[MAX],maxn[MAX],dfa[MAX];
bool vis[MAX];
vector<int>p[MAX];

struct peach
{
    private:
        struct tree
        {
            int l,r,sum;
        }op[MAX<<5];
        int root[MAX],qwq=0;

        void dfs(int &pos,int l,int r,const int &x,const int &k)
        {
            if(!pos) pos=++qwq;
            if(l==r)
            {
                op[pos].sum+=k;
                // cout<<op[pos].sum<<endl;
                return;
            }
            int mid=(l+r)>>1;
            if(x<=mid) dfs(op[pos].l,l,mid,x,k);
            else dfs(op[pos].r,mid+1,r,x,k);
            op[pos].sum=op[op[pos].l].sum+op[op[pos].r].sum;
        }
        int query(int pos,int l,int r,const int &st,const int &ed)
        {
            if(!pos||r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[pos].sum;
            int mid=(l+r)>>1;
            return query(op[pos].l,l,mid,st,ed)+query(op[pos].r,mid+1,r,st,ed);
        }
    public:
        void update(const int &pos,const int &x,const int &k)
        {
            dfs(root[pos],0,n-1,x,k);
        }
        int get(const int &pos,const int &st,const int &ed)
        {
            return query(root[pos],0,n-1,st,ed);
        }
}f,g;

struct fucalorse
{
    private:
        int f[MAX],depth[MAX],sz[MAX],son[MAX],top[MAX],qwq=0;
    public:
        int dfs(int ch,int fa)
        {
            f[ch]=fa;
            depth[ch]=depth[fa]+1;
            sz[ch]=1;
            int maxn=-1;
            for(auto &to:p[ch])
            {
                if(to==fa) continue;
                sz[ch]+=dfs(to,ch);
                if(sz[to]>maxn) maxn=sz[to],son[ch]=to;
            }
            return sz[ch];
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
        int get_dis(int u,int v) { return depth[u]+depth[v]-2*depth[query(u,v)]; }
}fu;

void get_root(int ch,int fa,const int &total)
{
    sz[ch]=1;
    maxn[ch]=0;
    for(auto &to:p[ch])
    {
        if(to==fa||vis[to]) continue;
        get_root(to,ch,total);
        sz[ch]+=sz[to];
        maxn[ch]=max(maxn[ch],sz[to]);
    }
    maxn[ch]=max(maxn[ch],total-sz[ch]);
    if(!root||maxn[ch]<maxn[root]) root=ch;
}

void get_cent(int pos,int total)
{
    vis[pos]=true;
    for(auto &to:p[pos])
    {
        if(vis[to]) continue;
        root=0;
        int now=sz[to]<sz[pos]?sz[to]:total-sz[pos];
        get_root(to,pos,now);
        dfa[root]=pos;
        get_cent(root,now);
    }
}

void update(int x,const int &k)
{
    int cur=x;
    while(cur)
    {
        f.update(cur,fu.get_dis(x,cur),k);
        if(dfa[cur]) g.update(cur,fu.get_dis(x,dfa[cur]),k);
        cur=dfa[cur];
    }
}

int query(int x,int k)
{
    int cur=x,pre=0,ans=0;
    while(cur)
    {
        int dist=fu.get_dis(x,cur);
        if(dist>k)
        {
            pre=cur;
            cur=dfa[cur];
            continue;
        }
        ans+=f.get(cur,0,k-dist);
        if(pre) ans-=g.get(pre,0,k-dist);
        pre=cur;
        cur=dfa[cur];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fu.dfs(1,0);
    fu.find(1,1);
    maxn[0]=n+10;
    get_root(1,0,n);
    get_cent(root,n);
    for(int i=1;i<=n;i++)
        update(i,num[i]);
    int pre=0;
    while(m--)
    {
        int p,x,k;
        cin>>p>>x>>k;
        x^=pre,k^=pre;
        if(!p)
        {
            pre=query(x,k);
            cout<<pre<<endl;
        }
        else update(x,k-num[x]),num[x]=k;
    }
    return 0;
}