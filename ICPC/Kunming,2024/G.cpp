#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

LL a,b;

void solve()
{
    cin>>a>>b;

    int ans=INF;
    auto dfs=[&](auto &&self,LL u,LL v,int cnt)->void
    {
        if(!u||!v)
        {
            ans=min(ans,cnt+1);
            return;
        }

        if(cnt+2>26||cnt+2>=ans) return;
        
        LL g=__gcd(u,v);
        if(u) self(self,u-g,v,cnt+1);
        if(v) self(self,u,v-g,cnt+1);
    };
    dfs(dfs,a,b,0);

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