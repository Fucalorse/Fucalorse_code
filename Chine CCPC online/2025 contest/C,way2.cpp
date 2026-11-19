#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,MOD=1e9+7,LEN=5e5;
const LL INF=1e18;

int T,n;
LL k;
LL a[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=k;
    }

    sort(a+1,a+n+1);

    int l=1,r=n;
    LL ans=0;

    while(l<r&&a[l]+a[r]<k)
    {
        ++l;
        ans+=a[l]+a[1];
    }

    while(l<r)
    {
        while(l<r&&a[l]+a[r]>=k)
        {
            ans+=a[l]+a[r]-k;
            --r;
        }

        while(l<r&&a[l]+a[r]<k)
        {
            ++l;
            ans+=a[l]+a[r+1]-k;
        }
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