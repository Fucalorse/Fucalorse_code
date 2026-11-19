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
LL num[MAX],lazy[MAX];

struct peach
{
    private:
        int id(const int &x) { return (x-1)/m+1; }
        int bl(const int &bx) { return (bx-1)*m+1; }
        int br(const int &bx) { return min(bx*m,n); }
        int cal_l(const int &x) { return bl(id(x)); }
        int cal_r(const int &x) { return br(id(x)); }
        LL cal(const int &x) { return num[x]+lazy[id(x)]; }

        void add(const int &l,const int &r,const LL &k)
        {
            if(id(l)==id(r))
            {
                for(int i=l;i<=r;i++)
                    num[i]+=k;
                return;
            }
            for(int i=l;i<=cal_r(l);i++)
                num[i]+=k;
            for(int i=id(l)+1;i<id(r);i++)
                lazy[i]+=k;
            for(int i=cal_l(r);i<=r;i++)
                num[i]+=k;
        }
    public:
        void debut()
        {
            m=sqrt(n);
            for(int i=1;i<=n;i++)
                num[i]=read();
        }
        void update(const int &l,const int &r,const LL &k) { add(l,r,k); }
        LL query(const int &x) { return cal(x); }
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
            int l=read(),r=read();
            LL k=read();
            fu.update(l,r,k);
        }
        else
        {
            int x=read();
            printf("%lld\n",fu.query(x));
        }
    }
    return 0;
}