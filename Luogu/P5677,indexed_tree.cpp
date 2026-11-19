#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=3e5+90;

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

struct fucalorse
{
    private:
        int size;
        vector<LL>op;
        int lowbit(int n) { return n&-n; }
    public:
        fucalorse(int n) { size=n;op.resize(n+10,0); }
        void update(int n)
        {
            while(n<=size)
            {
                op[n]++;
                n+=lowbit(n);
            }
        }
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
};

struct ui
{
    int val,id;
    bool operator<(const ui &a)const { return val<a.val; }
};
vector<ui>num;

struct ovo
{
    int l,r;
    bool operator<(const ovo &a)const { return l>a.l; }
};
vector<ovo>rest;

void add(const ui &a,const ui &b)
{
    int l=min(a.id,b.id),r=max(a.id,b.id);
    rest.push_back({l,r});
}

struct qwq
{
    int l,r,id;
    bool operator<(const qwq &a)const { return l>a.l; }
};
vector<qwq>op;

int n,m;
LL ans[MAX];

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        num.push_back({read(),i});
    sort(num.begin(),num.end());
    add(num[0],num[1]),add(num[n-1],num[n-2]);
    for(int i=1;i<n-1;i++)
    {
        ui &l=num[i-1],&p=num[i],&r=num[i+1];
        if(p.val-l.val<=r.val-p.val) add(l,p);
        if(r.val-p.val<=p.val-l.val) add(p,r);
    }
    for(int i=1;i<=m;i++)
        op.push_back({read(),read(),i});
    sort(rest.begin(),rest.end());
    sort(op.begin(),op.end());
    fucalorse fu(n);
    for(int i=0,j=0;i<m;i++)
    {
        while(j<rest.size()&&rest[j].l>=op[i].l)
        {
            fu.update(rest[j].r);
            j++;
        }
        ans[op[i].id]=fu.query(op[i].r);
    }
    LL total=0;
    for(int i=1;i<=m;i++)
        total+=i*ans[i];
    printf("%lld\n",total);
    return 0;
}