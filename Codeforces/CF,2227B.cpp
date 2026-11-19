#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    int cnt=0;
    for(int i=1;i<=n;i++)
        if(s[i]==')') ++cnt;

    if(cnt*2!=n) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}