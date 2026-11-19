#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

LL gcd(LL a,LL b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

LL a,b;
int ans;

void dfs(LL a,LL b,int cnt)
{
    if(!a||!b)
    {
        ans=min(ans,cnt+1);
        return;
    }

    if(cnt+2>=ans) return;

    LL g=gcd(a,b);
    if(a) dfs(a-g,b,cnt+1);
    if(b) dfs(a,b-g,cnt+1);
}

void solve()
{
    cin>>a>>b;

    ans=INF;
    dfs(a,b,0);
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