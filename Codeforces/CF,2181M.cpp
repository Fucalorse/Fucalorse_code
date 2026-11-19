#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

string a,b;

void solve()
{
    cin>>a>>b;a=' '+a,b=' '+b;
    int n=a.size()-1;

    int dp[2]={INF,INF};
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int ndp[2]={INF,INF};
        int sa=a[i]-'0',sb=b[i]-'0';
        for(int col=0;col<=1;col++)
        {
            if(dp[col]==INF) continue;
            int ncol=(col+sa)&1;
            if(ncol!=sb)
            {
                ndp[ncol]=min(ndp[ncol],dp[col]+1);
                ndp[ncol^1]=min(ndp[ncol^1],dp[col]+1);
            }
            else
            {
                ndp[ncol]=min(ndp[ncol],dp[col]);
                ndp[ncol^1]=min(ndp[ncol^1],dp[col]+1);
            }
        }

        memcpy(dp,ndp,sizeof(ndp));
    }

    cout<<min(dp[0],dp[1])<<endl;
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