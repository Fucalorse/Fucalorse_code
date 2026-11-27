#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    auto cal_other_side=[&](LL mid,LL one_side)->LL { return mid*2-one_side; };

    for(int i=1;i<=n;i++)
        cin>>a[i];

    LL cur=0;
    for(int i=n;i>=1;i--)
        cur=cal_other_side(a[i],cur);

    cout<<(cur/2)<<endl;
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