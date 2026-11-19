#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7,INF=2e9,LEN=2e6;

struct peach
{
    private:
        struct qwq
        {
            int maxn,minn;
            int ans;
        };

        int n;
        vector<qwq>op;

        qwq merge(const qwq &a,const qwq &b,int len)
        {
            if(a.maxn==-1) return b;
            if(b.maxn==-1) return a;

            int ans=max(a.ans,b.ans);
            if(a.maxn>b.minn) ans=max(ans,len/2);

            return {max(a.maxn,b.maxn),min(a.minn,b.minn),ans};
        }

        void create(int l,int r,int id,int *a)
        {
            if(l==r)
            {
                op[id]={a[l],a[l],0};
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl,a);
            create(mid+1,r,hr,a);

            op[id]=merge(op[hl],op[hr],r-l+1);
        }

        void dfs(int l,int r,int id,const int &x,const int &k)
        {
            if(l==r)
            {
                op[id].maxn=op[id].minn=k;
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,k);
            else dfs(mid+1,r,hr,x,k);

            op[id]=merge(op[hl],op[hr],r-l+1);
        }
    public:
        peach(int _n) { n=_n,op.assign((n+90)<<2,{0,0,0}); }
        void build(int *a) { create(0,n,1,a); }
        void update(int x,int k) { dfs(0,n,1,x,k); }
        int query() { return op[1].ans; }
};

int n,q;
int a[MAX],lg[MAX];

void create()
{
    lg[1]=0;
    for(int i=2;i<=LEN;i++)
        lg[i]=lg[i>>1]+1;
}

void solve()
{
    cin>>n>>q;

    for(int i=0;i<n;i++)
        cin>>a[i];

    int m=(1<<lg[n])==n?n:1<<(lg[n]+1);

    for(int i=n;i<m;i++)
        a[i]=INF;

    peach fu(m-1);
    fu.build(a);
    cout<<fu.query()<<endl;

    while(q--)
    {
        int pos,x;
        cin>>pos>>x;

        a[pos]=x;
        fu.update(pos,x);

        cout<<fu.query()<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}