#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;

void solve()
{
    cin>>n;

    array<int,3>f={};
    for(int i=2;i<=2*n;i++)
        f[i%3]=i;

    vector<int>ans;
    for(int col=0;col<=2;col++)
    {
        int now=(col+(int)ans.size())%3;
        for(int i=f[now];i>=2;i-=2)
            ans.push_back(i);
    }
    
    cout<<ans.size()<<endl;
    for(auto &cur:ans)
        cout<<cur<<' ';
    cout<<endl;
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