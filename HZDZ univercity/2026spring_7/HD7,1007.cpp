#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3090;

struct peach
{
    private:
        vector<int>fa;
    public:
        peach(int n)
        {
            fa.assign(n+3,0);
            for(int i=0;i<=n;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
};

struct point
{
    int u,v;
    LL val;
    bool operator<(const point &a)const { return val<a.val; }
};

int t,n;
LL a[MAX];

void solve()
{
    cin>>n;
    vector<point>op;
    peach fu(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        op.push_back({i,i,a[i]<<1});
        if(i>1) op.push_back({i-1,i,a[i-1]+a[i]});
    }
    sort(op.begin(),op.end());
    LL ans=0;
    for(auto &[u,v,val]:op)
    {
        int minn=min(u-1,n-v);
        for(int i=0;i<=minn;i++)
        {
            if(fu.find(u-i)==fu.find(v+i)) continue;
            fu.combine(u-i,v+i);
            ans+=val;
        }
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