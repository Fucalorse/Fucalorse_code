#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

struct qwq
{
    int val;
    int l,r;
};

int n;
int a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<qwq>op;
    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&a[l]==a[r]) ++r;
        op.push_back({a[l],l,r-1});
    }

    int len=op.size(),base=len,ans=base;
    for(int i=1;i<len;i++)
    {
        if(op[i].r-op[i].l+1==1)
        {
            if(i<len-1&&op[i-1].val==op[i+1].val) continue;

            int extra=min(op[i-1].r-op[i-1].l,1)+min(op[i].r-op[i].l,1);
            ans=max(ans,base+extra);
        }
        else
        {
            if(i>=2&&op[i-1].r-op[i-1].l+1==1&&op[i-2].val==op[i].val) continue;

            int extra=min(op[i-1].r-op[i-1].l,1)+min(op[i].r-op[i].l,1);
            // cout<<i<<' '<<extra<<endl;
            ans=max(ans,base+extra);
        }
    }

    cout<<ans<<endl;
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