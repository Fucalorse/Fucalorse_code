#include <bits/stdc++.h>
using namespace std;

const int MAX=1090,mod=19650827;

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
        f[i][i]=1;
    }
    for(int k=2;k<=n;k++)
        for(int i=1;i+k-1<=n;i++)
        {
            int j=i+k-1;
            if(op[j]>op[j-1]) f[i][j]+=f[i][j-1];
            if(op[j]>op[i]&&k!=2) f[i][j]+=f[j-1][i];
            if(op[i]<op[i+1]) f[j][i]+=f[j][i+1];
            if(op[i]<op[j]&&k!=2) f[j][i]+=f[i+1][j];
            f[i][j]%=mod,f[j][i]%=mod;
        }
    cout<<(f[1][n]+f[n][1])%mod<<'\n';
    return 0;
}