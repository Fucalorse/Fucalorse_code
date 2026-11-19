#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,m;

void solve()
{
    cin>>n>>m;

    if(__gcd(n,m)==1)
    {
        cout<<"Yes"<<endl;

        int N=n*m;
        for(int i=1;i<=n;i++)
            cout<<(1+(i-1)*m)%N<<' ';
        cout<<endl;

        for(int i=1;i<=m;i++)
            cout<<(1+(i-1)*n)%N<<' ';
        cout<<endl;
    }
    else cout<<"No"<<endl;
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