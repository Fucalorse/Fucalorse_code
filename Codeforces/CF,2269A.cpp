#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,k;
LL pw2[MAX];

void create()
{
    pw2[0]=1;
    for(int i=1;i<=LEN;i++)
        pw2[i]=pw2[i-1]*2;
}

void solve()
{
    cin>>n>>k;

    LL ans=pw2[n-k+1];
    for(int i=1;i<=k-1;i++)
        ans+=2;

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}