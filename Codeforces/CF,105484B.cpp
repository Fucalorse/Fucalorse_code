#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

string s;

void solve()
{
    cin>>s;s=' '+s;

    int n=s.size()-1,sum=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        int f=1;
        if(i&1) f=-1;

        if(s[i]=='1') sum+=f;
        else if(s[i]=='0') sum+=-f;
        else cnt++;
    }

    cout<<max(abs(sum)-cnt,n&1)<<endl;
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