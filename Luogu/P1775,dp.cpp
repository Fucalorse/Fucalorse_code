#include <bits/stdc++.h>
using namespace std;

const int MAX=350;

int n;
int f[MAX][MAX],op[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i];
        op[i]+=op[i-1];
    }
    memset(f,0x3f,sizeof f);
    for(int j=1;j<=n;j++)
    {
        f[j][j]=0;
        for(int i=j-1;i>=1;i--)
            for(int k=i;k<j;k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+op[j]-op[i-1]);
    }
    cout<<f[1][n]<<'\n';
    return 0;
}