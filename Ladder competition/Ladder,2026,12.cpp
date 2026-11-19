#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=15;

int w,n,ans=0;
int op[MAX][MAX],f[MAX][MAX],g[MAX][MAX];

void dfs(int depth,int x,int y)
{
    if(depth==n*n)
    {
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=n;j++)
        //         cout<<op[x][y]<<' ';
        //     cout<<endl;
        // }
        if(f[x-1][y]==g[x][y-1]&&f[x-1][y]>=0) ans++;
        // if(ans==10) exit(0);
        return;
    }
    if(y==n)
    {
        op[x][y]=g[x][y-1];
        f[x][y]=f[x-1][y]-op[x][y];
        // cout<<f[x][y]<<endl;
        if(g[x][y-1]<0) return;
        dfs(depth+1,x+1,1);
    }
    else if(x==n)
    {
        op[x][y]=f[x-1][y];
        g[x][y]=g[x][y-1]-op[x][y];
        // cout<<g[x][y]<<endl;
        if(f[x-1][y]<0) return;
        dfs(depth+1,x,y+1);
    }
    else
    {
        for(int i=0;i<=min(f[x-1][y],g[x][y-1]);i++)
        {
            op[x][y]=i;
            f[x][y]=f[x-1][y]-i;
            g[x][y]=g[x][y-1]-i;
            // cout<<depth<<' '<<f[x][y]<<' '<<g[x][y]<<endl;
            dfs(depth+1,x,y+1);
            // f[x][y]=f[x-1][y];
            // g[x][y]=g[x][y-1];
        }
    }
}

int main()
{
    cin>>w>>n;
    for(int i=0;i<=n;i++)
        f[i][0]=f[0][i]=g[i][0]=g[0][i]=w;
    dfs(1,1,1);
    cout<<ans<<endl;
    return 0;
}