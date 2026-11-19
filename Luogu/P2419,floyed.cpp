#include <bits/stdc++.h>
using namespace std;

const int MAX=150;

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
bitset<MAX>f[MAX],g[MAX];

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read();
        f[u][v]=1;
        g[v][u]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        {
            if(f[i][k]) f[i]|=f[k];
            if(g[i][k]) g[i]|=g[k];
        }
    int total=0;
    for(int i=1;i<=n;i++)
    {
        f[i][i]=g[i][i]=1;
        int ans=f[i].count()+g[i].count()-1;
        if(ans==n) total++;
    }
    printf("%d\n",total);
    return 0;
}