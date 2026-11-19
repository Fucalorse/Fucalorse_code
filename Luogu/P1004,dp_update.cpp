#include <bits/stdc++.h>
using namespace std;

const int MAX=14;

int n;
int op[MAX][MAX],f[MAX<<1][MAX][MAX];

int main()
{
    cin>>n;
    int x,y,v;
    while(cin>>x>>y>>v&&(x||y||v)) op[x][y]=v;
    for(int k=1;k<=n*2;k++)
        for(int i1=1;i1<=n;i1++)
            for(int i2=1;i2<=n;i2++)
            {
                int j1=k-i1,j2=k-i2;
                if(j1<0||j1>n||j2<0||j2>n) continue;
                int &x=f[k][i1][i2],t=op[i1][j1];
                if(i1!=i2||j1!=j2) t+=op[i2][j2];
                x=max(x,f[k-1][i1-1][i2]+t);
                x=max(x,f[k-1][i1-1][i2-1]+t);
                x=max(x,f[k-1][i1][i2-1]+t);
                x=max(x,f[k-1][i1][i2]+t);
            }
    cout<<f[n*2][n][n]<<'\n';
    return 0;
}