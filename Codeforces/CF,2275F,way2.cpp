#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+5,LEN=1e6,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int minp[MAX];
vector<int>op;
vector<vector<int>>prime_set(MAX);

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

    auto cal=[&](int num)
    {
        map<int,int>f;
        vector<int>vec;
        while(num!=1)
        {
            ++f[minp[num]];
            num/=minp[num];
        }
        for(auto &[val,cnt]:f)
            if(cnt&1) vec.push_back(val);
        return vec;
    };

    for(int i=2;i<=n;i++)
        prime_set[i]=cal(i);
}

int n;
int a[MAX];

void solve()
{
    cin>>n;

    map<vector<int>,int>cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[prime_set[a[i]]];
    }

    LL ans=0;
    map<int,int>f;

    auto update=[&](const vector<int>& vec)
    {
        for(auto &cur:vec)
        {
            f[cur]^=1;
            if(f[cur]==0) f.erase(cur);
        }

        if(f.size()>7) return;
        vector<int>prime;
        for(auto &[val,cnt]:f)
            prime.push_back(val);
        ans+=cnt[prime];
    };

    for(int i=1;i<=n;i++)
        update(prime_set[a[i]]);

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