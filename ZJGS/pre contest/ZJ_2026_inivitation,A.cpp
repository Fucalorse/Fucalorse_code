#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=410,inf=2e9;

int n,b;
int f[MAX][MAX];

int main()
{
    cin>>n>>b;
    for(int i=1;i<=n;i++)
        f[i][i]=i;
    for(int len=2;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1,x=f[i][j-1]+j;
            f[i][j]=inf;
            for(int k=i;k<j;k++)
                f[i][j]=min(f[i][j],min(max(f[i][k-1]+k,f[k+1][j]+b),x));
        }
    cout<<f[1][n]<<endl;
    return 0;
}