#include <bits/stdc++.h>
using namespace std;

const int MAX=1e4+90,mod=1e9+7;

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

int n,w;
int op[MAX],f[MAX];

int main()
{
    n=read(),w=read();
    for(int i=1;i<=n;i++)
        op[i]=read();
    f[0]=1;
    for(int i=1;i<=w;i++)
        for(int j=1;j<=n;j++)
        {
            if(op[j]>i) continue;
            f[i]=(f[i]+f[i-op[j]])%mod;
        }
    printf("%d\n",f[w]);
    return 0;
}