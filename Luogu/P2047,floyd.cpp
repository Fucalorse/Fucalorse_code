#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=150,inf=0x3f3f3f3f;

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
LL dist[MAX][MAX],f[MAX][MAX];

int main()
{
    n=read(),m=read();
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        dist[u][v]=dist[v][u]=val;
        f[u][v]=f[v][u]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    f[i][j]=f[i][k]*f[k][j];
                }
                else if(dist[i][j]==dist[i][k]+dist[k][j])
                    f[i][j]+=f[i][k]*f[k][j];
            }
    for(int k=1;k<=n;k++)
    {
        double ans=0.0;
        for(int i=1;i<=n;i++)
        {
            if(i==k) continue;
            for(int j=1;j<=n;j++)
            {
                if(j==k||i==j) continue;
                if(dist[i][j]==dist[i][k]+dist[k][j])
                {
                    LL a=f[i][k]*f[k][j];
                    ans+=(double)a/f[i][j];
                }
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}