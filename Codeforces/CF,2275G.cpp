#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

struct fucalorse
{
    private:
        vector<int>fa,sz;
    public:
        fucalorse(int _n)
        {
            fa.assign(_n+1,0);
            sz.assign(_n+1,0);
            for(int i=1;i<=_n;i++)
            {
                fa[i]=i;
                sz[i]=1;
            }
        }

        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }

        void merge(int x,int y)
        {
            int px=find(x),py=find(y);
            if(px==py) return;
            fa[px]=py;
            sz[py]+=sz[px];
        }

        int get_size(int x) { return sz[find(x)]; }
};

struct Edge
{
    int u,v,val;
    bool operator<(const Edge &a)const { return val<a.val; }
}edge[MAX];

int n,m,q;

void solve()
{
    cin>>n>>m>>q;

    int need_comb=n-1;
    fucalorse fu(n);
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        edge[i]={u,v,val};
        if(fu.find(u)!=fu.find(v))
        {
            fu.merge(u,v);
            --need_comb;
        }
    }

    vector<vector<Edge>>comb(n+1);
    for(int i=1;i<=m;i++)
    {
        auto [u,v,val]=edge[i];
        comb[fu.find(u)].push_back(edge[i]);
    }

    LL free=0;
    vector<LL>rest;
    fucalorse dsu(n);
    for(int x=1;x<=n;x++)
    {
        auto &op=comb[x];
        if(op.empty()) continue;

        sort(op.begin(),op.end());
        LL total=0;
        for(auto &[u,v,val]:op)
        {
            if(dsu.find(u)!=dsu.find(v))
            {
                dsu.merge(u,v);
                rest.push_back(val);
            }
            else total+=val;
        }
        free+=total;
    }

    int len=rest.size();
    sort(rest.begin(),rest.end(),greater<LL>());
    vector<LL>sum(len+2,0LL);
    for(int i=0;i<len;i++)
        sum[i+1]=sum[i]+rest[i];

    while(q--)
    {
        LL x;
        cin>>x;

        LL ans=free-1LL*x*(need_comb+1)*need_comb/2,st=1LL*x*(need_comb+1);
        int l=1,r=len;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            LL now=rest[mid-1]-(st+(mid-1)*x);
            if(now>=0) l=mid+1;
            else r=mid-1;
        }

        if(r>=1)
        {
            LL cost=st*r+1LL*r*(r-1)*x/2;
            ans+=sum[r]-cost;
        }

        cout<<ans<<' ';
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