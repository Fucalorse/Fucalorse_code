#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    map<int,int>f;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++f[a[i]];
    }

    LL ans=0;
    for(auto &[val,cnt]:f)
    {
        int rest=n-cnt;
        int con=min(rest+2,cnt);
        ans+=1LL*con*val;
    }

    cout<<ans<<endl;
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