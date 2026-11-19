#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct ovo
{
    int u,v,val;
    bool operator<(const ovo &a)const { return val<a.val; }
}edge[MAX];

struct peach
{
    private:
        int fa[MAX];
    public:
        void debut(int n)
        {
            for(int i=0;i<=n;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
}fu;

int t,n,m;

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,col;
        cin>>u>>v>>col;
        edge[i]={u,v,col};
    }
    sort(edge+1,edge+m+1);
    fu.debut(n);
    int l=0,r=0,total=n-1;
    for(int i=1;i<=m;i++)
    {
        auto [u,v,val]=edge[i];
        if(fu.find(u)==fu.find(v)) continue;
        l+=val;
        fu.combine(u,v);
        if(--total==0) break;
    }
    if(total!=0)
    {
        cout<<0<<endl;
        return;
    }
    fu.debut(n);
    total=n-1;
    for(int i=m;i>=1;i--)
    {
        auto [u,v,val]=edge[i];
        if(fu.find(u)==fu.find(v)) continue;
        r+=val;
        fu.combine(u,v);
        if(--total==0) break;
    }
    cout<<r-l+1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}