#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7,INF=2e9;

int n;

void solve()
{
    cin>>n;

    cout<<2*n<<endl;

    double d=0.0101;
    cout<<fixed<<setprecision(20);
    for(int i=1;i<=n;i++)
    {
        double y=(i%10)*d,z=(i/10)*d;
        cout<<0.0<<' '<<y<<' '<<z<<endl;
        cout<<1.0<<' '<<y<<' '<<z<<endl;
    }
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