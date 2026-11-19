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

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct qwq
{
    int dfn,val,sum,maxn,pri;
    qwq *l,*r;
    qwq(int id,int k):dfn(id),val(k),sum(k),maxn(k),
    pri(dist(rng)),l(nullptr),r(nullptr){}
};

struct tree
{
    void maintain(qwq *pos)
    {
        if(pos)
        {
            pos->maxn=pos->sum=pos->val;
            if(pos->l)
            {
                pos->sum+=pos->l->sum;
                pos->maxn=max(pos->maxn,pos->l->maxn);
            }
            if(pos->r)
            {
                pos->sum+=pos->r->sum;
                pos->maxn=max(pos->maxn,pos->r->maxn);
            }
        }
    }
    pair<qwq*,qwq*> split(qwq *pos,const int &k)
    {
        if(!pos) return {nullptr,nullptr};
        if(pos->dfn<=k)
        {
            auto p=split(pos->r,k);
            qwq *left=p.first,*right=p.second;
            pos->r=left;
            maintain(pos);
            return {pos,right};
        }
        else
        {
            auto p=split(pos->l,k);
            qwq *left=p.first,*right=p.second;
            pos->l=right;
            maintain(pos);
            return {left,pos};
        }
    }
    qwq *merge(qwq *left,qwq *right)
    {
        if(!left||!right) return left?left:right;
        if(left->pri>right->pri)
        {
            left->r=merge(left->r,right);
            maintain(left);
            return left;
        }
        else
        {
            right->l=merge(left,right->l);
            maintain(right);
            return right;
        }
    }
    qwq *insert(qwq *pos,qwq *node)
    {
        if(!pos) return node;
        if(node->pri>pos->pri)
        {
            auto p=split(pos,node->dfn);
            qwq *left=p.first,*right=p.second;
            node->l=left,node->r=right;
            maintain(node);
            return node;
        }
        if(node->dfn<pos->dfn) pos->l=insert(pos->l,node);
        else pos->r=insert(pos->r,node);
        maintain(pos);
        return pos;
    }
    qwq *remove(qwq *pos,const int &k)
    {
        if(!pos) return nullptr;
        if(pos->dfn==k)
        {
            qwq *res=merge(pos->l,pos->r);
            delete(pos);
            return res;
        }
        if(k<pos->dfn) pos->l=remove(pos->l,k);
        else pos->r=remove(pos->r,k);
        maintain(pos);
        return pos;
    }
    pair<int,int> get(qwq *root,const int &l,const int &r)
    {
        auto p=split(root,r);
        auto q=split(p.first,l-1);
        pair<int,int>ans={0,0};
        if(q.second) ans={q.second->maxn,q.second->sum};
        root=merge(q.first,q.second);
        root=merge(root,p.second);
        return ans;
    }
};

struct ui
{
    int w,c;
}pre[MAX],num[MAX];

int n,q;
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX],id[MAX],cnt;
vector<int>p[MAX];

struct fucalorse
{
    private:
        qwq *root[MAX];
        tree op;
    public:
        void debut()
        {
            for(int i=1;i<=n;i++)
                root[num[i].c]=op.insert(root[num[i].c],new qwq(i,num[i].w));
        }
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
            id[pos]=++cnt;
            num[cnt]=pre[pos];
            top[pos]=dfn;
            if(!son[pos]) return;
            find(son[pos],dfn);
            for(auto &to:p[pos])
            {
                if(to==f[pos]||to==son[pos]) continue;
                find(to,to);
            }
        }
        void update_cul(const int &x,const int &new_c)
        {
            int pos=num[id[x]].c;
            root[pos]=op.remove(root[pos],id[x]);
            root[new_c]=op.insert(root[new_c],new qwq(id[x],num[id[x]].w));
            num[id[x]].c=new_c;
        }
        void update_val(const int &x,const int &new_w)
        {
            int pos=num[id[x]].c;
            root[pos]=op.remove(root[pos],id[x]);
            root[pos]=op.insert(root[pos],new qwq(id[x],new_w));
            num[id[x]].w=new_w;
        }
        int maxn(const int &x,int u,int v)
        {
            int pos=num[id[x]].c,ans=0;
            while(top[u]!=top[v])
            {
                if(depth[top[u]]<depth[top[v]]) swap(u,v);
                ans=max(ans,op.get(root[pos],id[top[u]],id[u]).first);
                u=f[top[u]];
            }
            if(depth[u]>depth[v]) swap(u,v);
            return max(ans,op.get(root[pos],id[u],id[v]).first);
        }
        int sum(const int &x,int u,int v)
        {
            int pos=num[id[x]].c,ans=0;
            while(top[u]!=top[v])
            {
                if(depth[top[u]]<depth[top[v]]) swap(u,v);
                ans+=op.get(root[pos],id[top[u]],id[u]).second;
                u=f[top[u]];
            }
            if(depth[u]>depth[v]) swap(u,v);
            return ans+op.get(root[pos],id[u],id[v]).second;
        }
}fu;

int main()
{
    n=read(),q=read();
    for(int i=1;i<=n;i++)
        pre[i]={read(),read()};
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fu.dfs(1,0),fu.find(1,1);
    fu.debut();
    for(int i=1;i<=q;i++)
    {
        char s[5];
        scanf(" %s",s);
        if(s[1]=='C')
        {
            int x=read(),c=read();
            fu.update_cul(x,c);
        }
        else if(s[1]=='W')
        {
            int x=read(),w=read();
            fu.update_val(x,w);
        }
        else if(s[1]=='S')
        {
            int u=read(),v=read();
            printf("%d\n",fu.sum(u,u,v));
        }
        else
        {
            int u=read(),v=read();
            printf("%d\n",fu.maxn(u,u,v));
        }
    }
    return 0;  
}