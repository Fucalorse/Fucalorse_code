#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=60;

int n,st;
int p[MAX],v[MAX];
LL f[MAX][MAX],s[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>st;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>v[i];
        s[i]=s[i-1]+v[i];
    }
    memset(f,0x3f,sizeof f);
    f[st][st]=0;
    for(int len=2;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            LL a=(p[j]-p[j-1])*(s[i-1]-s[j-1]+s[n]),b=(p[j]-p[i])*(s[i-1]-s[j-1]+s[n]);
            f[i][j]=min(f[i][j-1]+a,f[j-1][i]+b);
            a=(p[j]-p[i])*(s[i]-s[j]+s[n]),b=(p[i+1]-p[i])*(s[i]-s[j]+s[n]);
            f[j][i]=min(f[i+1][j]+a,f[j][i+1]+b);
        }
    cout<<min(f[1][n],f[n][1])<<'\n';
    return 0;
}