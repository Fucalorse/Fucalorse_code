#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;

int T,n,x,y,z;

void solve()
{
    cin>>n>>x>>y>>z;

    int ans=(n-1)/(x+y)+1;
    if(x*z<n)
    {
        int now=z;
        n-=x*z;

        now+=(n-1)/(x+10*y)+1;
        ans=min(ans,now);
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