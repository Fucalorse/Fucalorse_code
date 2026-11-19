#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int n,m,root;
int sz[MAX],dfa[MAX],maxn[MAX];
bool vis[MAX];
vector<int>p[MAX];

struct peach
{
    private:
        struct tree
        {
            int l,r;
            LL lazy;
        }op[MAX<<6];
        int root[MAX],qwq=0;

        void dfs(int &pos,int l,int r,const int &st,const int &ed,const int &k)
        {
            if(!pos) pos=++qwq;
            if(st<=l&&r<=ed)
            {
                op[pos].lazy+=k;
                return;
            }
            int mid=(l+r)>>1;
            if(st<=mid) dfs(op[pos].l,l,mid,st,ed,k);
            if(mid<ed) dfs(op[pos].r,mid+1,r,st,ed,k);
        }
        LL query(int pos,int l,int r,const int &x)
        {
            if(!pos) return 0;
            if(l==r) return op[pos].lazy;
            int mid=(l+r)>>1;
            if(x<=mid) return op[pos].lazy+query(op[pos].l,l,mid,x);
            else return op[pos].lazy+query(op[pos].r,mid+1,r,x);
        }
    public:
        void update(const int &pos,const int &st,const int &ed,const int &k)
        {
            dfs(root[pos],0,n-1,st,ed,k);
        }
        LL get(const int &pos,const int &x)
        {
            return query(root[pos],0,n-1,x);
        }
}f,g;

struct fucalorse
{
    private:
        int depth[MAX],f[MAX],top[MAX],son[MAX],sz[MAX],qwq=0;
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

void update(int x,int d,int k)
{
    int cur=x,pre=0;
    while(cur)
    {
        int dist=fu.get_dis(x,cur);
        if(dist<=d)
        {
            f.update(cur,0,d-dist,k);
            if(pre) g.update(pre,0,d-dist,k);
        }
        pre=cur;
        cur=dfa[cur];
    }
}

LL query(int x)
{
    int cur=x,pre=0;
    LL ans=0;
    while(cur)
    {
        int dist=fu.get_dis(x,cur);
        // printf("%d %d\n",x,cur);
        ans+=f.get(cur,dist);
        if(pre) ans-=g.get(pre,dist);
        pre=cur;
        cur=dfa[cur];
        // printf("%d %d\n",cur,dfa[cur]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fu.dfs(1,0),fu.find(1,1);
    get_root(1,0,n),get_cent(root,n);
    // for(int i=1;i<=n;i++)
    //     cout<<dfa[i]<<' ';
    // cout<<endl;
    while(m--)
    {
        char c;
        int x;
        cin>>c>>x;
        if(c=='Q') cout<<query(x)<<endl;
        else
        {
            int d,k;
            cin>>d>>k;
            update(x,d,k);
        }
        // for(int i=1;i<=n;i++)
        //     cout<<f.get(i,0,n-1)<<endl;
    }
    return 0;
}