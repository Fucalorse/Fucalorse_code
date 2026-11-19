#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

LL qpow(LL a,LL p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ans;
}

int n;
int f[MAX];
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        if(s[i]=='(') ++f[i];
        else --f[i];
    }

    LL ans=0,left=0,right=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')
        {
            LL now=qpow(2,i-1);
            ans=(ans+now)%MOD;
            left=(left*2+right+1)%MOD;
        }
        else
        {
            LL now=left+right+1;
            ans=(ans+now)%MOD;
            right=(right*2+left+1)%MOD;
        }

        if(f[i]<2) left=0;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}