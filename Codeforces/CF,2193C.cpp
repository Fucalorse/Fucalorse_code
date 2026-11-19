#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct fucalorse
{
    private:
        int n;
        vector<LL>op;

        void create(int l,int r,int id,LL *a)
        {
            if(l==r)
            {
                op[id]=a[l];
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl,a);
            create(mid+1,r,hr,a);

            op[id]=op[hl]+op[hr];
        }

        LL query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0LL;
            if(st<=l&&r<=ed) return op[id];

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }
    public:
        fucalorse(int _n,LL *a)
        {
            n=_n;
            op.assign((n+90)<<2,0LL);
            create(1,n,1,a);
        }

        LL get(int st,int ed) { return query(1,n,1,st,ed); }
};

int n,q;
LL a[MAX],b[MAX],f[MAX];

void solve()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        f[i]=max(a[i],b[i]);
    }

    f[n+1]=-LINF;
    for(int i=n;i>=1;i--)
        f[i]=max(f[i],f[i+1]);

    fucalorse fu(n,f);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<fu.get(l,r)<<' ';
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