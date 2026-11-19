#include <bits/stdc++.h>
using namespace std;

#define LL long long

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

int t,q,mod;
struct fucalorse
{
    private:
        vector<LL>op;
        void dfs(int l,int r,int id,const int &x,const LL &k)
        {
            if(l==r)
            {
                op[id]=k%mod;
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,k);
            else dfs(mid+1,r,hr,x,k);
            op[id]=op[hl]*op[hr]%mod;
        }
    public:
        fucalorse(int n) { op.resize((n+90)<<2,1); }
        void update(const int &x,const LL &k) { dfs(1,q,1,x,k); }
        LL get() { return op[1]; }
};

int main()
{
    t=read();
    while(t--)
    {
        q=read(),mod=read();
        fucalorse fu(q);
        for(int i=1;i<=q;i++)
        {
            int p=read();
            if(p==1)
            {
                LL k=read();
                fu.update(i,k);
            }
            else
            {
                int x=read();
                fu.update(x,1);
            }
            printf("%lld\n",fu.get());
        }
    }
    return 0;
}