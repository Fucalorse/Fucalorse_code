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
            LL sum,a,d;
        }op[MAX<<2];
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id].sum=read();
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id].sum=op[hl].sum+op[hr].sum;
        }
        void cal(int id,int len,LL a,LL d)
        {
            op[id].sum+=a*len+len*(len-1)*d;
            op[id].a+=a;
            op[id].d+=d;
        }
        void down(int l,int r,int id)
        {
            if(op[id].a||op[id].d)
            {
                int mid=(l+r)>>1;
                int hl=id<<1,hr=id<<1|1;
                int lenl=mid-l+1,lenr=r-mid;
                LL a1=op[id].a,a2=op[id].a+(mid+1-l)*op[id].d;
                cal(hl,lenl,a1,op[id].d);
                cal(hr,lenr,a2,op[id].d);
                op[id].a=op[id].d=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const LL &a,const LL &d)
        {
            if(st<=l&&r<=ed)
            {
                LL p=a+(l-st)*d;
                cal(id,r-l+1,p,d);
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,a,d);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,a,d);
            op[id].sum=op[hl].sum+op[hr].sum;
        }
        LL query(int l,int r,int id,const int &x)
        {
            if(l==r) return op[id].sum;
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(x<=mid) return query(l,mid,hl,x);
            else return query(mid+1,r,hr,x);
        }
        public:
            void debut() { create(1,n,1); }
            void update(const int &st,const int &ed,const LL &a,const LL &d)
            {
                dfs(1,n,1,st,ed,a,d);
            }
            LL get(const int &x) { return query(1,n,1,x); }
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
            LL a=read(),d=read();
            fu.update(st,ed,a,d);
        }
        else
        {
            int x=read();
            printf("%lld\n",fu.get(x));
        }
    }
    return 0;
}