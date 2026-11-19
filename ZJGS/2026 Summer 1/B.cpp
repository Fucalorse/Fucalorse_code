#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,INF=2e9,MOD=1e9+7;

struct peach
{
    private:
        vector<int>fa;
    public:
        peach(int n)
        {
            fa.assign(n+3,0);
            for(int i=1;i<=n;i++)
                fa[i]=i;
        }

        void clear(int n)
        {
            for(int i=1;i<=n;i++)
                fa[i]=i;
        }

        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }

        void combine(int x,int y) { fa[find(x)]=find(y); }
};

struct edge
{
    int u,v,val;
    bool operator<(const edge &a)const { return val<a.val; }
}pre[MAX],op[MAX];

int T,n,m,k;

void solve()
{
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++)
        cin>>pre[i].u>>pre[i].v>>pre[i].val;
    sort(pre+1,pre+m+1);

    peach fu(n);
    int len=0;

    for(int i=1;i<=m;i++)
    {
        auto &[u,v,val]=pre[i];

        if(fu.find(u)==fu.find(v)) continue;
        op[++len]=pre[i];
        fu.combine(u,v);
    }

    int l=0,r=0;
    for(int i=1;i<=len;i++)
        r=max(r,op[i].val);

    auto cal=[&](const int &mid)
    {
        int cnt=n;
        fu.clear(n);

        for(int i=1;i<=len;i++)
        {
            auto &[u,v,val]=op[i];

            if(val>mid) continue;
            if(fu.find(u)==fu.find(v)) continue;
            fu.combine(u,v);
            --cnt;
        }

        return cnt;
    };

    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        
        int now=cal(mid);
        if(now==k) ans=mid;
        
        if(now>k) l=mid+1;
        else r=mid-1;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}