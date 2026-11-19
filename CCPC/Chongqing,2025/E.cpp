#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'
const int MAX= 1e5+90,INF=2e9,LEN=20;
const LL LINF=3e18;

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

        int upper(LL n) { return upper_bound(num.begin(),num.end(),n)-num.begin(); }

        LL get(int pos) { return num[pos-1]; }

        int size() { return (int)num.size(); }
};

struct fucalorse
{
    private:
        int n;
        vector<LL>op;
    public:
        fucalorse(int _n):n(_n),op(_n+5,0LL){}

        void update(int pos,LL k)
        {
            for(int i=pos;i<=n;i+=i&-i)
                op[i]+=k;
        }

        LL query(int pos)
        {
            LL ans=0;
            for(int i=pos;i;i-=i&-i)
                ans+=op[i];
            return ans;
        }

        LL query_range(int l,int r) { return query(r)-query(l-1); }

        int find(LL target_cnt)
        {
            int pos=0;
            LL cnt=0;
            for(int k=LEN;k>=0;k--)
            {
                int npos=pos|1<<k;
                if(npos<=n&&cnt+op[npos]<target_cnt)
                {
                    cnt+=op[npos];
                    pos=npos;
                }
            }
            return pos+1;
        }
};

struct qwq
{
    LL w,r;
    bool operator<(const qwq &a)const
    {
        if(r!=a.r) return r<a.r;
        return w<a.w;
    }
}op[MAX];

int n;

void solve()
{
    cin>>n;

    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].w;
        dis.add(op[i].w);
    }
    for(int i=1;i<=n;i++)
        cin>>op[i].r;

    dis.create();
    sort(op+1,op+n+1);

    int ans=0;
    fucalorse cnt(dis.size()),sum(dis.size());

    for(int i=n;i>=1;i--)
    {
        const auto [cur_w,cur_r]=op[i];
        int st=cnt.query(dis.upper(cur_r));
        int l=st,r=n-i;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int pos=cnt.find(mid);
            int rest=cnt.query(pos)-mid;
            if(cur_w+sum.query(pos)-1LL*rest*dis.get(pos)-1LL*(mid+1)*cur_r<=0) l=mid+1;
            else r=mid-1;
        }

        if(r>=st) ans=max(ans,r+1);
        int pos=dis.find(cur_w);
        cnt.update(pos,1);
        sum.update(pos,cur_w);
    }

    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ E.cpp -O2 -o out && ./out < in.txt