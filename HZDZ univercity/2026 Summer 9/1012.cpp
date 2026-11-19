#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'
const int MAX=1e5+5,LEN=32,INF=2e9;

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

        int size() { return (int)num.size(); }
};

struct point
{
    int x,y;
};

struct peach
{
    private:
        int n;
        vector<vector<int>>pos;
        vector<vector<LL>>tree;
    public:
        peach(int _n,const vector<point>& op)
        {
            n=_n;
            pos.assign(n+1,vector<int>{});
            tree.assign(n+1,vector<LL>{});

            for(auto &[x,y]:op)
                for(int i=x;i<=n;i+=i&-i)
                    pos[i].push_back(y);

            for(int i=1;i<=n;i++)
            {
                sort(pos[i].begin(),pos[i].end());
                pos[i].erase(unique(pos[i].begin(),pos[i].end()),pos[i].end());
                tree[i].assign((int)pos[i].size()+1,0);
            }
        }

        void clear()
        {
            for(auto &vec:tree)
                for(auto &cur:vec)
                    cur=0;
        }

        void update(int x,int y,int k)
        {
            for(int i=x;i<=n;i+=i&-i)
            {
                int rank=lower_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin()+1;

                for(int j=rank;j<(int)tree[i].size();j+=j&-j)
                    tree[i][j]+=k;
            }
        }

        LL query(int x,int y)
        {
            LL ans=0;

            for(int i=x;i;i-=i&-i)
            {
                int rank=upper_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin();

                for(int j=rank;j;j-=j&-j)
                    ans+=tree[i][j];
            }

            return ans;
        }
};

int n;
int a[MAX],f[MAX];

LL cal(LL x) { return x*x; }

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[0]=a[1],a[n+1]=a[n];

    if(n<=2)
    {
        cout<<0<<endl;
        return;
    }

    LL ans=0;
    discrete dis;

    //not adjacent
    vector<point>op;
    for(int i=2;i<n;i++)
    {
        f[i]=a[i-1]+a[i+1];
        dis.add(f[i]),dis.add(a[i]);
    }
    dis.create();

    for(int i=2;i<n;i++)
    {
        int x=dis.find(a[i]),y=dis.find(f[i]);
        op.push_back({x,y});
    }

    int len=op.size();
    peach fu(dis.size(),op);
    for(int i=0;i<len;i++)
    {
        ans+=fu.query(op[i].x-1,op[i].y-1);
        if(i-1>=0) fu.update(op[i-1].x,op[i-1].y,1);
    }

    fu.clear();
    reverse(op.begin(),op.end());

    for(int i=0;i<len;i++)
    {
        ans+=fu.query(op[i].x-1,op[i].y-1);
        if(i-1>=0) fu.update(op[i-1].x,op[i-1].y,1);
    }

    //adjacent
    for(int i=2;i<=n-2;i++)
    {
        LL pre=cal(a[i-1]-a[i])+cal(a[i+2]-a[i+1]);
        LL now=cal(a[i+1]-a[i-1])+cal(a[i+2]-a[i]);
        if(now>pre) ++ans;
    }

    //begin
    LL pre1=cal(a[3]-a[2]),now1=cal(a[3]-a[1]);
    if(now1>pre1) ++ans;

    for(int i=3;i<n;i++)
    {
        LL pre=cal(a[2]-a[1])+cal(a[i]-a[i-1])+cal(a[i+1]-a[i]);
        LL now=cal(a[2]-a[i])+cal(a[1]-a[i-1])+cal(a[i+1]-a[1]);
        // cout<<i<<' '<<pre<<' '<<now<<endl;
        if(now>pre) ++ans;
    }

    //end
    LL pre2=cal(a[n-1]-a[n-2]),now2=cal(a[n]-a[n-2]);
    if(now2>pre2) ++ans;

    for(int i=2;i<=n-2;i++)
    {
        LL pre=cal(a[n]-a[n-1])+cal(a[i]-a[i-1])+cal(a[i+1]-a[i]);
        LL now=cal(a[i]-a[n-1])+cal(a[n]-a[i-1])+cal(a[i+1]-a[n]);
        if(now>pre) ++ans;
    }

    LL pre3=cal(a[2]-a[1])+cal(a[n]-a[n-1]),now3=cal(a[2]-a[n])+cal(a[1]-a[n-1]);
    if(now3>pre3) ++ans;

    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

// g++ 1012.cpp -o out && ./out < in.txt