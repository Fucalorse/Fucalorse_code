#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+10,LEN=2e5,MOD=1e9+7,INF=2e9;

template <typename T>
struct discrete
{
    private:
        vector<T>num;
    public:
        void add(T n) { num.push_back(n); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(T n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }

        int lower_rank(T n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }
        int upper_rank(T n) { return upper_bound(num.begin(),num.end(),n)-num.begin(); }

        int size() { return (int)num.size(); }
};

struct Segment
{
    private:
        struct qwq
        {
            int maxn;
            bool clear;
            qwq()
            {
                maxn=-INF;
                clear=false;
            }
        };

        int n;
        vector<qwq>op;

        void down(int id)
        {
            if(op[id].clear)
            {
                int hl=id<<1,hr=id<<1|1;

                op[hl].maxn=op[hr].maxn=-INF;
                op[hl].clear=op[hr].clear=true;
    
                op[id].clear=false;
            }
        }

        void dfs(int l,int r,int id,const int &x,const int &val)
        {
            if(l==r)
            {
                op[id].maxn=max(op[id].maxn,val);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,val);
            else dfs(mid+1,r,hr,x,val);

            op[id].maxn=max(op[hl].maxn,op[hr].maxn);
        }

        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return -INF;
            if(st<=l&&r<=ed) return op[id].maxn;

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return max(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        Segment(int _n)
        {
            n=_n;
            op.assign((n+90)<<2,qwq{});
        }

        void update(int x,int val) { dfs(1,n,1,x,val); }

        int get(int st,int ed)
        {
            if(st>ed) return -INF;
            return query(1,n,1,st,ed);
        }

        void reset() { op[1].clear=true,op[1].maxn=-INF; }
};

int n,q;
int id[MAX],L[MAX],R[MAX];
LL a[MAX];

void solve()
{
    cin>>n>>q;

    LL maxn=0;
    discrete<LL> dis;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);

        dis.add(a[i]);
    }

    dis.create();
    for(int i=1;i<=n;i++)
    {
        id[i]=dis.find(a[i]);
        LL r=a[i]>>1,l=(a[i]-1)/3+1;
        int u=dis.lower_rank(l),v=dis.upper_rank(r);
        L[i]=u,R[i]=v;
    }

    int k=0;
    while((1LL<<k)<=maxn) k++;

    Segment fu(dis.size());
    vector<vector<int>>dp(k+1,vector<int>(n+1,-INF));

    for(int i=1;i<=n;i++)
        dp[1][i]=i;

    for(int len=2;len<=k;len++)
    {
        fu.reset();

        for(int i=1;i<=n;i++)
        {
            dp[len][i]=fu.get(L[i],R[i]);

            if(dp[len-1][i]!=-INF) fu.update(id[i],dp[len-1][i]);
        }
    }

    for(int len=1;len<=k;len++)
        for(int i=1;i<=n;i++)
            dp[len][i]=max(dp[len][i],dp[len][i-1]);

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        for(int len=k;len>=1;len--)
            if(dp[len][r]>=l)
            {
                cout<<len<<endl;
                break;
            }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}