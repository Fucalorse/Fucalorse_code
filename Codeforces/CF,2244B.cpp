#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

int T,n;
LL a[MAX],sum[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }

    if(sum[n]<1LL*(1+n)*n/2)
    {
        cout<<"NO"<<endl;
        return;
    }

    for(int i=1;i<=n;i++)
    {
        LL now=1LL*(1+i)*i/2;
        if(sum[i]<now)
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

    cin>>T;
    while(T--) solve();

    return 0;
}