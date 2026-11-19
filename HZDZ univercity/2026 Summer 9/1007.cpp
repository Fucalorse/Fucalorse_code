#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define ULL unsigned long long
#define i128 __int128
const int MAX=2e6+90,LEN=32,MOD=998244353,INF=2e9;

mt19937_64 rng(random_device{}());

struct peach
{
    private:
        int size;
        vector<ULL>op;
    public:
        peach(int _n) { size=_n,op.assign(size+3,0ULL); }

        void update(int n,ULL k)
        {
            while(n<=size)
            {
                op[n]+=k;
                n+=n&-n;
            }
        }

        ULL query(int n)
        {
            ULL ans=0;
            
            while(n)
            {
                ans+=op[n];
                n-=n&-n;
            }

            return ans;
        }

        ULL query_range(int l,int r) { return query(r)-query(l-1); }
};

int n,q,k;
ULL V[MAX];
int a[MAX],c[MAX];

void solve()
{
    cin>>n>>q>>k;

    map<pair<int,int>,ULL>f;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    auto add=[&](int u,int v) { if(!f.count({u,v})) f[{u,v}]=rng(); };

    peach fu(n);
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        add(a[i],c[i]);

        int nxt=(c[i]+1)%k;
        add(a[i],nxt);
        V[i]=f[{a[i],nxt}]-f[{a[i],c[i]}];
        fu.update(i,V[i]);
    }

    while(q--)
    {
        int opt;
        cin>>opt;

        if(opt==1)
        {
            int p,x,val;
            cin>>p>>x>>val;
            a[p]=x;
            c[p]=val;

            int nxt=(val+1)%k;
            add(x,val);
            add(x,nxt);

            ULL new_V=f[{x,nxt}]-f[{x,val}];
            fu.update(p,-V[p]+new_V);
            V[p]=new_V;
        }
        else
        {
            int l,r;
            cin>>l>>r;

            if(fu.query_range(l,r)==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
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