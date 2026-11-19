#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=30,MOD=998244353,INF=2e9;

int n;
int a[MAX],b[MAX];
string sa,sb;

void solve()
{
    cin>>n>>sa>>sb;
    sa=' '+sa,sb=' '+sb;

    int ca=0,cb=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]^(sa[i]-'0');
        b[i]=b[i-1]^(sb[i]-'0');

        if(a[i]) ++ca;
        if(b[i]) ++cb;
    }

    if(ca==cb||ca+cb==n+1) cout<<"YES"<<endl;
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