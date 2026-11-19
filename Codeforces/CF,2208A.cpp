#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
int a[150][150];

void solve()
{
    cin>>n;

    map<int,int>f;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            ++f[a[i][j]];
        }

    if(n==1)
    {
        cout<<"NO"<<endl;
        return;
    }

    int lim=(n-1)*n;
    for(auto &[val,cnt]:f)
        if(cnt>lim)
        {
            cout<<"NO"<<endl;
            return;
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