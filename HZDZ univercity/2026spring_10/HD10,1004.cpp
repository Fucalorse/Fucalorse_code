#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

struct discrete
{
    private:
        vector<int>num;
    public:
        void add(int n) { num.push_back(n); }
        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }
        int find(int n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }
        int size() { return num.size(); }
};

struct peach
{
    private:
        int size;
        vector<int>op;
    public:
        peach(int n) { size=n,op.assign(n+3,0); }
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

struct qwq
{
    int l,r;
    bool operator<(const qwq &a)const { return l<a.l; }
}op[MAX];

int t,L,n,m;
int a[MAX],dp[MAX];

void solve()
{
    cin>>L>>n>>m;
    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].l>>op[i].r;
        dis.add(op[i].l),dis.add(op[i].r);
        dp[i]=0;
    }
    for(int i=1;i<=m;i++)
        cin>>a[i];
    sort(a+1,a+m+1);

    vector<qwq>rest;
    rest.push_back({-1,-1});
    for(int i=1;i<=n;i++)
    {
        int l=lower_bound(a+1,a+m+1,op[i].l)-a,r=upper_bound(a+1,a+m+1,op[i].r)-a;
        if(r-l) rest.push_back(op[i]);
    }
    sort(rest.begin(),rest.end());

    int ans=0;
    dis.create();
    peach fu(dis.size());
    for(size_t i=1;i<rest.size();i++)
    {
        // int pos=dis.find(rest[i].l)-1;
        // cout<<pos<<' ';
        dp[i]=rest[i].r-rest[i].l+1+fu.query(dis.find(rest[i].l)-1);
        // pos=dis.find(rest[i].r);
        // cout<<pos<<endl;
        fu.update(dis.find(rest[i].r),dp[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}