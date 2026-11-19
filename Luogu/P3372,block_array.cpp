#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=5e5+90;

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

int n,m,q;
LL num[MAX],lazy[MAX],sum[MAX];

struct peach
{
    private:
        int id(const int &x) { return (x-1)/m+1; }
        int bl(const int &bx) { return (bx-1)*m+1; }
        int br(const int &bx) { return min(bx*m,n); }
        int cal_l(const int &x) { return bl(id(x)); }
        int cal_r(const int &x) { return br(id(x)); }
        LL cal(const int &x) { return num[x]+lazy[id(x)]; }

        void create()
        {
            m=sqrt(n);
            for(int i=1;i<=n;i++)
            {
                num[i]=read();
                sum[id(i)]+=num[i];
            }
        }
        void add(int l,int r,const LL &k)
        {
            if(id(l)==id(r))
            {
                for(int i=l;i<=r;i++)
                    num[i]+=k,sum[id(l)]+=k;
                return;
            }
            for(int i=l;i<=cal_r(l);i++)
                num[i]+=k,sum[id(l)]+=k;
            for(int i=id(l)+1;i<id(r);i++)
                lazy[i]+=k;
            for(int i=cal_l(r);i<=r;i++)
                num[i]+=k,sum[id(r)]+=k;
        }
        LL query(const int &l,const int &r)
        {
            LL ans=0;
            if(id(l)==id(r))
            {
                for(int i=l;i<=r;i++)
                    ans+=cal(i);
                return ans;
            }
            for(int i=l;i<=cal_r(l);i++)
                ans+=cal(i);
            for(int i=id(l)+1;i<id(r);i++)
                ans+=sum[i]+lazy[i]*m;
            for(int i=cal_l(r);i<=r;i++)
                ans+=cal(i);
            return ans;
        }
    public:
        void debut() { create(); }
        void update(const int &l,const int &r,const LL &k) { add(l,r,k); }
        LL get(const int &l,const int &r) { return query(l,r); }
}fu;

int main()
{
    n=read(),q=read();
    fu.debut();
    while(q--)
    {
        int p=read(),l=read(),r=read();
        if(p==1)
        {
            LL k=read();
            fu.update(l,r,k);
        }
        else printf("%lld\n",fu.get(l,r));
    }
    return 0;
}