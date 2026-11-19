#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e7+90;

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

int w,n;
LL f[MAX];

int main()
{
    w=read(),n=read();
    for(int i=1;i<=n;i++)
    {
        int t=read(),val=read();
        for(int j=t;j<=w;j++)
            f[j]=max(f[j],f[j-t]+val);
    }
    printf("%lld\n",f[w]);
    return 0;
}