#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define ULL unsigned long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e6,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

mt19937_64 rng(random_device{}());
uniform_int_distribution<ULL>dist(0,LONG_LONG_MAX);

int minp[MAX];
ULL Val[MAX],num_xor[MAX];
vector<int>op;

void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            Val[i]=dist(rng);
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }

    num_xor[1]=0;
    for(int i=2;i<=n;i++)
        num_xor[i]=num_xor[i/minp[i]]^Val[minp[i]];
}

int n;
int a[MAX];
ULL sum[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]^num_xor[a[i]];
    }

    LL ans=0;
    map<ULL,LL>cnt;

    for(int i=1;i<=n;i++)
        ++cnt[num_xor[a[i]]];

    for(int i=1;i<=n;i++)
        ans+=cnt[sum[i]];

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}