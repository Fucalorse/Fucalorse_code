#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5090,MOD=998244353,LEN=5000;
const LL INF=1e18;  

int T,n;
int a[MAX];
LL pow_2[MAX];

vector<LL> cal_l(int maxn)
{
    int pos=-1;
    vector<int>st;
    st.push_back(-10086);

    for(int i=1;i<=n;i++)
    {
        if(st.size()&&st.back()>=a[i]) continue;

        if(a[i]!=maxn) st.push_back(a[i]);
        if(a[i]==maxn&&pos==-1)
        {
            pos=i;
            break;
        }
    }

    int len=st.size()-1;
    vector<vector<LL>>dp(n+1,vector<LL>(len+1,0));
    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        dp[i][0]=1;

        for(int j=1;j<=len;j++)
        {
            dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;

            if(a[i]<=st[j]) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            if(a[i]==st[j]) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;
        }
    }

    vector<LL>pre(n+1,0);
    pre[0]=1;
    for(int i=1;i<=n;i++)
        pre[i]=dp[i][len];

    return pre;
}

vector<LL> cal_r(int maxn)
{
    int pos=-1;
    vector<int>st;
    st.push_back(-10086);

    for(int i=n;i>=1;i--)
    {
        if(st.size()&&st.back()>=a[i]) continue;

        if(a[i]!=maxn) st.push_back(a[i]);
        if(a[i]==maxn&&pos==-1)
        {
            pos=i;
            break;
        }
    }

    int len=st.size()-1;
    vector<vector<LL>>dp(n+3,vector<LL>(len+1,0));
    dp[n+1][0]=1;

    for(int i=n;i>=1;i--)
    {
        dp[i][0]=1;

        for(int j=1;j<=len;j++)
        {
            dp[i][j]=(dp[i][j]+dp[i+1][j])%MOD;

            if(a[i]<=st[j]) dp[i][j]=(dp[i][j]+dp[i+1][j])%MOD;
            if(a[i]==st[j]) dp[i][j]=(dp[i][j]+dp[i+1][j-1])%MOD;
        }
    }

    vector<LL>suf(n+3,0);
    suf[n+1]=1;
    for(int i=n;i>=1;i--)
        suf[i]=dp[i][len];

    return suf;
}

void solve()
{
    cin>>n;

    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }

    if(n==1)
    {
        cout<<1<<endl;
        return;
    }

    vector<int>id;
    vector<LL>pre=cal_l(maxn),suf=cal_r(maxn);
    for(int i=1;i<=n;i++)
        if(a[i]==maxn) id.push_back(i);

    // for(auto &cur:pre)
    //     cout<<cur<<' ';
    // cout<<endl;
    // for(auto &cur:suf)
    //     cout<<cur<<' ';
    // cout<<endl;

    LL ans=0;
    int len=id.size();
    for(int i=0;i<len;i++)
    {
        int l=id[i];
        ans=(ans+pre[l-1]*suf[l+1]%MOD)%MOD;

        for(int j=i+1;j<len;j++)
        {
            int r=id[j];
            int mid_len=r-l-1;

            ans=(ans+pre[l-1]*suf[r+1]%MOD*pow_2[mid_len]%MOD)%MOD;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    pow_2[0]=1;
    for(int i=1;i<=LEN;i++)
        pow_2[i]=pow_2[i-1]*2%MOD;

    cin>>T;
    while(T--) solve();

    return 0;
}