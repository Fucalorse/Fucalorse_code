#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,mod=10007;

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

int n,m;
int f[MAX];
int sum[MAX][2],num[MAX][2],col[MAX];

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        f[i]=read();
    for(int i=1;i<=n;i++)
    {
        col[i]=read();
        int p=col[i],q=i%2;
        sum[p][q]=(sum[p][q]+f[i])%mod;
        num[p][q]++;
    }
    int total=0;
    for(int i=1;i<=n;i++)
    {
        int p=col[i],q=i%2;
        if(num[p][q]<2) continue;
        total=(total+i%mod*((num[p][q]-2)%mod*f[i]%mod+sum[p][q])%mod)%mod;
    }
    printf("%d\n",total);
    return 0;
}