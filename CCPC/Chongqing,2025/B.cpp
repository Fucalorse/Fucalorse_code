#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1090,LEN=32,G=3,MOD=1e9+7,INF=2e9;
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

vector<vector<LL>> merge(const vector<vector<LL>>& a,const vector<vector<LL>>& b)
{
    int n=a.size();
    vector<vector<LL>>ans(n,vector<LL>(n,0LL));

    for(int i=0;i<n;i++)
        for(int k=0;k<n;k++)
        {
            if(a[i][k]==0) continue;
            for(int j=0;j<n;j++)
            {
                if(b[k][j]==0) continue;
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%MOD;
            }
        }
    return ans;
}

vector<vector<LL>> multiply(vector<vector<LL>>a,LL p)
{
    int n=a.size();
    vector<vector<LL>>ans(n,vector<LL>(n,0LL));
    for(int i=0;i<n;i++)
        ans[i][i]=1;
    while(p)
    {
        if(p&1) ans=merge(ans,a);
        a=merge(a,a);
        p>>=1;
    }
    return ans;
}

int n,k;
int t[MAX];
LL dp[MAX];

void solve()
{
    cin>>n>>k;

    int maxt=0;
    for(int i=1;i<=k-1;i++)
    {
        cin>>t[i];
        maxt=max(maxt,t[i]);
    }

    for(int i=1;i<=maxt;i++)
    {
        dp[i]=dp[i-1]+1;
        for(int j=1;j<=k-1;j++)
            if(i-1>=t[j])
            {
                LL now=1+dp[i-1]-dp[i-1-t[j]];
                dp[i]=(dp[i]+now)%MOD;
            }
        dp[i]=(dp[i]+MOD)%MOD;
        // cout<<dp[i]<<' ';
    }
    // cout<<endl;

    int m=maxt+2;
    vector<vector<LL>>a(m,vector<LL>(m,0LL));
    a[0][0]=k,a[m-1][m-1]=1,a[0][m-1]=k;
    for(int i=1;i<m-1;i++)
        a[i][i-1]=1;
    for(int i=1;i<=k-1;i++)
        a[0][t[i]]=(a[0][t[i]]-1+MOD)%MOD;

    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<m;j++)
    //         cout<<a[i][j]<<' ';
    //     cout<<endl;
    // }

    LL ans=0;
    vector<vector<LL>>op=multiply(a,n-maxt);
    for(int i=0;i<m-1;i++)
        ans=(ans+op[0][i]*dp[maxt-i]%MOD)%MOD;
    ans=(ans+op[0][m-1])%MOD;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}