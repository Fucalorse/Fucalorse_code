#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

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

int n,qwq;
int f[MAX],g[MAX],num[MAX],op[MAX];

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        num[i]=read();
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(op+1,op+qwq+1,num[i])-op;
        f[i]=pos;
        op[pos]=num[i];
        qwq=max(qwq,pos);
    }
    memset(op,0,sizeof op),qwq=0;
    for(int i=n;i>=1;i--)
    {
        int pos=lower_bound(op+1,op+qwq+1,num[i])-op;
        g[i]=pos;
        op[pos]=num[i];
        qwq=max(qwq,pos);
    }
    int maxn=0;
    for(int i=1;i<=n;i++)
        maxn=max(maxn,f[i]+g[i]-1);
    printf("%d\n",n-maxn);
    return 0;
}