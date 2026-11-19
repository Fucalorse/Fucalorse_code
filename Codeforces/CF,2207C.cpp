#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2090,inf=2e9;

int t,n,h;
LL a[MAX],sum[MAX];

struct peach
{
    private:
        struct qwq
        {
            int pos;
            LL maxn;
        }op[MAX<<2];

        qwq merge(const qwq &a,const qwq &b)
        {
            if(a.maxn==inf) return b;
            if(b.maxn==inf) return a;

            if(a.maxn>b.maxn) return a;
            else return b;
        }
        void create(int l,int r,int id)
        {
            op[id]={0,0};
            if(l==r)
            {
                op[id]={l,a[l]};
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=merge(op[hl],op[hr]);
        }
        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return {inf,inf};
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return merge(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void debut() { create(1,n,1); }
        LL get(int st,int ed) { return query(1,n,1,st,ed).pos; }
}fu;

void solve()
{
    cin>>n>>h;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        LL maxn=a[i];
        sum[i]=h-a[i];
        for(int j=i-1;j>=1;j--)
        {
            maxn=max(maxn,a[j]);
            sum[i]+=h-maxn;
        }
        maxn=a[i];
        for(int j=i+1;j<=n;j++)
        {
            maxn=max(maxn,a[j]);
            sum[i]+=h-maxn;
        }
    }
    fu.debut();
    for(int i=1;i<=n;i++)
        cout<<sum[i]<<" ";
    cout<<endl;
    LL ans=sum[1];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int pos=fu.get(i,j);
            ans=max(ans,sum[i]+sum[j]-sum[pos]);
        }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}