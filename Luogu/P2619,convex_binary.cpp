#include <bits/stdc++.h>
using namespace std;

const int MAX=5e4+90,LEN=1e5+90;

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
        int fa[MAX+90];
    public:
        void debut(int n)
        {
            for(int i=0;i<=n;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x])
                fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
}fu;

struct ovo
{
    int u,v,val,col;
    bool operator<(const ovo &a)const
    {
        if(val!=a.val) return val<a.val;
        return col<a.col;
    }
}op[LEN],now[LEN];

int n,m,k;

pair<int,int> dis(const int &mid)
{
    memcpy(now,op,sizeof op);
    fu.debut(n);
    for(int i=1;i<=m;i++)
        if(now[i].col==0) now[i].val+=mid;
    sort(now+1,now+m+1);
    int cnt=0,total=n,ans=0;
    for(int i=1;i<=m;i++)
    {
        ovo &p=now[i];
        if(fu.find(p.u)==fu.find(p.v)) continue;
        fu.combine(p.u,p.v);
        ans+=p.val;
        if(p.col==0) cnt++;
        if(--total==1) return {cnt,ans};
    }
    return {cnt,ans};
}

int main()
{
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)
    {
        int u=read()+1,v=read()+1,val=read(),col=read();
        op[i]={u,v,val,col};
    }
    int l=-110,r=110,ans;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        auto cur=dis(mid);
        if(cur.first>=k)
        {
            ans=cur.second-mid*k;
            l=mid+1;
        }
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}