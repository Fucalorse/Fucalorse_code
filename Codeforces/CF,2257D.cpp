#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

LL S;
int q;

void solve()
{
    cin>>S>>q;

    vector<pair<LL,LL>>op;
    for(LL d=1;d*d<=S;d++)
    {
        if(S%d!=0) continue;
        op.push_back({d,S/d});
        if(d*d!=S) op.push_back({S/d,d});
    }

    sort(op.begin(),op.end());

    int len=op.size();
    vector<LL>up,down,base,f(len);

    for(int i=1;i<len;i++)
    {
        base.push_back(op[i-1].first);
        up.push_back(op[i-1].second);
        down.push_back(op[i].second);
    }
    base.push_back(op.back().first);
    up.push_back(op.back().second);
    down.push_back(0LL);

    for(int i=0;i<len;i++)
    {
        if(i) f[i]+=f[i-1];
        f[i]+=(up[i]-down[i])*base[i];
    }

    auto find=[&](const vector<LL> &op,LL tar)
    {
        int l=0,r=op.size()-1;

        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(op[mid]>tar) l=mid+1;
            else r=mid-1;
        }

        return l;
    };

    while(q--)
    {
        LL x,y;
        cin>>x>>y;

        int l=find(down,y);
        int r=upper_bound(base.begin(),base.end(),x)-base.begin()-1;

        if(l>r) cout<<x*y<<endl;
        else
        {
            LL ans=0;
            if(l+1<=r) ans+=f[r]-f[l];

            ans+=x*down[r];
            ans+=base[l]*(y-down[l]);

            cout<<ans<<endl;
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