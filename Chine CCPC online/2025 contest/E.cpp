#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5e5+90,MOD=1e9+7,LEN=5e5;

int T,n,m;

void solve()
{
    cin>>n>>m;

    int rest=m-(n+1)/2;
    cout<<min(n,2*rest+1)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}