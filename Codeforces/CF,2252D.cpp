#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
typedef multiset<LL> qwq;
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

int n;
int col[MAX];
LL a[MAX],f[MAX];

void solve()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        col[i]=(a[i]%2+2)%2;
        f[i]=a[i]-a[i-1];
    }

    vector<bool>vis(n+1,false);
    for(int i=2;i<n;i++)
        if(col[i-1]==col[i+1]) vis[i]=true;

    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&vis[l]==vis[r]) ++r;

        if(vis[l]) sort(f+l,f+r+1);
    }

    // for(int i=1;i<=n;i++)
    //     cout<<f[i]<<' ';
    // cout<<endl;

    vector<LL>ans(n+1,0);
    for(int i=1;i<=n;i++)
        ans[i]=ans[i-1]+f[i];

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
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