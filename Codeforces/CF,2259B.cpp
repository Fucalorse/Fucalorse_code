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

    map<int,int>cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]&1) ++cnt[1];
        else
        {
            if((a[i]>>1)&1) ++cnt[0];
            else ++cnt[2];
        }
    }

    int ans=0;
    for(auto &[val,freq]:cnt)
        ans=max(ans,freq);

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