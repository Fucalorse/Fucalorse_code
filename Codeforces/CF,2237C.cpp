#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7,INF=2e9;

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        if(ans<=a[i]) ans=a[i];
        else ans+=a[i];
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