#include <bits/stdc++.h>
using namespace std;

const int MAX=45,LEN=400;

int n,m;
int f[MAX][MAX][MAX][MAX],op[LEN],c[6];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>op[i];
    for(int i=1;i<=m;i++)
    {
        int a;
        cin>>a;
        c[a]++;
    }
    f[0][0][0][0]=op[1];
    for(int h=0;h<=c[1];h++)
        for(int i=0;i<=c[2];i++)
            for(int j=0;j<=c[3];j++)
                for(int k=0;k<=c[4];k++)
                {
                    int &x=f[h][i][j][k],s=h+i*2+j*3+k*4+1;
                    if(h-1>=0) x=max(x,f[h-1][i][j][k]+op[s]);
                    if(i-1>=0) x=max(x,f[h][i-1][j][k]+op[s]);
                    if(j-1>=0) x=max(x,f[h][i][j-1][k]+op[s]);
                    if(k-1>=0) x=max(x,f[h][i][j][k-1]+op[s]);
                }
    cout<<f[c[1]][c[2]][c[3]][c[4]]<<'\n';
    return 0;
}