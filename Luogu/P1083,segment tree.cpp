#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e6+90;

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
struct fucalorse
{
    private:
        struct tree
        {
            LL minn,lazy;
        }op[MAX<<2];
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id].minn=read();
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id].minn=min(op[hl].minn,op[hr].minn);
        }
        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;
                op[hl].minn-=op[id].lazy;
                op[hl].lazy+=op[id].lazy;
                op[hr].minn-=op[id].lazy;
                op[hr].lazy+=op[id].lazy;
                op[id].lazy=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const LL &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].minn-=k;
                op[id].lazy+=k;
                return;
            }
            down(id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id].minn=min(op[hl].minn,op[hr].minn);
        }
        public:
            void debut() { create(1,n,1); }
            void update(const int &st,const int &ed,const LL &k)
            {
                dfs(1,n,1,st,ed,k);
            }
            LL get() { return op[1].minn; }
}fu;

int main()
{
    n=read(),m=read();
    fu.debut();
    for(int i=1;i<=m;i++)
    {
        LL k=read();
        int st=read(),ed=read();
        fu.update(st,ed,k);
        if(fu.get()<0) 
        {
            printf("-1\n%d\n",i);
            exit(0);
        }
    }
    printf("0\n");
    return 0;
}