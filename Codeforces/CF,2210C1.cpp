#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

template <typename T>
T __lcm(T a,T b) { return a/__gcd(a,b)*b; }

int n;
int a[MAX],b[MAX],f[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];

    for(int i=1;i<n;i++)
        f[i]=__gcd(a[i],a[i+1]);

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int lcm=1;
        if(i>1) lcm=__lcm(lcm,f[i-1]);
        if(i<n) lcm=__lcm(lcm,f[i]);

        if(lcm!=a[i]) ++ans;
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