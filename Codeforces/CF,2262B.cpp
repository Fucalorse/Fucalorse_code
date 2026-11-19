#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

struct Bit
{
    private:
        int n;
        vector<LL>op;
    public:
        Bit(int _n):n(_n),op(_n+3,0LL){}

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
};

struct fucalorse
{
    private:
        struct qwq
        {
            LL minn;
            LL lazy;
        };

        int n;
        vector<qwq>op;

        void add(int id,LL k)
        {
            op[id].minn+=k;
            op[id].lazy+=k;
        }

        void down(int id)
        {
            if(op[id].lazy!=0)
            {
                int hl=id<<1,hr=id<<1|1;
                add(hl,op[id].lazy);
                add(hr,op[id].lazy);
                op[id].lazy=0;
            }
        }

        void create(int l,int r,int id,const vector<LL>& a)
        {
            op[id]={0,0};

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

        void dfs(int l,int r,int id,const int &st,const int &ed,const LL &k)
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

        int find_first(int l,int r,int id,const int &st,const int &ed,const LL &target)
        {
            if(r<st||l>ed||op[id].minn>=target) return n+1;
            if(l==r) return l;

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            int ans=find_first(l,mid,hl,st,ed,target);
            if(ans!=n+1) return ans;
            return find_first(mid+1,r,hr,st,ed,target);
        }
    public:
        fucalorse(int _n,const vector<LL>& a)
        {
            n=_n;
            op.assign((n+90)<<2,qwq{});
            create(1,n,1,a);
        }

        void update(int st,int ed,LL k)
        {
            if(st>ed) return;
            dfs(1,n,1,st,ed,k);
        }

        int find(int st,int ed,LL target)
        {
            if(st>ed) return n+1;

            return find_first(1,n,1,st,ed,target);
        }
};

int n;
int a[MAX],p[MAX];
LL f[MAX];

void solve()
{
    cin>>n;

    vector<LL>b(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
        b[i]=f[i]-2*a[i];
    }

    for(int i=1;i<=n;i++)
        cin>>p[i];

    Bit bit(n);
    fucalorse fu(n,b);
    set<int>st{0,n+1};

    for(int i=1;i<=n;i++)
        bit.update(i,a[i]);

    for(int pos=1;pos<=n;)
    {
        int nxt=fu.find(pos+1,n,f[pos-1]);
        st.insert(pos);
        pos=nxt;
    }

    cout<<(int)st.size()-3<<' ';
    for(int i=1;i<n;i++)
    {
        auto it=st.lower_bound(p[i]);
        int l=*prev(it),r=*st.upper_bound(p[i]);

        st.erase(p[i]);
        bit.update(p[i],-a[p[i]]);
        fu.update(p[i],p[i],LINF);
        fu.update(p[i]+1,n,-a[p[i]]);

        for(int pos=l;pos<r;)
        {
            int nxt;
            if(pos==0) nxt=fu.find(pos+1,n,0);
            else nxt=fu.find(pos+1,n,bit.query(pos-1));
            st.insert(pos);
            pos=nxt;
        }

        cout<<(int)st.size()-3<<' ';
    }
    cout<<endl;
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