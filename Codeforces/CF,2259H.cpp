#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=1e9+7,INF=2e9;

int n;
int b[MAX];

void solve()
{
    cin>>n;

    vector<int>f(n+3,0);
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]>0)
        {
            int l=max(1,i-b[i]+1),r=min(n,i+b[i]-1);
            ++f[l],--f[r+1];
        }
    }

    for(int i=1;i<=n;i++)
        f[i]+=f[i-1];

    vector<bool>must(n+3,false),choose_one(n+3,false);

    for(int i=1;i<=n;i++)
    {
        if(b[i]>=0)
        {
            int l=i-b[i],r=i+b[i],cnt=0;
            bool have_zero=false;

            if(l>=1&&!f[l])
            {
                ++cnt;
                if(b[l]==0) have_zero=true;
            }
            if(r<=n&&!f[r])
            {
                ++cnt;
                if(b[r]==0) have_zero=true;
            }

            if(!cnt)
            {
                cout<<0<<endl;
                return;
            }

            if(cnt==1)
            {
                if(l>=1&&!f[l]) must[l]=true;
                else must[r]=true;
            }
            else if(!have_zero) choose_one[r]=true;
        }
    }

    vector<vector<LL>>dp(n+3,vector<LL>(2,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>=0||(b[i]==-1&&f[i]>0))
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            continue;
        }

        dp[i][1]=(dp[i-1][0]+dp[i-1][1])%MOD;
        if(!must[i])
        {
            if(choose_one[i]) dp[i][0]=dp[i-1][1];
            else dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
        }
    }

    bool all_neg=true;
    for(int i=1;i<=n;i++)
        if(b[i]>=0)
        {
            all_neg=false;
            break;
        }

    LL ans=(dp[n][0]+dp[n][1])%MOD;
    if(all_neg) ans=(ans-1+MOD)%MOD;

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