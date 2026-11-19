#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>0) ++cnt;
    }

    if(n&1)
    {
        cout<<"NO"<<endl;
        return;
    }

    int now=abs(n-2*cnt);
    if(now%4==0) cout<<"YES"<<endl;
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