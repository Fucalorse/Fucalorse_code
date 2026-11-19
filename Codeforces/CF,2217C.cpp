#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=2e5,MOD=1e9+7,INF=2e9;

LL gcd(LL a,LL b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

LL lcm(LL a,LL b) { return a/gcd(a,b)*b; }

LL n,m,a,b;

void solve()
{
    cin>>n>>m>>a>>b;

    LL p=n/gcd(n,a),q=m/gcd(m,b);
    LL T=lcm(p,q);

    LL cnt;
    if(gcd(p,q)==1) cnt=T;
    else cnt=2*T;

    if(cnt==n*m) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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