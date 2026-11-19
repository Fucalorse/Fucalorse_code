#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int a[MAX];

vector<int> cal_l()
{
    vector<int>st,dp(n+1);
    for(int i=1;i<=n;i++)
    {
        while(st.size()&&a[i]>a[st.back()]) st.pop_back();
        st.push_back(i);
        dp[i]=st.size();
    }
    return dp;
}

vector<int> cal_r()
{
    vector<int>st,dp(n+1);
    for(int i=n;i>=1;i--)
    {
        while(st.size()&&a[i]>a[st.back()]) st.pop_back();
        st.push_back(i);
        dp[i]=st.size();
    }
    return dp;
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<int>L=cal_l(),R=cal_r();
    int remain=0;
    for(int i=1;i<=n;i++)
    {
        int now=L[i]+R[i]-1;
        remain=max(remain,now);
    }

    // for(int i=1;i<=n;i++)
    //     cout<<R[i]<<' ';
    // cout<<endl;

    cout<<n-remain<<endl;
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