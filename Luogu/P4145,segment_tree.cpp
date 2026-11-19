#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90;

LL read()
{
    LL ans=0,f=1;
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
struct fucalorse
{
    private:
        struct tree
        {
            LL maxn,sum;
        }op[MAX<<2];
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id].maxn=op[id].sum=read();
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id].maxn=max(op[hl].maxn,op[hr].maxn);
            op[id].sum=op[hl].sum+op[hr].sum;
        }
        void dfs(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed)
            {
                if(op[id].maxn==1) return;
                if(l==r)
                {
                    op[id].sum=op[id].maxn=(LL)sqrt(op[id].maxn);
                    return;
                }
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed);
            if(mid<ed) dfs(mid+1,r,hr,st,ed);
            op[id].maxn=max(op[hl].maxn,op[hr].maxn);
            op[id].sum=op[hl].sum+op[hr].sum;
        }
        LL query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].sum;
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }
    public:
        void debut() { create(1,n,1); }
        void update(const int &st,const int &ed)
        {
            dfs(1,n,1,st,ed);
        }
        LL get(const int &st,const int &ed)
        {
            return query(1,n,1,st,ed);
        }
}fu;

int main()
{
    n=read();
    fu.debut();
    q=read();
    while(q--)
    {
        int p=read(),st=read(),ed=read();
        if(st>ed) swap(st,ed);
        if(!p) fu.update(st,ed);
        else printf("%lld\n",fu.get(st,ed));
    }
    return 0;
}