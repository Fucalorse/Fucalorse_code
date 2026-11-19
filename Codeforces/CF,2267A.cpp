#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
char c;
string s;

void solve()
{
    cin>>n>>c>>s;s=' '+s;

    int ans=0;
    for(int i=1;i<=n/2;i++)
    {
        int l=i,r=n-i+1;
        if(s[l]!=s[r])
        {
            if(s[l]!=c) ++ans;
            if(s[r]!=c) ++ans;
        }
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