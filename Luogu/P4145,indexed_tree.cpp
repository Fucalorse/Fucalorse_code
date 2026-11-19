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
        vector<LL>op;
        int lowbit(int n) { return n&-n; }
        LL query(int n)
        {
            LL ans=0;
            while(n)
            {
                ans+=op[n];
                n-=lowbit(n);
            }
            return ans;
        }
    public:
        fucalorse(int n) { size=n,op.resize(n+10,0); }
        void update(int n,const LL &k)
        {
            while(n<=size)
            {
                op[n]+=k;
                n+=lowbit(n);
            }
        }
        LL get(const int &st,const int &ed) { return query(ed)-query(st-1); }
};

int n,q;
LL op[MAX];
int fa[MAX];
int find(int x)
{
    if(x!=fa[x])
        fa[x]=find(fa[x]);
    return fa[x];
}

int main()
{
    n=read();
    fucalorse fu(n);
    for(int i=1;i<=n;i++)
    {
        op[i]=read();
        fa[i]=i;
        fu.update(i,op[i]);
    }
    fa[n+1]=182497;
    q=read();
    while(q--)
    {
        int p=read(),st=read(),ed=read();
        if(st>ed) swap(st,ed);
        if(!p)
        {
            for(int i=st;i<=ed;i=find(i)==i?i+1:fa[i])
            {
                LL aft=(LL)sqrt(op[i]);
                fu.update(i,aft-op[i]);
                op[i]=aft;
                if(op[i]==1) fa[i]=i+1;
            }
        }
        else printf("%lld\n",fu.get(st,ed));
    }
    return 0;
}