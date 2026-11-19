#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct peach
{
    private:
        int n;
        vector<int>op;
    public:
        peach(int _n) { n=_n,op.assign(n+3,0); }

        void update(int pos,int k)
        {
            for(int i=pos;i<=n;i+=i&-i)
                op[i]=max(op[i],k);
        }

        int query(int pos)
        {
            int ans=0;
            for(int i=pos;i;i-=i&-i)
                ans=max(ans,op[i]);
            return ans;
        }
};

int n,m;
int a[MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<int>dp(n+1,0),pre(n+1,0),f(n+1,0);
    peach fu(n);

    for(int i=1;i<=n;i++)
    {
        int pos=i-a[i]+1;
        if(pos>=1&&pos<=n-m+1)
        {
            dp[i]=max(dp[i],pre[pos-1]+1);
            if(i-m>=1) dp[i]=max(dp[i],fu.query(i-m)+1);
            if(pos<i) dp[i]=max(dp[i],f[pos]+1);
            f[pos]=max(f[pos],dp[i]);
            fu.update(pos,dp[i]);
        }
        pre[i]=max(pre[i-1],dp[i]);
    }

    cout<<n-pre[n]<<endl;
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