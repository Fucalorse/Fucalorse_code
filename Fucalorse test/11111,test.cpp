#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=1e9;
const LL LINF=9e18;

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

        int lower_rank(int n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }
        int upper_rank(int n) { return upper_bound(num.begin(),num.end(),n)-num.begin(); }

        int size() { return (int)num.size(); }
};

struct Segment
{
    private:
        struct qwq
        {
            int minn;
            int lazy;
            qwq() { minn=lazy=0; }
        };

        int n;
        vector<qwq>op;

        void add(int id,int k)
        {
            op[id].minn+=k;
            op[id].lazy+=k;
        }

        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;
                add(hl,op[id].lazy);
                add(hr,op[id].lazy);
                op[id].lazy=0;
            }
        }

        void create(int l,int r,int id,const vector<int>& a)
        {
            if(l==r)
            {
                op[id].minn=a[l];
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl,a);
            create(mid+1,r,hr,a);

            op[id].minn=min(op[hl].minn,op[hr].minn);
        }

        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                add(id,k);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);

            op[id].minn=min(op[hl].minn,op[hr].minn);
        }

        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return INF;
            if(st<=l&&r<=ed) return op[id].minn;

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return min(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        Segment(int _n,const vector<int>& a)
        {
            n=_n;
            op.assign((n+90)<<2,qwq{});
            create(1,n,1,a);
        }

        void update(int st,int ed,int k)
        {
            if(st>ed) return;
            dfs(1,n,1,st,ed,k);
        }
        int get(int st,int ed)
        {
            if(st>ed) return -INF;
            return query(1,n,1,st,ed);
        }

        int get_maxn() { return op[1].minn; }
};

struct Bit
{
    private:
        int n;
        vector<int>op;
    public:
        Bit(int _n):n(_n),op(_n+1,0){}

        void update(int pos,int k)
        {
            for(int i=pos;i<=n;i+=i&-i)
                op[i]+=k;
        }

        int query(int pos)
        {
            int ans=0;
            for(int i=pos;i;i-=i&-i)
                ans+=op[i];
            return ans;
        }
};

int n;
int a[MAX];

void solve()
{
    cin>>n;

    map<int,vector<int>>pos;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[a[i]].push_back(i);
    }

    vector<int>diff(n+2,0);
    vector<pair<int,int>>pre(n+1,{-1,-1}),suf(n+1,{-1,-1});
    auto get_diff_array=[&]()->vector<int>
    {
        Bit fu(n);
        vector<int>diff(n+2,0);

        for(const auto &[val,vec]:pos)
        {
            if((int)vec.size()<2) continue;

            int len=(int)vec.size();
            for(int i=0;i<len-1;i++)
            {
                int l=vec[i],r=vec[i+1];
                int cnt=fu.query(r)-fu.query(l-1);
                if(cnt==r-l-1)
                {
                    ++diff[l];
                    --diff[r+1];
                    suf[vec[i]]={l,r-1};
                    pre[vec[i+1]]={l,r-1};
                }
            }
        }

        return diff;
    };

    get_diff_array();
    int L=INF,R=-INF;
    for(int i=1;i<=n;i++)
    {
        diff[i]+=diff[i-1];
        if(diff[i]==0)
        {
            L=min(L,i);
            R=max(R,i);
        }
    }

    if(L==INF)
    {
        cout<<0<<endl;
        return;
    }

    Segment seg(n,diff);
    //left
    for(int i=1;i<L;i++)
    {
        if(pre[i].first==-1||pre[i].first==pre[i].second)
        {
            cout<<1<<endl;
            cout<<i<<' '<<a[R]<<endl;
            return;
        }

        auto [l,r]=pre[i];
        if(seg.get(l,r-1)>1)
        {
            cout<<1<<endl;
            cout<<i<<' '<<a[R]<<endl;
            return;
        }
    }

    //right
    for(int i=R+1;i<=n;i++)
    {
        
    }
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