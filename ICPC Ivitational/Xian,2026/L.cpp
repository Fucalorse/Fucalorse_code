#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;

void solve()
{
    cin>>n;

    string ans="";
    for(int i=1;i<=n;i++)
        ans+="DRDL";
    for(int i=1;i<n-1;i++)
        ans+="URRD";
    ans+=string(n,'L');
    ans+="DL";
    ans+=string(n,'D');

    cout<<ans.size()<<endl;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}