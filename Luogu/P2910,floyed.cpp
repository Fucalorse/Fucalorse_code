#include <bits/stdc++.h>
using namespace std;

const int MAX=1e4+90,LEN=150;

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
int f[LEN][LEN],op[MAX];

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
        op[i]=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=read();
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    int total=0;
    for(int i=2;i<=m;i++)
        total+=f[op[i-1]][op[i]];
    printf("%d\n",total);
    return 0;
}