#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

mt19937 rng(random_device{}());
int n,y;
string s;

void solve()
{
    n=rng()%10+1,y=rng()%20+1;
    s="#";
    for(int i=1;i<n;i++)
    {
        if(rng()&1) s.push_back('E');
        else s.push_back('I');
    }

    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}