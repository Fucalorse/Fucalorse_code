#include <bits/stdc++.h>
using namespace std;

const int MAX=1e4+90;

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
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for(int i=0;i<n;i++)
    {
        int a=read();
        for(int i=a;i<=w;i++)
            f[i]=min(f[i],f[i-a]+1);
    }
    printf("%d\n",f[w]);
    return 0;
}