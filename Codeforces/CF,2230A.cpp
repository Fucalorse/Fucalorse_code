#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long 
const int MAX=1e5+90;

int T;
LL n,a,b;

void solve()
{
    cin>>n>>a>>b;

    if(a*3<=b) cout<<a*n<<endl;
    else
    {
        LL ans=n/3*b,r=n%3;
        ans+=min(b,a*r);

        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}