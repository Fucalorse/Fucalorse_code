#include <bits/stdc++.h>
using namespace std;

const int MAX=1090,inf=2e9;

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

int n,m,s,bit;
int f[MAX][MAX],g[MAX][MAX];
struct fucalorse
{
    void create()
    {
        bit=log2(s);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                f[i][j]=g[i][j]=read();
        for(int k=1;(1<<k)<=s;k++)
        {
            int p=1<<(k-1);
            for(int i=1;i<=n-(1<<k)+1;i++)
                for(int j=1;j<=m-(1<<k)+1;j++)
                {
                    f[i][j]=max(max(f[i][j],f[i+p][j]),max(f[i][j+p],f[i+p][j+p]));
                    g[i][j]=min(min(g[i][j],g[i+p][j]),min(g[i][j+p],g[i+p][j+p]));
                }
        }
    }
    int query(int i,int j)
    {
        int p=1<<bit,ni=i+s,nj=j+s;
        if(p==s) return f[i][j]-g[i][j];
        int a=max(max(f[i][j],f[ni-p][j]),max(f[i][nj-p],f[ni-p][nj-p]));
        int b=min(min(g[i][j],g[ni-p][j]),min(g[i][nj-p],g[ni-p][nj-p]));
        return a-b;
    }
}fu;

int main()
{
    n=read(),m=read(),s=read();
    fu.create();
    int ans=inf;
    for(int i=1;i<=n-s+1;i++)
        for(int j=1;j<=m-s+1;j++)
            ans=min(ans,fu.query(i,j));
    printf("%d\n",ans);
    return 0;
}