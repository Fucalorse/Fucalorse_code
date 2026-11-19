#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n,m;

void solve()
{
    cin>>n>>m;

    set<char>st;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        st.insert(s.front()-32);
    }

    bool ok=true;
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        for(auto &cur:s)
            if(st.count(cur)==0) ok=false;
    }

    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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