#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=1e9+7,INF=2e9;

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

const vector<vector<int>>bad={{},
{0,3,9,27,81,243,729,2187,6561,19683},
{0,9,66,390,1800,6120,13680,15120,0,0},
{0,27,390,3198,13176,27000,13680,15120,0,0},
{0,81,1800,13176,24336,4320,0,0,0,0},
{0,243,6120,27000,4320,4320,0,0,0,0},
{0,729,13680,13680,0,0,0,0,0,0},
{0,2187,15120,15120,0,0,0,0,0,0},
{0,6561,0,0,0,0,0,0,0,0},
{0,19683,0,0,0,0,0,0,0,0}
};

int n,m;

void solve()
{
    cin>>n>>m;
    
    if(n==1||m==1)
    {
        cout<<0<<endl;
        return;
    }

    if(max(n,m)>9) cout<<qpow(3,n*m)<<endl;
    else
    {
        LL ans=qpow(3,n*m)-bad[n][m];
        // cout<<bad[n][m]<<endl;
        cout<<(ans%MOD+MOD)%MOD<<endl;
    }
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