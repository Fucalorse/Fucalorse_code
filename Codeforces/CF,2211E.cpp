#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

template <typename T>
T __lcm(T a,T b) { return a/__gcd(a,b)*b; }

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    vector<LL>dp(n+1,0);
    vector<i128>lcm(n+1,1);
    for(int i=n;i>=1;i--)
    {
        int k;
        cin>>a[i]>>k;
        i128 val=a[i];

        if(!k)
        {
            dp[i]=1;
            lcm[i]=val;
        }
        else
        {
            for(int round=1;round<=k;round++)
            {
                int ch;
                cin>>ch;
                lcm[i]=__lcm(lcm[i],__gcd(lcm[ch],val));
                dp[i]+=dp[ch];
            }

            if(lcm[i]==1)
            {
                ++dp[i];
                lcm[i]=val;
            }
        }

        cout<<dp[i]<<endl<<flush;
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