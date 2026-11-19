#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=3e5,G=3,MOD=998244353,INF=2e9;

int minp[MAX];
vector<int>op;

void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }
}

int n,x;
int a[MAX];

void solve()
{
    cin>>n>>x;

    map<int,LL>f;

    auto split=[&](int num)
    {
        set<int>prime;
        while(num!=1)
        {
            prime.insert(minp[num]);
            num/=minp[num];
        }
        return prime;
    };

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        set<int>prime=split(a[i]);

        for(auto &cur:prime)
            f[cur]+=a[i];
    }

    LL ans=0;
    set<int>st=split(x);
    for(auto &cur:st)
        ans=max(ans,f[cur]);

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