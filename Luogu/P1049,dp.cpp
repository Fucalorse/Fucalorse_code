#include <bits/stdc++.h>
using namespace std;

const int MAX=2e4+90;

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

int w,n;
int f[MAX];

int main()
{
    w=read(),n=read();
    for(int i=0;i<n;i++)
    {
        int a=read();
        for(int j=w;j>=a;j--)
            f[j]=max(f[j],f[j-a]+a);
    }
    printf("%d\n",w-f[w]);
    return 0;
}