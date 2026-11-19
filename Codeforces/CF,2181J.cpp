#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;
const double EPS=1e-7;

template <typename T>
T qpow(T a,LL p)
{
    T ans=1;
    while(p)
    {
        if(p&1) ans=ans*a;
        a=a*a;
        p>>=1;
    }
    return ans;
}

int n,k;

int sgn(double x)
{
    if(fabs(x)<=EPS) return 0;
    if(x>EPS) return 1;
    else return -1;
}

void solve()
{
    cin>>n>>k;

    vector<int>cnt(101,0);
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        ++cnt[p];
    }

    vector<vector<double>>dp(k+1,vector<double>(k+1,-INF)),ndp(k+1,vector<double>(k+1,-INF));
    for(int win=0;win<=k;++win)
    {
        int lose=k-win;
        double now=0;
        for(int i=0;i<=100;i++)
        {
            if(cnt[i]==0) continue;
            double p=1.00*i/100;
            now+=1.00*cnt[i]*qpow(p,win)*qpow(1-p,lose)/n;
        }
        dp[win][lose]=now;
    }

    for(int round=k-1;round>=0;round--)
    {
        for(int i=0;i<=k;i++)
            fill(ndp[i].begin(),ndp[i].end(),-INF);

        for(int win=0;win<=round;win++)
        {
            int lose=round-win;
            ndp[win][lose]=max(dp[win+1][lose]+dp[win][lose+1],2*dp[win+1][lose]);
        }
        swap(dp,ndp);
    }

    cout<<fixed<<setprecision(20);
    cout<<1000*(dp[0][0]-1)<<endl;
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