#include <bits/stdc++.h>
using namespace std;

const int MAX=110;

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

int n;
bitset<MAX>f[MAX];

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=read();
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            if(f[i][k]) f[i]|=f[k];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",f[i][j]?1:0);
        printf("\n");
    }
    return 0;
}