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

struct edge
{
    int next,to,val;
}op[MAX<<1];

int head[MAX],cnt=1;
void add(int from,int to,int n)
{
    op[cnt].to=to;
    op[cnt].next=head[from];
    op[cnt].val=n;
    head[from]=cnt;
    cnt++;
}

int n,q,st,ed;
int pre[MAX],num[MAX],qwq=0,max_path=0;
int f[MAX],depth[MAX],path[MAX],son[MAX],id[MAX],top[MAX];

struct furina1
{
    private:
        int op[MAX];
        inline int lowbit(int pos) { return pos&-pos; }
        inline int query(int pos)
        {
            int ans=0;
            while(pos)
            {
                ans+=op[pos];
                pos-=lowbit(pos);
            }
            return ans;
        }
    public:
        inline void update(int pos,const int &k)
        {
            while(pos<=n)
            {
                op[pos]+=k;
                pos+=lowbit(pos);
            }
        }
        inline int get(const int &l,const int &r) { return query(r)-query(l-1); }
};

struct furina2
{
    private:
        struct tree
        {
            int maxn,lazy;
        }op[MAX<<2];
        inline void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;
                op[hl].maxn=max(op[hl].maxn,op[id].lazy);
                op[hl].lazy=max(op[hl].lazy,op[id].lazy);
                op[hr].maxn=max(op[hr].maxn,op[id].lazy);
                op[hr].lazy=max(op[hr].lazy,op[id].lazy);
                op[id].lazy=0;
            }
        }
        inline void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].maxn=max(op[id].maxn,k);
                op[id].lazy=max(op[id].lazy,k);
                return;
            }
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id].maxn=max(op[hl].maxn,op[hr].maxn);
        }
        inline int query(int l,int r,int id,const int &x)
        {
            if(l==r) return op[id].maxn;
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) return query(l,mid,hl,x);
            else return query(mid+1,r,hr,x);
        }
    public:
        inline void update(const int &st,const int &ed,const int &k)
        {
            dfs(1,n,1,st,ed,k);
        }
        inline int get(const int &x) { return query(1,n,1,x); }
};

int c[MAX],d[MAX],idx[MAX];
bool cmp(const int &a,const int &b) { return c[a]<c[b]; }
struct fucalorse
{
    private:
        furina1 bit;furina2 fu;
    public:
        inline void debut()
        {
            for(int i=1;i<=n;i++)
                bit.update(i,num[i]);
        }
        inline int dfs(int ch,int fa)
        {
            f[ch]=fa;
            depth[ch]=depth[fa]+1;
            path[ch]=1;
            int maxn=-1;
            for(int i=head[ch];i;i=op[i].next)
            {
                int &to=op[i].to;
                if(to==fa) continue;
                pre[to]=op[i].val;
                path[ch]+=dfs(to,ch);
                if(path[to]>maxn) maxn=to,son[ch]=to;
            }
            return path[ch];
        }
        inline void find(int pos,int dfn)
        {
            id[pos]=++qwq;
            num[qwq]=pre[pos];
            top[pos]=dfn;
            if(!son[pos]) return;
            find(son[pos],dfn);
            for(int i=head[pos];i;i=op[i].next)
            {
                int &to=op[i].to;
                if(to==f[pos]||to==son[pos]) continue;
                find(to,to);
            }
        }
        inline void update(int u,int v)
        {
            int uu=u,vv=v;
            int total=0,len=0;
            while(top[u]!=top[v])
            {
                if(depth[top[u]]<depth[top[v]]) swap(u,v);
                total+=bit.get(id[top[u]],id[u]);
                c[++len]=id[top[u]],d[len]=id[u];
                u=f[top[u]];
            }
            if(depth[u]>depth[v]) swap(u,v);
            total+=bit.get(id[u]+1,id[v]);
            c[++len]=id[u]+1,d[len]=id[v];
            for(int i=1;i<=len;i++) 
                idx[i]=i;
            sort(idx+1,idx+len+1,cmp);
            if(c[idx[1]]>1) fu.update(1,c[idx[1]]-1,total);
            if(d[idx[len]]<n) fu.update(d[idx[len]]+1,n,total);
            for(int i=1;i<len;i++)
                fu.update(d[idx[i]]+1,c[idx[i+1]]-1,total);
            if(total>max_path) max_path=total,st=uu,ed=vv;
        }
        inline int query(int u,int v)
        {
            if(u==v) return 0;
            int ans=2e9;
            if(depth[u]<depth[v]) swap(u,v);
            while(depth[u]!=depth[v])
            {
                ans=min(ans,max(max_path-pre[u],fu.get(id[u])));
                u=f[u];
            }
            while(u!=v)
            {
                if(depth[u]<depth[v]) swap(u,v);
                ans=min(ans,max(max_path-pre[u],fu.get(id[u])));
                u=f[u];
            }
            return ans;
        }
}fu;

int main()
{
    n=read(),q=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read(),val=read();
        add(u,v,val),add(v,u,val);
    }
    fu.dfs(1,0);
    fu.find(1,1);
    fu.debut();
    for(int i=1;i<=q;i++)
    {
        int u=read(),v=read();
        fu.update(u,v);
    }
    // printf("%d\n",fu.query(st,ed));
    return 0;
}