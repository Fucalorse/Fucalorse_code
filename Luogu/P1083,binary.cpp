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

struct qwq
{
    LL val;
    int st,ed;
}op[MAX];

LL num[MAX];
int n,m;

bool dis(const int &mid)
{
    LL f[n+10];
    memset(f,0,sizeof f);
    for(int i=1;i<=mid;i++)
    {
        f[op[i].st]+=op[i].val;
        f[op[i].ed+1]-=op[i].val;
    }
    for(int i=1;i<=n;i++)
    {
        f[i]+=f[i-1];
        if(f[i]>num[i]) return false;
    }
    return true;
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        num[i]=read();
    for(int i=1;i<=m;i++)
        op[i].val=read(),op[i].st=read(),op[i].ed=read();
    int l=1,r=m;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(dis(mid)) l=mid+1;
        else r=mid-1;
    }
    if(r==m) printf("0\n");
    else printf("-1\n%d\n",l);
    return 0;
}