#include <bits/stdc++.h>
using namespace std;

const int MAX=300;
const int op[MAX][MAX]={{0,0,0,0,0,0},
                        {0,5,-1,-2,-1,-3},
                        {0,-1,5,-3,-2,-4},
                        {0,-2,-3,5,-2,-2},
                        {0,-1,-2,-2,5,-1},
                        {0,-3,-4,-2,-1,-10086}};
            
int n,m;
int a[MAX],b[MAX],f[MAX][MAX];

int change(const char &c)
{
    if(c=='A') return 1;
    else if(c=='C') return 2;
    else if(c=='G') return 3;
    else return 4;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        a[i]=change(c);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        char c;
        cin>>c;
        b[i]=change(c);
    }
    memset(f,-0x3f,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=n;i++)
        f[i][0]=f[i-1][0]+op[a[i]][5];
    for(int i=1;i<=m;i++)
        f[0][i]=f[0][i-1]+op[5][b[i]];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int &x=f[i][j];
            x=max(x,f[i-1][j-1]+op[a[i]][b[j]]);
            x=max(x,f[i-1][j]+op[a[i]][5]);
            x=max(x,f[i][j-1]+op[5][b[j]]);
        }
    cout<<f[n][m]<<'\n';
    return 0;
}