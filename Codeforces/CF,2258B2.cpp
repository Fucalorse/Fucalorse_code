#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,m;
int a[MAX];

void solve()
{
    cin>>n>>m;

    vector<LL>cnt(m+1,0),f(m+3,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }

    for(int i=1;i<=m;i++)
        f[i]=f[i-1]+cnt[i];

    vector<LL>ans(m+1,0);
    for(int each=1;each<=m;++each)
    {
        LL sum=0;
        int tot=1;
        for(int k=min(each<<1,m),l=each;;k<<=1)
        {
            int ed=min(k,m);

            while(l<=ed)
            {
                int r=min(l/each*each+each-1,ed);
                sum+=1LL*(f[r]-f[l-1])*(r/each);
                l=r+1;
            }

            LL now=sum+(f[m]-f[l-1])*((1<<tot)-1);
            ans[tot]=max(ans[tot],now);
            ++tot;

            if(k>=m) break;
        }
    }

    for(int i=1;i<=m;i++)
    {
        ans[i]=max(ans[i],ans[i-1]);
        cout<<ans[i]<<' ';
    }
    cout<<endl;
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