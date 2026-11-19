#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,mod=998244353;
const LL inf=1e18;

int t,n,q;
LL a[MAX];

struct peach
{
    private:
        struct qwq
        {
            LL con,sum;
            LL lazy;
        }op[MAX<<2];

        qwq merge(const qwq &a,const qwq &b)
        {
            if(a.sum==inf) return b;
            if(b.sum==inf) return a;
            LL now=a.con+b.con+a.sum*b.sum;
            return {now%mod,(a.sum+b.sum)%mod,0};
        }
        void add(int l,int r,int id,LL k)
        {
            int len=r-l+1;

            op[id].con=(op[id].con+(len-1)*k%mod*op[id].sum%mod)%mod;
            op[id].con=(op[id].con+k*k%mod*len*(len-1)/2%mod)%mod;

            op[id].sum=(op[id].sum+k*len%mod)%mod;

            op[id].lazy=(op[id].lazy+k)%mod;
        }
        void down(int l,int r,int id)
        {
            if(op[id].lazy)
            {
                int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
                add(l,mid,hl,op[id].lazy),add(mid+1,r,hr,op[id].lazy);
                op[id].lazy=0;
            }
        }
        void create(int l,int r,int id)
        {
            op[id]={0,0,0};
            if(l==r)
            {
                op[id].sum=a[l];
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=merge(op[hl],op[hr]);
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const LL &k)
        {
            if(st<=l&&r<=ed)
            {
                add(l,r,id,k);
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id]=merge(op[hl],op[hr]);
        }
        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return {inf,inf,inf};
            if(st<=l&&r<=ed) return op[id];
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return merge(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void debut() { create(1,n,1); }
        void update(int st,int ed,LL k) { dfs(1,n,1,st,ed,k); }
        LL get(int st,int ed) { return query(1,n,1,st,ed).con; }
}fu;

void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    fu.debut();
    while(q--)
    {
        int p,l,r;
        cin>>p>>l>>r;
        if(p==1)
        {
            LL k;
            cin>>k;
            fu.update(l,r,k);
        }
        else cout<<fu.get(l,r)<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}