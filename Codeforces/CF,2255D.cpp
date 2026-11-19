#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
LL a[MAX];

bool check(LL mid)
{
    priority_queue<LL>q;
    for(int i=1;i<=n;i++)
        q.push(a[i]);

    for(LL k=mid-1;k>=0;k--)
    {
        if(q.empty()) break;

        LL cur=q.top();q.pop();
        LL high=63-__builtin_clzll(cur);

        if(k>high) continue;

        // cout<<high<<endl;

        if(k<=high)
        {
            cur-=1LL<<k;
            if(cur>0) q.push(cur);
        }
    }

    return q.empty();
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    // check(1);
    // cout<<check(1)<<endl;

    LL l=0,r=6e6;
    while(l<=r)
    {
        LL mid=(l+r)>>1;

        if(check(mid)) r=mid-1;
        else l=mid+1;
    }

    cout<<l<<endl;
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