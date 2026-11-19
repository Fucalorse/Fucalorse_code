#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=110;
const LL inf=-1e18;

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
LL f[MAX][MAX][MAX],op[MAX][MAX];

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            op[i][j]=read();
    memset(f,-0x3f,sizeof f);
    for(int i=1;i<=n+1;i++)
        for(int j=0;j<=m;j++)
            f[n+1][i][j]=0;
    for(int i=n;i>=1;i--)
        for(int j=1;j<=i;j++)
            for(int k=0;k<=min(n,m);k++)
            {
                f[i][j][k]=max(f[i+1][j][k],f[i+1][j+1][k])+op[i][j];
                if(k)
                {
                    f[i][j][k]=max(f[i][j][k],f[i+1][j][k-1]+op[i][j]*3);
                    f[i][j][k]=max(f[i][j][k],f[i+1][j+1][k-1]+op[i][j]*3);
                }
            }
    printf("%lld\n",f[1][1][min(n,m)]);
    return 0;
}