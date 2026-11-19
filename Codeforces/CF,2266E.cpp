#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=2e5,G=3,MOD=998244353;
const LL INF=1e18;

int minp[MAX];
vector<int>op;
vector<vector<int>>num;

void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }

    auto split=[&](int num)
    {
        set<int>st;
        while(num!=1)
        {
            st.insert(minp[num]);
            num/=minp[num];
        }
        return st;
    };

    num.assign(n+1,vector<int>{});
    for(int i=2;i<=n;i++)
    {
        set<int>st=split(i);
        for(auto &cur:st)
            num[i].push_back(cur);
    }
}

int n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<LL>dp(n+1,INF);

    for(int x=1;x<=k;x++)
        dp[x]=0LL;

    for(int x=k+1;x<=n;x++)
        for(auto &prime:num[x])
        {
            int pre=x/prime;
            dp[x]=min(dp[x],prime*dp[pre]+1);
        }

    LL ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[a[i]];

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}