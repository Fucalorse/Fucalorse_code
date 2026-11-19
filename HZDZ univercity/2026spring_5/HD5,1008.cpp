#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+10,inf=2e9;

struct qwq
{
    int id;
    LL val;
};

int t,n,k;
LL a[MAX],sum[MAX],f[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(f,0,sizeof(LL)*(n+3));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i]/2;
        }
        deque<qwq>q;
        q.push_back({1,a[1]/2});
        f[1]=a[1];
        for(int i=2;i<=n;i++)
        {
            while(q.size()&&q.front().id<i-k-1) q.pop_front();
            f[i]=q.front().val+a[i]+sum[i-1];
            LL now=f[i]-sum[i];
            while(q.size()&&now<=q.back().val) q.pop_back();
            q.push_back({i,now});
        }
        // for(int i=1;i<=n;i++)
        //     cout<<f[i]<<' ';
        // cout<<endl;
        LL ans=1e18;
        for(int i=max(1,n-k);i<=n;i++)
            ans=min(ans,f[i]+sum[n]-sum[i]);
        cout<<ans<<endl;
    }
    return 0;
}