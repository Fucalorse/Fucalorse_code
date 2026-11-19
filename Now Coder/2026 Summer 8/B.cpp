#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n,m;
int a[MAX];

void solve()
{
    cin>>n>>m;

    int maxn=-INF;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }

    if(maxn>2*n-1)
    {
        cout<<0<<endl;
        return;
    }
    
    vector<bool>vis(2*n+1,false);
    vector<LL>dp(n+1,0);
    dp[0]=1;

    for(int i=1;i<=m;i++)
        vis[a[i]]=true;

    for(int x=1;x<=2*n-1;x++)
    {
        vector<LL>ndp(n+1,0);

        if(vis[x])
        {
            for(int k=1;k<=n;k++)
                if(x<=2*k-1) ndp[k]=(ndp[k]+dp[k-1])%MOD;
        }
        else
        {
            for(int k=1;k<=n;k++)
            {
                ndp[k]=(ndp[k]+dp[k])%MOD;
                if(k&&x<=2*k-1) ndp[k]=(ndp[k]+dp[k-1])%MOD;
            }
        }

        swap(dp,ndp);
    }

    cout<<dp[n]<<endl;
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