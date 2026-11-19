#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

LL op[MAX];

void solve()
{
    cin>>op[1]>>op[2]>>op[3];

    sort(op+1,op+3+1);

    if(op[1]+op[2]<op[3]) op[3]=op[1]+op[2];

    cout<<op[3]-op[1]<<endl;
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