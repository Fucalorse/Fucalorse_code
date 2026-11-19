#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;

    vector<int>cnt(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }
    
    int ansa=0,ansb=0;
    for(int i=0;i<=n;i++)
    {
        int num=(cnt[i]>>1)+(cnt[i]&1);
        if(num>=k) ++ansa;
        else break;
    }
    for(int i=0;i<=n;i++)
    {
        int num=cnt[i]>>1;
        if(num>=k) ++ansb;
        else break;
    }

    if(ansa!=ansb) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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