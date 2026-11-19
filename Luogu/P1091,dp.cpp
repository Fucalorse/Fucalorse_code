#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

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

int n;
int f[MAX],g[MAX],num[MAX];

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        num[i]=read();
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            if(num[i]>num[j]) f[i]=max(f[i],f[j]+1);
    for(int i=n;i>=1;i--)
        for(int j=n+1;j>i;j--)
            if(num[i]>num[j]) g[i]=max(g[i],g[j]+1);
    int maxn=0;
    for(int i=1;i<=n;i++)
        maxn=max(maxn,f[i]+g[i]-1);
    printf("%d\n",n-maxn);
    return 0;
}