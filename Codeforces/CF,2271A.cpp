#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int a,b;

int check(int step)
{
    int l=0,r=step;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        int now=2*mid-step;
        if(now==b) return step;
        if(2*mid-step<b) l=mid+1;
        else r=mid-1;
    }
    return INF;
}

void solve()
{
    cin>>a>>b;

    int ans=min(check(a),check(a+1));
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
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