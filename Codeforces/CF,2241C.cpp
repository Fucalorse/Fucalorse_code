#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    int cnt=1;
    for(int i=2;i<=n;i++)
        if(s[i]!=s[i-1]) ++cnt;

    if(cnt==2) cout<<2<<endl;
    else cout<<1<<endl;
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