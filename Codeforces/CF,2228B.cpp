#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T;
LL n,x1,x2,k;

void solve()
{
    cin>>n>>x1>>x2>>k;

    if(n<=3) cout<<1<<endl;
    else
    {
        if(x1<x2) cout<<k+min(llabs(x1-x2),llabs(x1+n-x2))<<endl;
        else cout<<k+min(llabs(x1-x2),llabs(x2+n-x1))<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}