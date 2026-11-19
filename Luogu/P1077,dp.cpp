#include <bits/stdc++.h>
using namespace std;

const int MAX=150,mod=1e6+7;

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
int f[MAX];

int main()
{
    n=read(),w=read();
    f[0]=1;
    for(int i=0;i<n;i++)
    {
        int a=read();
        for(int j=w;j>=1;j--)
            for(int k=1;k<=min(j,a);k++)
                f[j]=(f[j]+f[j-k])%mod;
    }
    printf("%d\n",f[w]);
    return 0;
}