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

struct fucalorse
{
    private:
        int size;
        vector<LL>f,g;
        int lowbit(int n) { return n&-n; }
    public:
        fucalorse(int n) { size=n;f.resize(n+10,0),g.resize(n+10,0); }
        void update(int n,const LL &x)
        {
            int p=n;
            while(n<=size)
            {
                f[n]+=x;
                g[n]+=x*p;
                n+=lowbit(n);
            }
        }
        LL query(int n)
        {
            int p=n+1;
            LL ans=0;
            while(n)
            {
                ans+=p*f[n]-g[n];
                n-=lowbit(n);
            }
            return ans;
        }
};

int main()
{
    int n=read(),q=read();
    fucalorse fu(n);
    LL a=0,b=0,c;
    for(int i=1;i<=n;i++)
    {
        c=read();
        fu.update(i,c-2*b+a);
        a=b,b=c;
    }
    while(q--)
    {
        int p=read();
        if(p==1)
        {
            int l=read(),r=read();
            LL k=read(),d=read();
            fu.update(l,k);
            fu.update(l+1,d-k);
            fu.update(r+1,-k-(r-l+1)*d);
            fu.update(r+2,k+(r-l)*d);
        }
        else
        {
            int x=read();
            printf("%lld\n",fu.query(x));
        }
    }
    return 0;
}