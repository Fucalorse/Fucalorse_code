#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

struct discrete
{
    private:
        vector<LL>num;
    public:
        void add(LL val) { num.push_back(val); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(LL val) { return lower_bound(num.begin(),num.end(),val)-num.begin()+1; }

        int size() { return num.size(); }
};

struct peach
{
    private:
        int size;
        vector<int>op;
    public:
        peach(int n) { size=n,op.assign(n+4,0); }

        void update(int n,int k)
        {
            while(n<=size)
            {
                op[n]+=k;
                n+=n&-n;
            }
        }

        int query(int n)
        {
            int ans=0;

            while(n)
            {
                ans+=op[n];
                n-=n&-n;
            }

            return ans;
        }
};

int T,n;
LL a[MAX],sum[MAX];

void solve()
{
    cin>>n;

    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        sum[i]=sum[i-1]+a[i]*(i&1?1:-1);
        dis.add(sum[i]);
    }
    dis.add(sum[0]);

    // for(int i=1;i<=n;i++)
    //     cout<<sum[i]<<' ';
    // cout<<endl;

    dis.create();
    peach even(dis.size()),odd(dis.size());
    even.update(dis.find(sum[0]),1);
    LL ans=0;

    for(int i=1;i<=n;i++)
    {
        if(i&1)
        {
            ans+=even.query(dis.find(sum[i])-1);
            odd.update(dis.find(sum[i]),1);
        }
        else
        {
            ans+=odd.query(dis.size())-odd.query(dis.find(sum[i]));
            even.update(dis.find(sum[i]),1);
        }
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