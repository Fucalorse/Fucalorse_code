#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=998244353;
const LL INF=1e18;

int T,n,y;
int c[MAX];

void solve()
{
    cin>>n>>y;

    int maxn=2; 
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        maxn=max(maxn,c[i]);
    }

    vector<int>cnt(maxn+1,0),sum(maxn+1,0);
    for(int i=1;i<=n;i++)
        ++cnt[c[i]];
    for(int i=1;i<=maxn;i++)
        sum[i]=sum[i-1]+cnt[i];

    LL ans=-INF;
    for(int x=2;x<=maxn;x++)
    {
        LL total=0,cost=0;

        for(int l=1;l<=maxn;l+=x)
        {
            int r=min(maxn,l+x-1),k=(l+x-1)/x;

            total+=min(sum[r]-sum[l-1],cnt[k]);
            cost+=1LL*(sum[r]-sum[l-1])*k;
        }

        cost-=1LL*(n-total)*y;
        ans=max(ans,cost);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}