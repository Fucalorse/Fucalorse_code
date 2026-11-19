#include <bits/stdc++.h>
using namespace std;

const int MAX=12;

int n;
int f[MAX][MAX][MAX][MAX],op[MAX][MAX];

int main()
{
    cin>>n;
    int x,y,v;
    while(cin>>x>>y>>v&&(x||y||v)) op[x][y]=v;
    for(int i1=1;i1<=n;i1++)
        for(int j1=1;j1<=n;j1++)
            for(int i2=1;i2<=n;i2++)
                for(int j2=1;j2<=n;j2++)
                {
                    int &x=f[i1][j1][i2][j2];
                    int t=op[i1][j1];
                    if(i1!=i2||j1!=j2) t+=op[i2][j2];
                    x=max(x,f[i1-1][j1][i2-1][j2]+t);
                    x=max(x,f[i1-1][j1][i2][j2-1]+t);
                    x=max(x,f[i1][j1-1][i2-1][j2]+t);
                    x=max(x,f[i1][j1-1][i2][j2-1]+t);
                }
    cout<<f[n][n][n][n]<<'\n';
    return 0;
}