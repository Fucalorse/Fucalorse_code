#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=110;
const LL inf=-1e18;

LL read()
{
    LL ans=0,f=1;
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

int n,m;
LL op[MAX][MAX],f[MAX][MAX][MAX];
bool vis[MAX][MAX][MAX];

LL dfs(int i,int j,int k)
{
    if(i>n) return 0;
    if(vis[i][j][k]) return f[i][j][k];
    vis[i][j][k]=true;
    LL ans=inf;
    ans=max(ans,dfs(i+1,j,k)+op[i][j]);
    ans=max(ans,dfs(i+1,j+1,k)+op[i][j]);
    if(k<m)
    {
        ans=max(ans,dfs(i+1,j,k+1)+op[i][j]*3);
        ans=max(ans,dfs(i+1,j+1,k+1)+op[i][j]*3);
    }
    return f[i][j][k]=ans;
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            op[i][j]=read();
    printf("%lld\n",dfs(1,1,0));
    return 0;
}