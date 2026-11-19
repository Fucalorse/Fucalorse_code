#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    auto cal=[&](int st)
    {
        int pos=-1;

        for(int i=st;i<=n;i+=2)
            if(pos==-1&&s[i]!='?')
            {
                pos=i;
                break;
            }

        if(pos==-1) return 2;

        vector<int>f(n+2,0);
        f[pos]=s[pos]-'0';
        for(int i=pos-2;i>=1;i-=2)
            f[i]=f[i+2]^1;
        for(int i=pos+2;i<=n;i+=2)
            f[i]=f[i-2]^1;

        for(int i=st;i<=n;i+=2)
            if(f[i]!=s[i]-'0'&&s[i]!='?') return 0;

        return 1;
    };

    // cout<<cal(1)<<' '<<cal(2)<<endl;

    LL ans=cal(1)*cal(2)%MOD;

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