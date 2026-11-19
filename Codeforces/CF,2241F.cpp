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

    int st,ed;
    for(st=1;st<=n;++st)
        if(s[st]=='1') break;
    for(ed=n;ed>=1;--ed)
        if(s[ed]=='0') break;

    if(st>ed)
    {
        cout<<"Bob"<<endl;
        return;
    }

    for(int l=st,r=st;l<=ed;l=r)
    {
        while(r<=ed&&s[l]==s[r]) ++r;
        if((r-l)&1)
        {
            cout<<"Alice"<<endl;
            return;
        }
    }

    cout<<"Bob"<<endl;
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