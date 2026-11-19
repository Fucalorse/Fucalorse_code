#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=1e7,MOD=998244353;
const LL INF=1e18;

LL n;

void solve()
{
    cin>>n;

    vector<LL>fac;

    LL k=n+1;
    for(LL i=1;i*i<=k;i++)
    {
        if(k%i!=0) continue;

        fac.push_back(i);
        if(i*i!=k) fac.push_back(k/i);
    }

    sort(fac.begin(),fac.end());

    vector<pair<LL,LL>>op;
    op.push_back({1,0});

    for(int i=1;i<(int)fac.size();i++)
    {
        LL y=fac[i];
        LL now=INF;

        for(auto &[x,cost]:op)
            now=min(now,(y-1)/x+cost);

        if(now==op.back().second) op.back().first=y;
        else op.push_back({y,now});
    }

    cout<<op.back().second<<endl;
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