#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=18,INF=2e9;

struct peach
{
    private:
        int size;
        vector<LL>op;
    public:
        peach(int n)
        {
            size=n;
            op.assign(n+5,0);
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

struct qwq
{
    int val,cnt;
    bool operator<(const qwq &a)const { return val<a.val; }
}op[MAX];

int n;
int a[MAX],cnt[MAX];

void solve()
{
    cin>>n;

    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        maxn=max(maxn,a[i]);
        ++cnt[a[i]];
    }

    int m=0;
    for(int i=1;i<=maxn;i++)
        if(cnt[i]) op[++m]={i,cnt[i]};

    vector<LL>dp(m+3,0);
    peach fu(maxn);
    for(int i=1;i<=m;i++)
    {
        LL now=fu.query(max(0,op[i].val-2));

        dp[i]=max(dp[i],now+1LL*op[i].cnt*op[i].val);
        fu.update(op[i].val,dp[i]);
    }

    // for(int i=1;i<=m;i++)
    //     cout<<dp[i]<<' ';
    // cout<<endl;

    LL ans=0;
    for(int i=1;i<=m;i++)
        ans=max(ans,dp[i]);

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}