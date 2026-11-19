#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1090,LEN=4e4+90,mid=2e4,mod=998244353;

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
int h[MAX];
LL f[MAX][LEN];

int main()
{
    n=read();
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        h[i]=read();
        if(h[i]>maxn) maxn=h[i];
    }
    LL total=0;
    for(int i=1;i<=n;i++)
    {
        total++;
        for(int j=1;j<i;j++)
        {
            int p=h[i]-h[j]+mid;
            f[i][p]=(f[i][p]+f[j][p]+1)%mod;
            total=(total+f[j][p]+1)%mod;
        }
    }
    printf("%lld\n",total);
    return 0;
}