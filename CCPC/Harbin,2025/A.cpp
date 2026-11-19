#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
        
    LL g=0;
    for(int i=2;i<=n;i++)
        g=__gcd(g,llabs(a[i]-a[1]));

    if(g==0)
    {
        cout<<"infinite"<<endl;
        return;
    }
        
    LL rest=g/__gcd(g,a[1]);
    cout<<g<<' '<<rest<<endl;
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