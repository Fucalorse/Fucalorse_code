#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e7+90,MOD=1e9+7,INF=2e9,LEN=1e7;

int T,n;
int minp[MAX];
LL cost[MAX],f[MAX];
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

void create()
{
    oula(LEN);

    for(int i=3;i<=LEN;i++)
    {
        if(minp[i]==i) cost[i]=1LL*i*2;
        else cost[i]=i;
    }

    for(int i=2;i<=LEN;i++)
        f[i]=f[i-1]+cost[i];
}

void solve()
{
    cin>>n;

    cout<<f[n]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    cin>>T;
    while(T--) solve();

    return 0;
}