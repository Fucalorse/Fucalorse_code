#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,LEN=30;

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
int pre[MAX],num[MAX];
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX],id[MAX],cnt=0;
vector<int>p[MAX];

struct furina
{
    private:
        struct qwq
        {
            qwq *op[2];
            int cnt;
            qwq() { op[0]=op[1]=nullptr,cnt=0; }
        };
        vector<qwq*>ver;
        qwq *clone(qwq *node)
        {
            qwq *now=new qwq;
            if(node)
            {
                now->op[0]=node->op[0];
                now->op[1]=node->op[1];
                now->cnt=node->cnt;
            }
            return now;
        }
    public:
        furina() { ver.push_back(new qwq); }
        void update(const int &x)
        {
            qwq *now=clone(ver.back()),*pre=ver.back();
            ver.push_back(now);
            for(int i=LEN;i>=0;i--)
            {
                int p=(x>>i)&1;
                qwq *old=pre?pre->op[p]:nullptr;
                qwq *aft=clone(old);
                now->op[p]=aft;
                aft->cnt++;
                now=aft;
                if(pre) pre=pre->op[p];
            }
        }
        int query(const int &st,const int &ed,const int &x)
        {
            qwq *l=ver[st],*r=ver[ed];
            int ans=0;
            for(int i=LEN;i>=0;i--)
            {
                int p=(x>>i)&1,aft=p;
                int numl=l&&l->op[p^1]?l->op[p^1]->cnt:0;
                int numr=r&&r->op[p^1]?r->op[p^1]->cnt:0;
                if(numr-numl>0)
                {
                    ans|=1<<i;
                    aft=p^1;
                }
                if(l) l=l->op[aft];
                if(r) r=r->op[aft];
            }
            return ans;
        }
}op;

struct fucalorse
{
    void debut()
    {
        for(int i=1;i<=n;i++)
            op.update(num[i]);
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
    int query_tree(int x,const int &k) { return op.query(id[x]-1,id[x]+path[x]-1,k); }
    int query_path(int u,int v,const int &k)
    {
        int ans=k^pre[u];
        while(top[u]!=top[v])
        {
            if(depth[top[u]]<depth[top[v]]) swap(u,v);
            ans=max(ans,op.query(id[top[u]]-1,id[u],k));
            u=f[top[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        return max(ans,op.query(id[u]-1,id[v],k));
    }
}fu;

int main()
{
    n=read(),q=read();
    for(int i=1;i<=n;i++)
        pre[i]=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v),p[v].push_back(u);
    }
    fu.dfs(1,0);
    fu.find(1,1);
    fu.debut();
    while(q--)
    {
        int p=read();
        if(p==1)
        {
            int x=read(),k=read();
            printf("%d\n",fu.query_tree(x,k));
        }
        else
        {
            int u=read(),v=read(),k=read();
            printf("%d\n",fu.query_path(u,v,k));
        }
    }
    return 0;
}