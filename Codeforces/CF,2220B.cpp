#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,m;
int a[MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&a[l]==a[r]) ++r;
        if(r-l>=m)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
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