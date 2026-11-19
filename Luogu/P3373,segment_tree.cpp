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

int n,q,mod;
struct fucalorse
{
    private:
        struct tree
        {
            LL sum,plu,mul;
        }op[MAX<<2];
        void create(int l,int r,int id)
        {
            op[id].plu=0,op[id].mul=1;
            if(l==r)
            {
                op[id].sum=read()%mod;
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id].sum=(op[hl].sum+op[hr].sum)%mod;
        }
        void down(int l,int r,int id)
        {
            if(op[id].plu||op[id].mul!=1)
            {
                int mid=(l+r)>>1;
                int hl=id<<1,hr=id<<1|1;
                int lenl=mid-l+1,lenr=r-mid;
                const LL &a=op[id].plu,&k=op[id].mul;
                
                op[hl].sum=(op[hl].sum*k+a*lenl)%mod;
                op[hl].mul=op[hl].mul*k%mod;
                op[hl].plu=(op[hl].plu*k+a)%mod;

                op[hr].sum=(op[hr].sum*k+a*lenr)%mod;
                op[hr].mul=op[hr].mul*k%mod;
                op[hr].plu=(op[hr].plu*k+a)%mod;

                op[id].plu=0,op[id].mul=1;
            }
        }
        void add(int l,int r,int id,const int &st,const int &ed,const LL &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].sum=(op[id].sum+k*(r-l+1))%mod;
                op[id].plu=(op[id].plu+k)%mod;
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) add(l,mid,hl,st,ed,k);
            if(mid<ed) add(mid+1,r,hr,st,ed,k);
            op[id].sum=(op[hl].sum+op[hr].sum)%mod;
        }
        void multiply(int l,int r,int id,const int &st,const int &ed,const LL &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].sum=op[id].sum*k%mod;
                op[id].mul=op[id].mul*k%mod;
                op[id].plu=op[id].plu*k%mod;
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) multiply(l,mid,hl,st,ed,k);
            if(mid<ed) multiply(mid+1,r,hr,st,ed,k);
            op[id].sum=(op[hl].sum+op[hr].sum)%mod;
        }
        LL query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].sum;
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            return (query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed))%mod;
        }
        public:
            void debut() { create(1,n,1); }
            void update(const int &st,const int &ed,const int &p,const LL &k)
            {
                if(p==1) multiply(1,n,1,st,ed,k);
                else add(1,n,1,st,ed,k);
            }
            LL get(const int &st,const int &ed)
            {
                return query(1,n,1,st,ed);
            }
}fu;

int main()
{
    n=read(),q=read(),mod=read();
    fu.debut();
    while(q--)
    {
        int p=read(),st=read(),ed=read();
        if(p<=2)
        {
            LL  k=read();
            fu.update(st,ed,p,k);
        }
        else printf("%lld\n",fu.get(st,ed));
    }
    return 0;
}