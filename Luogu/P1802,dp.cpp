#include <bits/stdc++.h>
using namespace std;

#define LL long long

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

int n,x;
LL f[MAX];

int main()
{
    n=read(),x=read();
    for(int i=0;i<n;i++)
    {
        int l=read(),w=read(),a=read();
        for(int j=x;j>=a;j--)
            f[j]=max(f[j]+l,f[j-a]+w);
        for(int j=a-1;j>=0;j--)
            f[j]+=l;
    }
    printf("%lld\n",f[x]*5);
    return 0;
}