#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    vector<LL>op;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        op.push_back(a[i]-i);
    }

    sort(op.begin(),op.end());
    op.erase(unique(op.begin(),op.end()),op.end());

    int ans=0,len=op.size();
    for(int l=0,r=0;l<len;l=r)
    {
        r=l+1;
        while(r<len&&op[r]==op[r-1]+1) ++r;
        ans=max(ans,r-l);
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