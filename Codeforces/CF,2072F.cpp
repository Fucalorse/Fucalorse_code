#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90;

int T,n;
LL k;

void solve()
{
    cin>>n>>k;

    auto dis=[&](int n,int m)
    {
        if((n&m)==m) return true;
        else return false;
    };

    for(int i=1;i<=n;i++)
    {
        if(dis(n-1,i-1)) cout<<k<<' ';
        else cout<<0<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}