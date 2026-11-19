#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;
const LL inf=9e18;

int T,n;
LL a,ans;
int d[MAX];

void dfs(int cnt,LL sum)
{
    if(cnt>18) return;

    dfs(cnt+1,sum*10+d[1]);
    dfs(cnt+1,sum*10+d[2]);

    // cout<<sum<<' ';

    if(cnt) ans=min(ans,llabs(sum-a));
}

void solve()
{
    cin>>a>>n;

    for(int i=1;i<=n;i++)
        cin>>d[i];

    ans=inf;
    dfs(0,0);

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}