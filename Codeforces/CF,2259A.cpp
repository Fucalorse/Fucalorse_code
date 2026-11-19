#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,k;
string s;

void solve()
{
    cin>>n>>k>>s;s=' '+s;

    int ans=0;
    for(int l=1,r=k;l<=n&&r<=n;l+=k,r+=k)
    {
        int cnt=0;
        for(int i=l;i<=r;i++)
            cnt+=s[i]=='0';

        if(!cnt) ++ans;
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