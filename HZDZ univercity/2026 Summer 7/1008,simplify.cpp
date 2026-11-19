#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
LL w;
string s;

void solve()
{
    cin>>n>>w>>s;s=' '+s;

    int r=1;
    vector<LL>ans(n+1,0);
    while(r<n&&s[r]=='&') ++r;

    for(int i=1;i<=r;i++)
        ans[i]=w;

    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
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