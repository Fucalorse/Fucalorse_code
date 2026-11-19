#include <bits/stdc++.h>
using namespace std;

const int MAX=220,inf=2e9;

int n;
int op[MAX],num[MAX],f[MAX][MAX],g[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    int len=n<<1;
    for(int i=1;i<=len;i++)
        op[i]=op[i-1]+num[(i-1)%n+1];
    memset(f,0x3f,sizeof f),memset(g,-0x3f,sizeof g);
    for(int j=1;j<=len;j++)
    {
        f[j][j]=g[j][j]=0;
        for(int i=j-1;i>=1;i--)
            for(int k=i;k<j;k++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+op[j]-op[i-1]);
                g[i][j]=max(g[i][j],g[i][k]+g[k+1][j]+op[j]-op[i-1]);
            }
    }
    int minn=inf,maxn=-inf;
    for(int i=1;i<=n;i++)
    {
        minn=min(minn,f[i][i+n-1]);
        maxn=max(maxn,g[i][i+n-1]);
    }
    cout<<minn<<'\n'<<maxn<<'\n';
    return 0;
}