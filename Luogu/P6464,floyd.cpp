#include <bits/stdc++.h>
using namespace std;

const int MAX=110,inf=1e9;

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
int op[MAX][MAX],f[MAX][MAX];

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) op[i][j]=inf;
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        op[u][v]=op[v][u]=val;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                op[i][j]=min(op[i][j],op[i][k]+op[k][j]);
    int ans=inf;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
        {
            memcpy(f,op,sizeof op);
            f[x][y]=f[y][x]=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[i][j]=min(f[i][j],f[i][x]+f[x][j]);
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[i][j]=min(f[i][j],f[i][y]+f[y][j]);
            int total=0;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    total+=f[i][j];
            ans=min(ans,total);
        }
    printf("%d\n",ans);
    return 0;
}