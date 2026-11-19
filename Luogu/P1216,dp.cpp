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

int n;
int op[MAX][MAX],f[MAX][MAX];

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            op[i][j]=read();
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            f[i][j]=max(f[i-1][j],f[i-1][j-1])+op[i][j];
            if(i==n) ans=max(ans,f[i][j]);
        }    
    printf("%d\n",ans);
    return 0;
}