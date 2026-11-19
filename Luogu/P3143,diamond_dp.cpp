#include <bits/stdc++.h>
using namespace std;

const int MAX=5e4+90;

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
int f[MAX],num[MAX];

int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)
        num[i]=read();
    sort(num+1,num+n+1);
    int ans=0;
    for(int l=1,r=1;l<=n;l++)
    {
        while(r<=n&&num[r]-num[l]<=k) 
        {
            r++;
            f[r]=max(f[r-1],r-l);
        }
        ans=max(ans,f[l]+r-l);
    }
    printf("%d\n",ans);
    return 0;
}