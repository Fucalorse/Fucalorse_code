#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=1e7,MOD=998244353,INF=2e9;

int a,b,c;

void solve()
{
    cin>>a>>b>>c;

    auto update=[&]()
    {
        vector<int>op;
        op.push_back(a);
        op.push_back(b);
        op.push_back(c);

        sort(op.begin(),op.end());

        a=op[0],b=op[1],c=op[2];
    };

    int ans=0;
    while(1)
    {
        if(a==b||a==c||b==c) break;

        update();
        a++,c--;

        ++ans;
    }

    cout<<ans<<endl;
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