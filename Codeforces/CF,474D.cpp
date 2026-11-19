#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,INF=2e9,MOD=1e9+7,LEN=1e5;

int T,k;
LL dp[MAX],f[MAX];

void solve()
{
    int l,r;
    cin>>l>>r;
    
    cout<<(f[r]-f[l-1]+MOD)%MOD<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T>>k;

    dp[0]=1;
    for(int i=1;i<=LEN;i++)
    {
        dp[i]=(dp[i]+dp[i-1])%MOD;
        if(i>=k) dp[i]=(dp[i]+dp[i-k])%MOD;
    }

    for(int i=1;i<=LEN;i++)
        f[i]=(f[i-1]+dp[i])%MOD;

    while(T--) solve();

    return 0;
}