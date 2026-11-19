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
    bool operator<(const point &a)const
    {
        if(x!=a.x) return x<a.x;
        else return y>a.y;
    }
};

struct peach
{
    private:
        int size;
        vector<LL>op;
    public:
        peach(int _n) { size=_n,op.assign(size+3,0LL); }

        void clear()
        {
            for(int i=1;i<=size;i++)
                op[i]=0;
        }

        void update(int n,LL k)
        {
            while(n<=size)
            {
                op[n]+=k;
                n+=n&-n;
            }
        }

        LL query_pre(int n)
        {
            LL ans=0;

            while(n)
            {
                ans+=op[n];
                n-=n&-n;
            }

            return ans;
        }

        LL query_suf(int n) { return query_pre(size)-query_pre(n); }
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

    sort(op.begin(),op.end());
    int len=op.size();
    peach fu(dis.size());

    for(int i=0;i<len;i++)
    {
        ans+=fu.query_pre(op[i].y-1);
        fu.update(op[i].y,1);
    }

    for(int i=2;i<=n-2;i++)
    {
        LL now=1LL*(a[i]-a[i+1])*(f[i]-f[i+1]);
        if(now>0) --ans;
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