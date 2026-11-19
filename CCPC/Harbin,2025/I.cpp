#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m;

void solve()
{
    cin>>n>>m;

    vector<map<int,int>>f(3),g(3);
    set<int>px,py,pz;
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        ++f[0][x];
        ++f[1][y];
        ++f[2][z];
        px.insert(x);
        py.insert(y);
        pz.insert(z);
    }

    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        ++g[0][x];
        ++g[1][y];
        ++g[2][z];
        px.insert(x);
        py.insert(y);
        pz.insert(z);
    }

    for(auto &x:px)
    {
        int now=f[0][x]+g[0][x];
        if(now&1)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    for(auto &y:py)
    {
        int now=f[1][y]+g[1][y];
        if(now&1)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    for(auto &z:pz)
    {
        int now=f[2][z]+g[2][z];
        if(now&1)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
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