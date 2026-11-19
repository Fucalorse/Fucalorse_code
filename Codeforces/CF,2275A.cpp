#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int x,y,r;

void solve()
{
    cin>>x>>y>>r;

    for(int i=1;i<=r;i++)
    {
        int other=r*r-i*i;
        int num=sqrt(other);
        if(num*num==other)
        {
            cout<<x+i<<' '<<y+num<<endl;
            return;
        }
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