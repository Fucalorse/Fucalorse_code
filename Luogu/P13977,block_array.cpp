#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=2e5+90;

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

int n,m;
LL num[MAX],op[MAX],lazy[MAX];

struct peach
{
    private:
        int id(const int &x) { return (x-1)/m+1; }
        int bl(const int &bx) { return (bx-1)*m+1; }
        int br(const int &bx) { return min(bx*m,n); }
        int cal_l(const int &x) { return bl(id(x)); }
        int cal_r(const int &x) { return br(id(x)); }
        LL cal(const int &x) { return num[x]+lazy[id(x)]; }

        void rebuild(const int &bx)
        {
            int st=bl(bx),ed=br(bx);
            for(int i=st;i<=ed;i++)
                op[i]=num[i];
            sort(op+st,op+ed+1);
        }
        void create()
        {
            for(int i=1;i<=n;i++)
                num[i]=read();
            m=sqrt(n);
            for(int i=1;i<=id(n);i++)
                rebuild(i);
        }
        void add(const int &l,const int &r,const LL &k)
        {
            if(id(l)==id(r))
            {
                for(int i=l;i<=r;i++)
                    num[i]+=k;
                rebuild(id(l));
                return;
            }
            for(int i=l;i<=cal_r(l);i++)
                num[i]+=k;
            rebuild(id(l));
            for(int i=id(l)+1;i<id(r);i++)
                lazy[i]+=k;
            for(int i=cal_l(r);i<=r;i++)
                num[i]+=k;
            rebuild(id(r));
        }
        int query(const int &l,const int &r,const LL &k)
        {
            int ans=0;
            if(id(l)==id(r))
            {
                for(int i=l;i<=r;i++)
                    if(cal(i)<k) ans++;
                return ans;
            }
            for(int i=l;i<=cal_r(l);i++)
                if(cal(i)<k) ans++;
            for(int i=id(l)+1;i<id(r);i++)
                ans+=lower_bound(op+bl(i),op+br(i)+1,k-lazy[i])-(op+bl(i));
            for(int i=cal_l(r);i<=r;i++)
                if(cal(i)<k) ans++;
            return ans;
        }
    public:
        void debut() { create(); }
        void update(const int &l,const int &r,const LL &k) { add(l,r,k); }
        int get(const int &l,const int &r,const LL &k) { return query(l,r,k*k); }
}fu;

int main()
{
    n=read();
    fu.debut();
    for(int i=1;i<=n;i++)
    {
        int p=read(),l=read(),r=read();
        LL k=read();
        if(!p) fu.update(l,r,k);
        else printf("%d\n",fu.get(l,r,k));
    }
    return 0;
}