#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

int T,n,x,y;
int p[MAX];

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

void solve()
{
    cin>>n>>x>>y;

    for(int i=1;i<=n;i++)
        cin>>p[i];
    
    int g=gcd(x,y);
    for(int i=1;i<=n;i++)
        if(abs(p[i]-i)%g!=0)
        {
            cout<<"NO"<<endl;
            return;
        }

    cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}