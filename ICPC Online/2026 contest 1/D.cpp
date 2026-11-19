#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int p[MAX];

void solve()
{
    cin>>n;

    vector<int>cnt(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        ++cnt[p[i]];
    }

    LL ans=1;
    int a=0,b=0;

    while(a+b<n)
    {
        if(a==b) ans=ans*2%MOD;

        if(cnt[b])
        {
            --cnt[b];
            ++a;
        }
        else
        {
            --cnt[a];
            ++b;
        }
    }

    cout<<ans<<endl;
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