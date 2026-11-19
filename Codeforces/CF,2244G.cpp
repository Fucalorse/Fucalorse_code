#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

struct discrete
{
    private:
        vector<LL>num;
    public:
        void add(LL n) { num.push_back(n); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(LL n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }

        int size() { return num.size(); }
};

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

struct qwq
{
    int id;
    LL pos,val;
    bool operator<(const qwq &a)const { return pos>a.pos; }
};

int T,n;
LL a[MAX];

void solve()
{
    cin>>n;

    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dis.add(i-a[i]);
        dis.add(i);
    }
    dis.create();

    LL ans=0;
    peach fu(dis.size());
    vector<LL>dp(n+1,0);
    priority_queue<qwq>q;

    for(int i=1;i<=n;i++)
    {
        while(q.size()&&q.top().pos<i)
        {
            auto [id,pos,val]=q.top();q.pop();
            fu.update(dis.find(id),val);
        }

        dp[i]=max(dp[i],fu.query(dis.find(i-a[i])-1)+a[i]);
        q.push({i,i+a[i],dp[i]});
        // cout<<dp[i]<<' ';

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