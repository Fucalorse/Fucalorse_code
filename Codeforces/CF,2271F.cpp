#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=20,G=3,MOD=998244353,INF=1e9;
const LL LINF=9e18;

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
    auto get_diff_array=[&]()
    {
        Bit fu(n);

        for(const auto &[val,vec]:pos)
        {
            int len=(int)vec.size();
            for(int i=0;i<len-1;i++)
            {
                int l=vec[i],r=vec[i+1];
                int cnt=fu.query(r)-fu.query(l-1);
                if(cnt==r-l-1)
                {
                    ++diff[l];
                    --diff[r+1];
                    suf[vec[i]]={l,r};
                    pre[vec[i+1]]={l,r};
                }
            }

            for(auto &cur:vec)
                fu.update(cur,1);
        }
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

    if(L==R)
    {
        int num=L==1?a[L+1]:a[L-1];

        cout<<1<<endl;
        cout<<L<<' '<<num<<endl;
        return;
    }

    Segment seg(n,diff);
    //left
    {
        int maxn=-INF;
        for(int i=R;i<=n;i++)
            maxn=max(maxn,a[i]);

        bool ok=true;
        for(int i=L;i<R;i++)
            if(a[i]>maxn)
            {
                ok=false;
                break;
            }
     
        if(ok)
        {
            int st=L;
            while(st>=1&&a[st]<maxn) --st;
            st=max(st,1);

            for(int i=st;i<=L;i++)
            {
                auto [l,r]=pre[i];
                if(l==-1||l==r)
                {
                    cout<<1<<endl;
                    cout<<i<<' '<<maxn<<endl;
                    return;
                }

                int minn=seg.get(l,r-1);
                if(minn>1)
                {
                    cout<<1<<endl;
                    cout<<i<<' '<<maxn<<endl;
                    return;                    
                }
            }
        }
    }

    //right
    {
        int maxn=-INF;
        for(int i=1;i<=L;i++)
            maxn=max(maxn,a[i]);

        bool ok=true;
        for(int i=L+1;i<=R;i++)
            if(a[i]>maxn)
            {
                ok=false;
                break;
            }

        if(ok)
        {
            int ed=R;
            while(ed<=n&&a[ed]<maxn) ++ed;
            ed=min(ed,n);

            for(int i=R;i<=ed;i++)
            {
                auto [l,r]=suf[i];
                if(l==-1||l==r)
                {
                    cout<<1<<endl;
                    cout<<i<<' '<<maxn<<endl;
                    return;
                }

                int minn=seg.get(l+1,r);
                if(minn>1)
                {
                    cout<<1<<endl;
                    cout<<i<<' '<<maxn<<endl;
                    return;
                }
            }
        }
    }

    //middle
    {
        Bit fu(n);

        auto update=[&](const vector<int>& vec)
        {
            for(auto &cur:vec)
                fu.update(cur,1);
        };

        for(const auto &[val,vec]:pos)
        {
            auto itl=upper_bound(vec.begin(),vec.end(),L);
            if(itl==vec.begin())
            {
                update(vec);
                continue;
            }
            auto itr=lower_bound(vec.begin(),vec.end(),R);
            if(itr==vec.end())
            {
                update(vec);
                continue;
            }
            int l=*(itl-1),r=*itr;
            if(l>L||r<R||l==r)
            {
                update(vec);
                continue;
            }

            int cnt=(r-l-1)-(fu.query(r)-fu.query(l-1));
            if(cnt<=1)
            {
                int st=l,ed=r;
                while(l<=r)
                {
                    int mid=(l+r)>>1;
                    if(fu.query(mid)-fu.query(st)==mid-st) l=mid+1;
                    else r=mid-1;
                }

                if(pre[l].first!=-1) seg.update(pre[l].first,pre[l].second,-1);
                if(suf[l].first!=-1) seg.update(suf[l].first,suf[l].second,-1);
                seg.update(st,ed,1);

                if(seg.get_maxn()>=1)
                {
                    cout<<1<<endl;
                    cout<<l<<' '<<1<<endl;
                    return;
                }

                if(pre[l].first!=-1) seg.update(pre[l].first,pre[l].second,1);
                if(suf[l].first!=-1) seg.update(suf[l].first,suf[l].second,1);
                seg.update(st,ed,-1);            
            }

            update(vec);
        }
    }

    cout<<2<<endl;
    cout<<1<<' '<<INF<<endl;
    cout<<n<<' '<<INF<<endl;
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