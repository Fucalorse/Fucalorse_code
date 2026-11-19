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
int num[MAX],f[MAX][MAX];

int dfs(int pos,int sum)
{
    if(sum==w) return f[pos][sum]=1;
    if(pos>n||sum>w) return 0;
    if(f[pos][sum]) return f[pos][sum];
    int cnt=0;
    for(int i=0;i<=num[pos];i++)
        cnt=(cnt+dfs(pos+1,sum+i))%mod;
    return f[pos][sum]=cnt;
}

int main()
{
    n=read(),w=read();
    for(int i=1;i<=n;i++)
        num[i]=read();
    printf("%d\n",dfs(1,0));
    return 0;
}