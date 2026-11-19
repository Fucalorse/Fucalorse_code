#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353;
const LL INF=1e18;

int n,m;
LL a[MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    LL sum=0,ans=-INF;
    priority_queue<LL>q;
    
    auto maintain=[&](LL val)
    {
        q.push(val);
        sum+=val;
        while((int)q.size()>=m)
        {
            sum-=q.top();
            q.pop();
        }
    };

    for(int i=1;i<m;i++)
        maintain(a[i]);

    for(int i=m;i<=n;i++)
    {
        LL now=1LL*m*a[i]-sum;
        // cout<<m*a[i]<<" "<<sum<<endl;
        ans=max(ans,now);
        maintain(a[i]);
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