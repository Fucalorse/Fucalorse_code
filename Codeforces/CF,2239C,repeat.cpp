#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct Segment
{
    private:
        int n;
        vector<int>op;

        void dfs(int l,int r,int id,const int &x,const int &k)
        {
            if(l==r)
            {
                op[id]+=k;
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,k);
            else dfs(mid+1,r,hr,x,k);

            op[id]=op[hl]+op[hr];
        }
    public:
        Segment(int _n)
        {
            n=_n;
            op.assign((n+90)<<2,0);
        }

        void update(int x,int k) { dfs(1,n,1,x,k); }

        int kth(int k)
        {
            int l=1,r=n,id=1;
            while(l<r)
            {
                int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
                if(k<=op[hl])
                {
                    id=hl;
                    r=mid;
                }
                else
                {
                    id=hr;
                    l=mid+1;
                    k-=op[hl];
                }
            }
            return l;
        }

        int size() { return op[1]; }
};

struct fucalorse
{
    private:
        int n;
        vector<LL>op;
    public:
        fucalorse(int _n)
        {
            n=_n;
            op.assign(n+3,0LL);
        }

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

        LL query_range(int l,int r)
        {
            if(l>r) return 0LL;
            return query(r)-query(l-1);
        }
};

struct Query
{
    char type;
    LL val;
}op[MAX];

int n;
int ans[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>op[i].type>>op[i].val;

    vector<int>pre(n+1,0);
    for(int i=1,pos=0;i<=n;i++)
    {
        pre[i]=pos;
        if(op[i].type=='s') pos=i;
    }

    Segment st(n);
    fucalorse A(n),B(n);

    for(int i=1;i<=n;i++)
    {
        if(op[i].type=='p') ans[i]=op[i].val;
        st.update(i,1);
        A.update(i,1LL);
    }

    int start=n;
    while(op[start].type=='p')
    {
        A.update(op[start].val,-1);
        st.update(op[start].val,-1);
        --start;
    }

    for(int cur=start;cur>=1;cur=pre[cur])
    {
        LL base=0,target=op[cur].val-op[pre[cur]].val;
        for(int i=cur-1;i>pre[cur];i--)
        {
            base+=A.query_range(op[i].val+1,n);
            A.update(op[i].val,-1);
            B.update(op[i].val,1);
            st.update(op[i].val,-1);
        }

        int l=1,r=st.size();
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int x=st.kth(mid);
            LL now=base+A.query_range(x+1,n)+B.query_range(x+1,n)-B.query(x-1);
            if(now<=target) r=mid-1;
            else l=mid+1;
        }

        int x=st.kth(l);
        A.update(x,-1);
        st.update(x,-1);
        for(int i=cur-1;i>pre[cur];i--)
            B.update(op[i].val,-1);

        ans[cur]=x;
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
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