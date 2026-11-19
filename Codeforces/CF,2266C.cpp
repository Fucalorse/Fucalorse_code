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

    vector<int>pre(n+3,0),suf(n+3,0);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+(s[i]=='1');
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+(s[i]=='0');

    if(s[1]=='1') cout<<suf[1]<<endl;
    else
    {
        int ans=pre[n],st;
        for(st=1;st<=n;st++)
            if(s[st]=='1') break;

        if(st<=n)
        {
            for(int i=st;i<=n;i++)
            {
                int now=pre[i-1]+suf[i];
                ans=min(ans,now);
            }
        }

        cout<<ans<<endl;
    }
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