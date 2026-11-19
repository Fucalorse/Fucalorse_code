#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

int n;

void solve()
{
    cin>>n;

    int k=n/2,A=n+k,B=2*n+k;
    if(n&1)
    {
        cout<<3*n-1<<' '<<0<<' '<<(3*n-1)/2<<endl;
        for(int i=1;i<=k;i++)
        {
            cout<<A+i<<' '<<2*i<<' '<<A-i<<endl;
            cout<<B+i-1<<' '<<2*i-1<<' '<<B-i<<endl;
        }
    }
    else
    {
        cout<<3*n-1<<' '<<A-1<<' '<<A<<endl;
        cout<<3*n-(n/2+1)<<' '<<0<<' '<<1<<endl;
        for(int i=1;i<k;i++)
        {
            cout<<A+i<<' '<<2*i+1<<' '<<A-i-1<<endl;
            cout<<B+i-1<<' '<<2*i<<' '<<B-i-1<<endl;
        }
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