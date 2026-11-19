#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=3010;

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

int n,s,bit1,bit2;
int f[MAX][MAX],g[MAX][MAX],a[MAX][MAX];
struct fucalorse
{
    void create()
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                f[i][j]=g[i][j]=read();
        if(!bit2) memcpy(a,g,sizeof g);
        for(int k=1;(1<<k)<=s;k++)
        {
            int p=1<<(k-1);
            for(int i=1;i+(1<<k)-1<=n;i++)
                for(int j=1;j<=i;j++)
                {
                    f[i][j]=max(max(f[i][j],f[i+p][j+p]),g[i+p][j]);
                    g[i][j]=max(max(g[i][j],g[i+p][j]),max(g[i][j+p],g[i+p][j+p]));
                }
            if(k==bit2) memcpy(a,g,sizeof g);
        }
    }
    int find(const int &i,const int &j)
    {
        int dx=s-(1<<bit1),p=1<<bit2;
        int ni=i+dx,nj=j+dx;
        return max(max(a[i][j],a[ni-p][j]),max(a[i][nj-p],a[ni-p][nj-p]));
    }
    int query(const int &i,const int &j)
    {
        if((1<<bit1)==s) return f[i][j];
        int p=1<<bit1;
        int ni=i+s,nj=j+s;
        return max(max(f[i][j],f[ni-p][nj-p]),find(i+p,j));
    }
}fu;

int main()
{
    n=read(),s=read();
    bit1=log2(s),bit2=s-(1<<bit1)==0?0:log2(s-(1<<bit1));
    fu.create();
    LL total=0;
    for(int i=1;i<=n-s+1;i++)
        for(int j=1;j<=i;j++)
            total+=fu.query(i,j);
    printf("%lld\n",total);
    return 0;
}