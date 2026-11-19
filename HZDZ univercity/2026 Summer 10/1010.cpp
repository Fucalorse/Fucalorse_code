#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

struct peach
{
    private:
        int size;
        vector<int>op;
    public:
        peach(int _n) { size=_n,op.assign(size+3,0); }

        void update(int n,int k)
        {
            while(n<=size)
            {
                op[n]=max(op[n],k);
                n+=n&-n;
            }
        }

        int query(int n)
        {
            int ans=0;

            while(n)
            {
                ans=max(ans,op[n]);
                n-=n&-n;
            }

            return ans;
        }
};

int n,m;
int a[MAX],b[MAX],revb[MAX];

void solve()
{
    cin>>n>>m;
    int len=n*m;

    map<int,int>pos;
    for(int i=1;i<=len;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }

    for(int i=1;i<=len;i++)
    {
        cin>>b[i];
        revb[i]=pos[b[i]];
    }

    peach fu(len);
    vector<int>dp(len+3,0);

    int ans=0;
    for(int i=1;i<=len;i++)
    {
        dp[i]=fu.query(revb[i]-1)+1;
        fu.update(revb[i],dp[i]);
        ans=max(ans,dp[i]);
    }

    cout<<len-ans<<endl;
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