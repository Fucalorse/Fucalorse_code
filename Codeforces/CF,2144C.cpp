#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=120,INF=1e9,MOD=998244353;

int T,n;
int a[MAX],b[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];

    LL ans=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>b[i]) swap(a[i],b[i]);
        if(a[i]>=b[i-1]) ans=ans*2LL%MOD;
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