#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90;

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
}dis;

struct peach
{
    private:
        vector<int>op;
        int size;
    public:
        peach(int n) { size=n,op.assign(n+3,0); }
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

struct qwq
{
    LL a,b;
}op[MAX];

bool cmp1(const qwq &a,const qwq &b) { return a.b<b.b; }
bool cmp2(const qwq &a,const qwq &b) { return a.a<b.a; }

vector<qwq>down,up;

int n;
int dp[MAX],pre[MAX];

void solve()
{
    cin>>n;
    up.push_back({-1,-1});
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].a>>op[i].b;
        if(op[i].a>=op[i].b) down.push_back(op[i]);
        else up.push_back(op[i]);
        dis.add(op[i].b),dis.add(op[i].a);
    }
    dis.create();
    sort(up.begin()+1,up.end(),cmp1);
    sort(down.begin(),down.end(),cmp2);
    int m=up.size()-1;
    for(int i=2;i<=m;i++)
    {
        int l=1,r=i-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(up[mid].b>up[i].a) r=mid-1;
            else l=mid+1;
        }
        pre[i]=r;
    }

    // for(int i=1;i<=m;i++)
    //     cout<<up[i].a<<' '<<up[i].b<<' '<<pre[i]<<endl;

    // for(auto &[a,b]:down)
    //     cout<<a<<' '<<b<<endl;

    peach fu(dis.size());
    int total=0,len=down.size();
    for(int i=1,j=0;i<=m;i++)
    {
        while(j<len&&down[j].a<up[i].b)
        {
            // cout<<down[j].b<<' '<<dis.find(down[j].b)<<endl;
            fu.update(dis.find(down[j].b),1);
            ++j;
            ++total;
        }
        dp[i]=max(dp[i-1],1-(total-fu.query(dis.find(up[i].a)))+dp[pre[i]]);
        // cout<<i<<"::"<<dp[i]<<' '<<total-fu.query(dis.find(up[i].a));
        // cout<<' '<<len+1-(total-fu.query(dis.find(up[i].a)))<<endl;
        // cout<<total-fu.query(dis.find(up[i].a))<<' ';
    }
    cout<<dp[m]+len<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}