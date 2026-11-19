#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=2e5,G=3,MOD=998244353,INF=2e9;

int minp[MAX];
vector<int>op;

void oula(int n)
{
    minp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }
}

struct fucalorse
{
    private:

        int n;
        vector<int>op,a;
        
        void merge(int id,int l,int r)
        {
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1,gcd=__gcd(op[hl],op[hr]);
            if(a[mid]>a[mid+1]) gcd=__gcd(gcd,mid+1);
            op[id]=gcd;
        }

        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id]=0;
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);

            merge(id,l,r);
        }

        void dfs(int l,int r,int id,const int &x,const int &val)
        {
            if(l==r)
            {
                a[l]=val;
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,val);
            else dfs(mid+1,r,hr,x,val);

            merge(id,l,r);
        }
    public:
        fucalorse(int _n,const vector<int>&_a)
        {
            n=_n;
            op.assign((n+90)<<2,0);
            a=_a;
            create(0,n-1,1);
        }

        void update(int x,int val) { dfs(0,n-1,1,x,val); }

        int get() { return op[1]; }
};

int n,q;
LL cnt[MAX];

void create()
{
    auto cal=[&](int x)
    {
        if(!x) return (LL)n;

        LL ans=1;
        map<int,int>f;

        while(x!=1)
        {
            ++f[minp[x]];
            x/=minp[x];
        }

        for(auto &[val,cnt]:f)
            ans*=cnt+1;

        return ans;
    };

    for(int i=1;i<=LEN;i++)
        cnt[i]=cal(i);
}

void solve()
{
    cin>>n>>q;

    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    auto get=[&](int x)
    {
        if(!x) return (LL)n;
        return cnt[x];
    };

    fucalorse fu(n,a);
    cout<<get(fu.get())<<endl;

    while(q--)
    {
        int pos,val;
        cin>>pos>>val;--pos;

        fu.update(pos,val);
        cout<<get(fu.get())<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}