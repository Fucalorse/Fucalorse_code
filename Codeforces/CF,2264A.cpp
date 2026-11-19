#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int p[MAX];

void solve()
{
    cin>>n;

    vector<pair<int,int>>rest;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        if(p[i]!=i) rest.push_back({i,p[i]});
    }

    int len=rest.size();
    for(int i=0;i<len;i++)
    {
        auto [pl,vl]=rest[i];
        auto [pr,vr]=rest[len-i-1];

        if(pl!=vr||pr!=vl)
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