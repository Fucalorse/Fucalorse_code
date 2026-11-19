#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;
const LL inf=9e18;

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
        LL get(int n) { return num[n-1]; }
        int find(LL n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }
        int size() { return num.size(); }
};

struct qwq
{
    int cnt;
    LL sum;
    qwq operator-(const qwq &a)const { return {cnt-a.cnt,sum-a.sum}; }
    qwq operator+(const qwq &a)const { return {cnt+a.cnt,sum+a.sum}; }
};

struct peach
{
    private:
        int size;
        vector<qwq>op;
    public:
        peach(int n) { size=n,op.assign(n+3,{0,0}); }
        void update(int n,LL x)
        {
            while(n<=size)
            {
                op[n].cnt++;
                op[n].sum+=x;
                n+=n&-n;
            }
        }
        qwq query(int n)
        {
            qwq now={0,0};
            while(n)
            {
                now=now+op[n];
                n-=n&-n;
            }
            // cout<<now.sum<<' '<<now.cnt<<endl;
            return now;
        }
        qwq get(int n) { return query(size)-query(n); }
};

int t,n;
LL x,y,k;
LL a[MAX];

void solve()
{
    cin>>n>>x>>y>>k;
    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dis.add(a[i]);
    }

    LL minn=inf;
    dis.create();
    peach fu(dis.size());
    for(int i=1;i<=n;i++)
    {
        auto get=[&](LL h,LL p) { return h>=p?x:-y; };
        auto cal=[&](const int &mid)
        {
            LL h=dis.get(mid);
            LL ans=get(h,a[1]);
            if(i>1) ans+=get(h,a[i]);
            qwq now=fu.get(mid);
            ans-=now.cnt*y;
            return ans;
        };

        int l=1,r=dis.size();
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(cal(mid)>=0) r=mid-1;
            else l=mid+1;
        }
        
        auto get_ans=[&](int pos)
        {
            if(pos<1||pos>dis.size()) return inf;
            LL h=dis.get(pos);
            qwq now=fu.get(pos);
            LL ans=max(x*(h-a[1]),y*(a[1]-h));
            if(i>1) ans+=max(x*(h-a[i]),y*(a[i]-h));
            ans+=y*(now.sum-now.cnt*h);
            return ans+(n-i)*k;
        };

        minn=min({minn,get_ans(l),get_ans(r)});
        if(i>1) fu.update(dis.find(a[i]),a[i]);
    }
    cout<<minn<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}