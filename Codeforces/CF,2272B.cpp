#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
string s;

void solve()
{
    cin>>n;

    int cnt=0;
    for(int i=1;i<=2;i++)
    {
        cin>>s;
        for(auto &cur:s)
            cnt+=(cur=='f');
    }

    cout<<(cnt&1)<<endl;
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