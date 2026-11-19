#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5e5+90;

int n,q;
int f[MAX],depth[MAX],sz[MAX],son[MAX],top[MAX],id[MAX],seq[MAX],tot=0;
LL pre[MAX],num[MAX],sum[MAX],g[MAX],path[MAX],gg[MAX];
vector<int>p[MAX];

struct peach1
{
    private:
        struct qwq
        {
            LL sum,lazy;
            int cnt;
        }op[MAX<<2];

        void add(int l,int r,int id,LL k,int cnt)
        {
            op[id].sum+=(r-l+1)*k+(gg[r]-gg[l-1])*cnt;
            // cout<<op[id].sum<<' ';
            // cout<<l<<' '<<r<<"::  "<<' ';
            op[id].lazy+=k;
            op[id].cnt+=cnt;
        }
        void down(int l,int r,int id)
        {
            if(op[id].cnt||op[id].lazy)
            {
                int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
                add(l,mid,hl,op[id].lazy,op[id].cnt);
                add(mid+1,r,hr,op[id].lazy,op[id].cnt);
                op[id].cnt=op[id].lazy=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const LL &k,const int &cnt)
        {
            if(st<=l&&r<=ed)
            {
                add(l,r,id,k,cnt);
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k,cnt);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k,cnt);
            op[id].sum=op[hl].sum+op[hr].sum;
        }
        LL query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].sum;
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }
    public:
        void update(int st,int ed,LL k,int cnt) { dfs(1,n,1,st,ed,k,cnt); }
        LL get(int st,int ed) { return query(1,n,1,st,ed); }
}fu1;

struct peach2
{
    private:
        struct qwq
        {
            LL sum_path,sum_wp;
            int cnt_path,cnt_wp;
            qwq operator+(const qwq &a) { return {sum_path+a.sum_path,sum_wp+a.sum_wp,0,0}; }
        }op[MAX<<2];

        void add(int l,int r,int id)
        {
            op[id].sum_path+=(g[r]-g[l-1])*2,op[id].cnt_path++;
            op[id].sum_wp+=(sum[r]-sum[l-1])*2,op[id].cnt_wp++;
        }
        void down(int l,int r,int id)
        {
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(op[id].cnt_path)
            {
                op[hl].sum_path+=(g[mid]-g[l-1])*op[id].cnt_path*2,op[hl].cnt_path+=op[id].cnt_path;
                op[hr].sum_path+=(g[r]-g[mid])*op[id].cnt_path*2,op[hr].cnt_path+=op[id].cnt_path;
                op[id].cnt_path=0;
            }
            if(op[id].cnt_wp)
            {
                op[hl].sum_wp+=(sum[mid]-sum[l-1])*op[id].cnt_wp*2,op[hl].cnt_wp+=op[id].cnt_wp;
                op[hr].sum_wp+=(sum[r]-sum[mid])*op[id].cnt_wp*2,op[hr].cnt_wp+=op[id].cnt_wp;
                op[id].cnt_wp=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed)
            {
                add(l,r,id);
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed);
            if(mid<ed) dfs(mid+1,r,hr,st,ed);
            op[id].sum_path=op[hl].sum_path+op[hr].sum_path;
            op[id].sum_wp=op[hl].sum_wp+op[hr].sum_wp;
        }
        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return {0,0,0,0};
            if(st<=l&&r<=ed) return op[id];
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }
    public:
        void update(int st,int ed)
        {
            if(st>ed) return;
            dfs(1,n,1,st,ed);
        }
        pair<LL,LL> get(int st,int ed)
        {
            if(st>ed) return {0,0};
            qwq now=query(1,n,1,st,ed);
            return {now.sum_path,now.sum_wp};
        }
}fu2;

struct fucalorse
{
    int dfs(int ch,int fa)
    {
        f[ch]=fa;
        depth[ch]=depth[fa]+1;
        sz[ch]=1;
        path[ch]=path[fa]+pre[ch];
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
        id[pos]=++tot;
        seq[tot]=pos;
        num[tot]=pre[pos];
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto &to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
    int LCA(int u,int v)
    {
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            u=f[top[u]];
        }
        return depth[u]<depth[v]?u:v;
    }
    //fu1->di+dy-2*dx,,,-wp
    //fu2->path_sum
    void update(int x,int y)
    {
        int lca=LCA(x,y);
        if(lca==x)
        {
            fu1.update(id[x],id[x]+sz[x]-1,path[y]-2*path[x],1);
            int u=x,v=y;
            while(top[u]!=top[v])
            {
                if(depth[top[u]]<depth[top[v]]) swap(u,v);
                fu2.update(id[top[u]],id[u]);
                u=f[top[u]];
            }
            if(depth[u]>depth[v]) swap(u,v);
            fu2.update(id[u]+1,id[v]);
        }
        else fu1.update(id[x],id[x]+sz[x]-1,path[y]-2*path[lca],1);
    }
    //first->sum_path
    //second->sum_wp
    LL query_path(int u,int v)
    {
        LL ans=0;
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans+=fu2.get(id[top[u]],id[u]).first;
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return ans+fu2.get(id[u]+1,id[v]).first;
    }
    LL query(int x)
    {
        LL a=fu2.get(id[x]+1,id[x]+sz[x]-1).second,b=query_path(1,x);
        LL ans=fu1.get(id[x],id[x]+sz[x]-1);
        ans-=a+b*sz[x];
        return ans;
    }
}fufu;

void solve()
{
    cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        int fa;
        LL val;
        cin>>fa>>val;
        p[fa].push_back(i);
        pre[i]=val;
    }
    fufu.dfs(1,0);
    fufu.find(1,1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+num[i]*sz[seq[i]];
        g[i]=g[i-1]+num[i];
        gg[i]=gg[i-1]+path[seq[i]];
    }
    while(q--)
    {
        int ops;
        cin>>ops;
        if(ops==1)
        {
            int x,y;
            cin>>x>>y;
            fufu.update(x,y);
        }
        else
        {
            int x;
            cin>>x;
            cout<<fufu.query(x)<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}