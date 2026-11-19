#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=18,INF=2e9;

int T,n;
LL ans[MAX],b[MAX];

LL gcd(LL a,LL b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

LL lcm(LL a,LL b) { return a/gcd(a,b)*b; }

void solve()
{
    cin>>n;

    if(n==1)
    {
        cout<<1<<endl;
        return;
    }

    if(n==2)
    {
        cout<<-1<<endl;
        return;
    }

    for(int i=1;i<=n-2;i++)
        b[i]=1LL<<i;
    LL x=1LL<<(n-2);
    b[n-1]=3*x/2,b[n]=3*x;
    LL S=lcm(lcm(b[n-2],b[n-1]),b[n]);

    for(int i=1;i<=n;i++)
        ans[i]=S/b[i];
    
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
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