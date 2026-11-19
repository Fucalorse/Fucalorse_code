#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7;
const LL INF=1e18;

int T,n;
LL c;
LL a[MAX];

void solve()
{
    cin>>n>>c;

    LL base=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        base+=a[i]-c;
    }

    sort(a+1,a+n+1);
    for(int i=1;i<=(n>>1);i++)
    {
        if(a[i]>=c) break;
        base+=c-a[i];
    }

    cout<<base<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}