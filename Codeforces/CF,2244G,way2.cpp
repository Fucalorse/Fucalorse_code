#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

struct peach
{
    private:
        int size;
        vector<LL>op;
    public:
        peach(int n)
        {
            size=n;
            op.assign(n+3,0);
        }

        void update(int n,LL k)
        {
            while(n<=size)
            {
                op[n]=max(op[n],k);
                n+=n&-n;
            }
        }

        LL query(int n)
        {
            LL ans=0;

            while(n)
            {
                ans=max(ans,op[n]);
                n-=n&-n;
            }

            return ans;
        }
};

int T,n;
int a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    LL ans=0;
    vector<LL>dp(n+1,0);
    vector<vector<pair<int,LL>>>bucket(n+1);
    peach fu(n);

    for(int i=1;i<=n;i++)
    {
        for(auto &[id,val]:bucket[i])
            fu.update(id,val);

        dp[i]=max(dp[i],fu.query(max(0,i-a[i]-1))+a[i]);
        if(i+a[i]+1<=n) bucket[i+a[i]+1].push_back({i,dp[i]});

        ans=max(ans,dp[i]);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}