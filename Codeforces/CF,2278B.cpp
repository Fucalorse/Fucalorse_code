#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int x,y,z;

void solve()
{
    cin>>x>>y>>z;
    int maxn=max({x,y,z}),total=x+y+z;
    if(maxn==x) cout<<string(total,'P')<<endl;
    else if(maxn==y) cout<<string(total,'R')<<endl;
    else cout<<string(total,'S')<<endl;
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