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

struct rock
{
    LL w,val;
}num[MAX];

struct qwq
{
    int st,ed;
}op[MAX];

int n,m;
LL s;

LL cal(const LL &mid)
{
    LL f[n+5],g[n+5];
    memset(f,0,sizeof f),memset(g,0,sizeof g);
    for(int i=1;i<=n;i++)
    {
        int now=num[i].w>=mid?1:0;
        f[i]=f[i-1]+now;
        g[i]=g[i-1]+now*num[i].val;
    }
    LL total=0;
    for(int i=1;i<=m;i++)
    {
        LL a=f[op[i].ed]-f[op[i].st-1];
        LL b=g[op[i].ed]-g[op[i].st-1];
        total+=a*b;
    }
    return total;
}

int main()
{
    n=read(),m=read(),s=read();
    LL l=0,r=0;
    for(int i=1;i<=n;i++)
    {
        num[i]={read(),read()};
        if(num[i].w>r) r=num[i].w;
    }
    for(int i=1;i<=m;i++)
        op[i].st=read(),op[i].ed=read();
    r++;
    LL ans=1e18;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        LL now=cal(mid);
        if(llabs(now-s)<ans) ans=llabs(now-s);
        if(now>s) l=mid+1;
        else r=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}