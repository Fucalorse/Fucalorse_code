#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    int c1=0,other=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) ++c1;
        else ++other;
    }

    if(c1==n)
    {
        if(c1&1) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    else
    {
        if(c1&1) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
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