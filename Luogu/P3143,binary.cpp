#include <bits/stdc++.h>
using namespace std;

const int MAX=5e4+90;

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
int num[MAX],f[MAX],g[MAX];

int cal_l(const int &x)
{
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(num[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return l;
}

int cal_r(const int &x)
{
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(num[mid]<=x) l=mid+1;
        else r=mid-1;
    }
    return r;
}

int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)
        num[i]=read();
    sort(num+1,num+n+1);
    for(int i=1;i<=n;i++)
    {
        f[i]=i-cal_l(num[i]-k)+1;
        g[i]=cal_r(num[i]+k)-i+1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f[i-1]+g[i]);
        f[i]=max(f[i-1],f[i]);
    }
    printf("%d\n",ans);
    return 0;
}