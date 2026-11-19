#include <bits/stdc++.h>
using namespace std;

const int MAX=5e5+90,inf=2e9;

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

int n,k;
int f[MAX];
struct fucalorse
{
    private:
        int op[MAX<<2];
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id]=f[l];
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=min(op[hl],op[hr]);
        }
        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return inf;
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            return min(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
        public:
            void debut() { create(1,n,1); }
            int get(const int &st,const int &ed)
            {
                return query(1,n,1,st,ed);
            }
}fu;

int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)
        f[i]=f[i-1]+read();
    fu.debut();
    int ans=-inf;
    for(int i=1;i<=n;i++)
    {
        int st=i-k>0?i-k:0,ed=i-1;
        int now=fu.get(st,ed);
        if(!st&&now>0) now=0;
        ans=max(ans,f[i]-now);
    }
    printf("%d\n",ans);
    return 0;
}