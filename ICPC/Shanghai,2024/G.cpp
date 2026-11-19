#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=1e9;
const LL LINF=2e18;

int n;
LL a[MAX],b[MAX],c[MAX];

LL find_large(LL u,LL target)
{
    LL l=-INF,r=INF;
    while(l<=r)
    {
        LL mid=(l+r)/2;
        if(u*mid>=target) r=mid-1;
        else l=mid+1;
    }
    return l>INF?LINF:l;
}

LL find_small(LL u,LL target)
{
    LL l=-INF,r=INF;
    while(l<=r)
    {
        LL mid=(l+r)/2;
        if(u*mid<target) r=mid-1;
        else l=mid+1;
    }
    return r<-INF?-LINF:r;
}

void solve()
{
    cin>>n;

    vector<LL>plain;
    vector<pair<LL,LL>>pos,neg;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(a[i]>0) pos.push_back({a[i],b[i]});
        else if(a[i]==0) plain.push_back(b[i]);
        else neg.push_back({a[i],b[i]});
    }

    for(int i=1;i<=n;i++)
        cin>>c[i];
    sort(c+1,c+n+1);

    int mid_num=(n+1)>>1;
    auto check=[&](LL mid)
    {
        int ans=0;
        vector<LL>op;
        for(auto &[u,v]:pos)
            op.push_back(find_large(u,mid-v));
        sort(op.begin(),op.end(),greater<LL>());

        int ed=n;
        for(auto &need:op)
            if(c[ed]>=need)
            {
                ++ans;
                --ed;
            }

        op.clear();
        for(auto &[u,v]:neg)
            op.push_back(find_small(u,mid-v));
        sort(op.begin(),op.end());

        int st=1;
        for(auto &need:op)
        {
            if(st>ed) break;
            if(c[st]<=need)
            {
                ++ans;
                ++st;
            }
        }

        for(auto &cur:plain)
            if(cur>=mid) ++ans;

        return ans>=mid_num;
    };

    LL l=-LINF,r=LINF;
    while(l<=r)
    {
        LL mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }

    cout<<r<<endl;
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