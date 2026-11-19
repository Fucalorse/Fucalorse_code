#include <bits/stdc++.h>
using namespace std;

const int MAX=2090,LEN=5000,mod=998244353;

int t,n;
int a[MAX],f[LEN+90][LEN+90];

void create()
{
    f[1][0]=f[1][1]=1;
    for(int i=2;i<=LEN;i++)
    {
        f[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            f[i][j]=f[i-1][j]+f[i-1][j-1];
            f[i][j]%=mod;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    create();
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(abs(2*a[i-1]-a[i])>abs(2*a[1]-a[i])) ans=(ans+f[a[i]][a[i-1]])%mod;
            else ans=(ans+f[a[i]][a[1]])%mod;
        }
        cout<<ans<<'\n';
    }
    return 0;
}