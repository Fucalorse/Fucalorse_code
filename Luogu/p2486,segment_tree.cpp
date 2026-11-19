#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,inf=2e9;

struct qwq
{
    int col,cnt;
    int fl,fr;
}op[MAX<<2];

int n,m;
int pre[MAX],num[MAX];
int f[MAX],depth[MAX],sz[MAX],son[MAX],top[MAX],id[MAX],tot=0;
vector<int>p[MAX];

struct peach
{
    private:
        qwq merge(const qwq &a,const qwq &b)
        {
            if(a.col==inf) return b;
            if(b.col==inf) return a;
            int cnt=a.cnt+b.cnt,col=a.col==b.col?a.col:-1;
            if(a.fr==b.fl) --cnt;
            return {col,cnt,a.fl,b.fr};
        }
        void down(int id)
        {
            if(op[id].col!=-1)
            {
                int hl=id<<1,hr=id<<1|1;
                op[hl]={op[id].col,1,op[id].col,op[id].col};
                op[hr]={op[id].col,1,op[id].col,op[id].col};
            }
        }
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id]={num[l],1,num[l],num[l]};
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=merge(op[hl],op[hr]);
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id]={k,1,k,k};
                return;
            }
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id]=merge(op[hl],op[hr]);
        }
        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return {inf,inf,inf,inf};
            if(st<=l&&r<=ed) return op[id];
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return merge(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void debut() { create(1,n,1); }
        void update(int st,int ed,int k) { dfs(1,n,1,st,ed,k); }
        qwq get(int st,int ed) { return query(1,n,1,st,ed); }
        qwq cal(const qwq &a,const qwq &b) { return merge(a,b); }
}fu;

struct fucalorse
{
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
        id[pos]=++tot;
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
    void update(int u,int v,int k)
    {
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            fu.update(id[top[u]],id[u],k);
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        fu.update(id[u],id[v],k);
    }
    int query(int u,int v)
    {
        qwq l={inf,inf,inf,inf},r={inf,inf,inf,inf};
        while(top[u]!=top[v])
        {
            if(depth[top[u]]>depth[top[v]])
            {
                qwq now=fu.get(id[top[u]],id[u]);
                l=fu.cal(now,l);
                u=f[top[u]];
            }
            else
            {
                qwq now=fu.get(id[top[v]],id[v]);
                r=fu.cal(now,r);
                v=f[top[v]];
            }
        }
        if(depth[u]>depth[v])
        {
            qwq now=fu.get(id[v],id[u]);
            l=fu.cal(now,l);
        }
        else
        {
            qwq now=fu.get(id[u],id[v]);
            r=fu.cal(now,r);
        }
        swap(l.fl,l.fr);
        return fu.cal(l,r).cnt;
    }
}fufu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>pre[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fufu.dfs(1,0);
    fufu.find(1,1);
    fu.debut();
    // for(int i=1;i<=n;i++)
    //     cout<<f[i]<<' ';
    // cout<<endl;
    while(m--)
    {
        char c;
        int u,v;
        cin>>c>>u>>v;
        if(c=='C')
        {
            int k;
            cin>>k;
            fufu.update(u,v,k);
        }
        else cout<<fufu.query(u,v)<<endl;
    }
    return 0;
}