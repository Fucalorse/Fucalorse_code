#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

int T,n,k;
string s;

void solve()
{
    cin>>n>>k>>s;s=' '+s;

    if(k*2>n)
    {
        cout<<-1<<endl;
        return;
    }

    int ans=0;
    for(int i=1;i<=k;i++)
        if(s[i]=='L') ++ans;
    for(int i=n;i>=n-k+1;i--)
        if(s[i]=='R') ++ans;
    
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