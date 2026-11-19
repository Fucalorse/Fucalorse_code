#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=150;

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

int n,m,st;
int pre[MAX][MAX];
LL f[MAX][MAX],op[MAX][MAX],maxn=-1e18;

void print(int k,int pos)
{
    if(!pos) return;
    print(k-1,pre[k][pos]);
    printf("%d ",pos);
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            op[i][j]=read();
    memset(f,-0x3f,sizeof f);
    for(int i=0;i<=m;i++)
        f[0][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=k;i<=m;i++)
            for(int j=k-1;j<i;j++)
            {
                LL now=f[k-1][j]+op[k][i];
                if(now>f[k][i]) f[k][i]=now,pre[k][i]=j;
                if(k==n&&f[k][i]>maxn) maxn=f[k][i],st=i;
            }
    printf("%lld\n",maxn);
    print(n,st);
    printf("\n");
    return 0;
}