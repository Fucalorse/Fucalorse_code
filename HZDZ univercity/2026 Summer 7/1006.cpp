#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n,m;

void solve()
{
    cin>>n>>m;

    int minn=n-1;
    vector<int>pre_max(n+3,-INF),suf_max(n+3,-INF),suf_min(n+3,INF);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        if(l>r) swap(l,r);
        ++l;

        minn=min(minn,r);

        pre_max[l]=max(pre_max[l],r);
        suf_max[l]=max(suf_max[l],l);
        suf_min[l]=min(suf_min[l],r);
    }

    for(int i=1;i<=n;i++)
        pre_max[i]=max(pre_max[i],pre_max[i-1]);
    for(int i=n;i>=1;i--)
    {
        suf_max[i]=max(suf_max[i],suf_max[i+1]);
        suf_min[i]=min(suf_min[i],suf_min[i+1]);
    }

    for(int x=2;x<=minn;x++)
    {
        int st=max({x+1,pre_max[x]+1,suf_max[x+1]}),ed=min(suf_min[x+1],n);
        if(st<=ed)
        {
            cout<<"Yes"<<endl;
            cout<<x<<' '<<st<<endl;
            return;
        }
    }

    cout<<"No"<<endl;
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