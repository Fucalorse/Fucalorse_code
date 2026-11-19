#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    int ans=-INF;
    for(int k=0;k<=n;k++)
    {
        vector<int>dp(k+1,-INF),ndp(k+1,-INF);
        dp[0]=0;

        for(int i=1;i<=n;i++)
        {
            fill(ndp.begin(),ndp.end(),-INF);

            if(s[i]=='N'||s[i]=='T')
            {
                for(int j=0;j<=k;j++)
                    if(dp[j]!=-INF) ndp[max(0,j-1)]=max(ndp[max(0,j-1)],dp[j]);
            }
            
            if(s[i]=='N'||s[i]=='F')
            {
                for(int j=0;j<k;j++)
                    if(dp[j]!=-INF) ndp[j+1]=max(ndp[j+1],dp[j]+1);
            }

            swap(dp,ndp);
        }

        int maxn=*max_element(dp.begin(),dp.end());
        ans=max(ans,maxn-k);
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