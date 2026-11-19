#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

struct number
{
    int cnt,val;
}op[MAX];

int t,n;
int a[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=2;i<=n;i++)
        if(abs(a[i]-a[i-1])==gcd(a[i],a[i-1])) ++ans;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}