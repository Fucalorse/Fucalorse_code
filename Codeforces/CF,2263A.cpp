#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    int c0=0,c1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0) ++c0;
        else ++c1;
    }

    if(c1>=c0) cout<<"Bessie"<<endl;
    else cout<<"Elsie"<<endl;
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