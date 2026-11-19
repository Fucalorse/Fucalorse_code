#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e7+10,LEN=24,MOD=998244353,INF=2e9;

int n;
int minp[MAX],f[MAX],cnt[MAX];
LL c,pw[MAX];
vector<int>op;

void oula(int n)
{
    minp[1]=1,cnt[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            cnt[i]=1;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            cnt[i*j]=cnt[i]+1;
            if(i%j==0) break;
        }
    }
}

void solve()
{
    cin>>n>>c;

    oula(1e7);

    f[1]=1;
    for(int i=2;i<=LEN;i++)
        f[i]=op[i-2];

    pw[0]=1;
    for(int i=1;i<=n;i++)
        pw[i]=pw[i-1]*c%MOD;

    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        LL now=f[cnt[i]]*pw[i]%MOD;
        ans=(ans+now)%MOD;
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