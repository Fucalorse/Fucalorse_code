#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,mod=676767677;

int t,n;
int a[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ed;
    for(ed=n;ed>=1&&a[ed]==1;ed--);
    if(!ed)
    {
        cout<<1<<endl;
        return;
    }
    int ans=ed==n?0:1;
    for(int i=1;i<=ed;i++)
    {
        if(a[i]==1) continue;
        ans=(ans+a[i])%mod;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}