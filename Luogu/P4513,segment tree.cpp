#include <bits/stdc++.h>
using namespace std;

const int MAX=5e5+90,inf=-1e9;

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
struct fucalorse
{
    private:
        struct qwq
        {
            int maxn;
            int sl,sr,sum;
        }op[MAX<<2];
        qwq cal(const qwq &a,const qwq &b)
        {
            if(a.maxn==inf||b.maxn==inf) return a.maxn==inf?b:a;
            int suml=max(a.sl,a.sum+b.sl),sumr=max(a.sr+b.sum,b.sr);
            int num=max(max(a.maxn,b.maxn),a.sr+b.sl);
            return {num,suml,sumr,a.sum+b.sum};
        }
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id].maxn=op[id].sl=op[id].sr=op[id].sum=read();
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=cal(op[hl],op[hr]);
        }
        void dfs(int l,int r,int id,const int &x,const int &k)
        {
            if(l==r) 
            {
                op[id].sum=op[id].maxn=op[id].sl=op[id].sr=k;
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,k);
            else dfs(mid+1,r,hr,x,k);
            op[id]=cal(op[hl],op[hr]);
        }
        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            qwq numl={inf,inf,inf,inf},numr={inf,inf,inf,inf};
            if(st<=mid) numl=query(l,mid,hl,st,ed);
            if(mid<ed) numr=query(mid+1,r,hr,st,ed);
            return cal(numl,numr);
        }
        public:
            void debut() { create(1,n,1); }
            void update(const int &x,const int &k)
            {
                dfs(1,n,1,x,k);
            }
            int get(const int &st,const int &ed)
            {
                return query(1,n,1,st,ed).maxn;
            }
}fu;

int main()
{
    n=read(),q=read();
    fu.debut();
    while(q--)
    {
        int p=read();
        if(p==1)
        {
            int st=read(),ed=read();
            if(st>ed) swap(st,ed);
            printf("%d\n",fu.get(st,ed));
        }
        else
        {
            int x=read(),k=read();
            fu.update(x,k);
        }
    }
    return 0;
}