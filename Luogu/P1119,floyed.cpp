#include <bits/stdc++.h>
using namespace std;

const int MAX=250,inf=0x3f3f3f3f;

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

int n,m,q;
int f[MAX][MAX],num[MAX];

int main()
{
    n=read(),m=read();
    memset(f,0x3f,sizeof f);
    for(int i=0;i<n;i++)
        num[i]=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        f[u][v]=f[v][u]=val;
    }
    q=read();
    int k=0;
    while(q--)
    {
        int u=read(),v=read(),t=read();
        while(k<n&&num[k]<=t)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            k++;
        }
        if(num[u]<=t&&num[v]<=t&&f[u][v]!=inf) printf("%d\n",f[u][v]);
        else printf("-1\n");
    }
    return 0;
}