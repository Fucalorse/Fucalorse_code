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

int n,k;
int f[MAX];

int main()
{
    n=read(),k=read();
    f[0]=1;
    for(int i=0;i<n;i++)
    {
        int a=read();
        for(int j=k;j>=a;j--)
            f[j]+=f[j-a];
    }
    printf("%d\n",f[k]);
    return 0;
}