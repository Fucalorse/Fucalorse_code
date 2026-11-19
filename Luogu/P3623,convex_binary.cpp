#include <bits/stdc++.h>
using namespace std;

const int MAX=2e4,inf=1e6,LEN=1e5+90;

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

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,inf);

struct ovo
{
    int u,v,col,val;
    bool operator<(const ovo &a)const
    {
        if(val!=a.val) return val<a.val;
        return col<a.col;
    }
}op[LEN],ans[LEN],now[LEN];

int n,m,k;

int dis(const int &mid)
{
    memcpy(now,op,sizeof op);
    for(int i=1;i<=m;i++)
        if(now[i].col==0) now[i].val+=mid;
    fu.debut(n);
    sort(now+1,now+m+1);
    int cnt=0,total=n,qwq=0;
    for(int i=1;i<=m;i++)
    {
        ovo &cur=now[i];
        if(fu.find(cur.u)==fu.find(cur.v)) continue;
        fu.combine(cur.u,cur.v);
        ans[++qwq]=now[i];
        if(cur.col==0) ans[qwq].val-=mid,cnt++;
        if(--total==1) return cnt;
    }
    if(total>1) return -1;
    else return cnt;
}

int main()
{
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),col=read();
        op[i]={u,v,col,dist(rng)};
    }
    int l=-inf-100,r=inf+100;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        int cur=dis(mid);
        if(cur==-1)
        {
            printf("no solution\n");
            exit(0);
        }
        if(cur==k)
        {
            for(int i=1;i<n;i++)
                printf("%d %d %d\n",ans[i].u,ans[i].v,ans[i].col);
            exit(0);
        }
        if(cur<k) r=mid-1;
        else l=mid+1;
    }
    printf("no solution\n");
    return 0;
}