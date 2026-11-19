#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e6,G=3,MOD=998244353,INF=2e9;

LL qpow(LL a,LL p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ans;
}

struct peach
{
    private:
        struct qwq
        {
            int cnt;
            bool lazy;
        };

        int n;
        vector<qwq>op;

        void add(int id)
        {
            op[id].cnt=0;
            op[id].lazy=true;
        }

        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;
                add(hl);
                add(hr);
                op[id].lazy=false;
            }
        }

        void create(int l,int r,int id)
        {
            op[id]={0,false};
            if(l==r)
            {
                op[id].cnt=1;
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);

            op[id].cnt=op[hl].cnt+op[hr].cnt;
        }

        void dfs(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed)
            {
                add(id);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed);
            if(mid<ed) dfs(mid+1,r,hr,st,ed);

            op[id].cnt=op[hl].cnt+op[hr].cnt;
        }

        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].cnt;

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }
    public:
        peach(int _n)
        {
            n=_n;
            op.assign((n+90)<<2,qwq{});
            create(1,n,1);
        }

        void update(int st,int ed) { dfs(1,n,1,st,ed); }

        int get(int st,int ed) { return query(1,n,1,st,ed); }
};

int n,q;
int lg[MAX];
LL f[MAX],inv[MAX];

struct qwq
{
    int id,x;
    bool operator<(const qwq &a)const
    {
        if(x!=a.x) return x<a.x;
        return lg[id]>lg[a.id];
    }
}op[MAX];

void create()
{
    f[0]=1;
    for(int i=1;i<=LEN;i++)
        f[i]=f[i-1]*i%MOD;

    inv[LEN]=qpow(f[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;

    lg[1]=0;
    for(int i=2;i<=LEN;i++)
        lg[i]=lg[i>>1]+1;
}

LL C(int n,int m) { return f[n]*inv[n-m]%MOD*inv[m]%MOD; }

LL A(int n,int m) { return f[n]*inv[n-m]%MOD; }

void dfs(int l,int r,int id,vector<pair<int,int>>& range)
{
    range[id]={l,r};
    if(l==r) return;

    int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
    dfs(l,mid,hl,range);
    dfs(mid+1,r,hr,range);
}

void solve()
{
    cin>>n>>q;

    int N=1<<n,S=(1<<(n+1))-1;

    for(int i=1;i<=q;i++)
        cin>>op[i].id>>op[i].x;

    sort(op+1,op+q+1);

    vector<set<int>>node(S+1);
    for(int i=1;i<=q;i++)
    {
        node[op[i].id].insert(op[i].x);
        if((int)node[op[i].id].size()>=2)
        {
            cout<<0<<endl;
            return;
        }
    }

    int use=0;
    LL ans=1;
    set<int>vis;
    peach fu(N);

    vector<pair<int,int>>range(S+1,pair<int,int>{});
    dfs(1,N,1,range);

    for(int l=1,r=1;l<=q;l=r)
    {
        while(r<=q&&op[l].x==op[r].x) ++r;

        vector<pair<int,int>>st;
        for(int i=l;i<r;i++)
            st.push_back(range[op[i].id]);

        for(auto itl=st.begin();itl!=st.end();++itl)
        {
            auto itr=itl;++itr;
            if(itr==st.end()) break;

            auto [prel,prer]=*itl;
            auto [nowl,nowr]=*itr;

            bool in_range=nowl<=prel&&prer<=nowr;
            if(!in_range)
            {
                cout<<0<<endl;
                return;
            }
        }
    }

    for(int i=1;i<=q;i++)
    {
        const auto &[id,x]=op[i];
        const auto &[l,r]=range[id];
        int rest=fu.get(l,r);

        int cnt=x-use;
        if(rest>cnt)
        {
            cout<<0<<endl;
            return;
        }

        if(vis.count(x))
        {
            LL now=A(cnt,rest);
            ans=ans*now%MOD;
        }
        else
        {
            if(!rest)
            {
                cout<<0<<endl;
                return;
            }

            LL now=A(cnt-1,rest-1)*rest%MOD;
            ans=ans*now%MOD;
            vis.insert(x);
        }

        use+=rest;
        fu.update(l,r);
    }

    ans=ans*f[fu.get(1,N)]%MOD;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}