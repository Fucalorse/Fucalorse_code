#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

int T,n;
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    int maxn=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='#') ++cnt;
        else
        {
            maxn=max(maxn,cnt);
            cnt=0;
        }
    }
    maxn=max(maxn,cnt);

    cout<<(maxn+1)/2<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}