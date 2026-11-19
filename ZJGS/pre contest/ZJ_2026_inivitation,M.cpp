#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e5+90,mod=1e9+7;

int n;
vector<vector<int>>f;
string s;

int cal(const int &x)
{
    double ans=(-3.0+sqrt(9+8*x))/2;
    return (int)ans;
}

int main()
{
    cin>>n>>s;
    s=" "+s;
    int len=sqrt(n*2);
    f.assign(n+5,vector<int>(len+5,0));
    f[1][0]=1;
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        if(s[i]=='#') continue;
        int k=cal(i);
        for(int j=0;j<=k;j++)
        {
            int x=j+1;
            if(s[i-1]!='#') f[i][j]=(f[i][j]+f[i-1][j])%mod;
            if(j&&s[i-x]!='#') f[i][j]=(f[i][j]+f[i-x][j-1])%mod;
            // cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
            if(i+j+2>n) ans=(ans+f[i][j])%mod;
            if(i==n) ans=(ans+f[i][j])%mod;
        }
    }
    if(n==1) ans=(ans+1)%mod;
    if(1+2>n) ans=(ans+1)%mod;
    cout<<ans<<endl;
    return 0;
}