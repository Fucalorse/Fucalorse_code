#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int mod=1e9+7;

int n,m,s;
char a[1090],b[1090];
LL f[2][210][210][2];

int main()
{
    cin>>n>>m>>s>>(a+1)>>(b+1);
    f[0][0][0][0]=f[1][0][0][0]=1;
    for(int i=1,p=1;i<=n;i++,p^=1)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=s;k++)
            {
                if(a[i]==b[j])
                {
                    f[p][j][k][0]=(f[p^1][j][k][0]+f[p^1][j][k][1])%mod;
                    f[p][j][k][1]=(f[p^1][j-1][k-1][0]+f[p^1][j-1][k-1][1]+f[p^1][j-1][k][1])%mod;
                }
                else
                {
                    f[p][j][k][0]=(f[p^1][j][k][0]+f[p^1][j][k][1])%mod;
                    f[p][j][k][1]=0;
                }
            }
    cout<<(f[n&1][m][s][0]+f[n&1][m][s][1])%mod<<'\n';
    return 0;
}