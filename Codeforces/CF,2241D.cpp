#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
LL a[MAX],b[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
        cin>>b[i];

    for(int i=1;i<=n;i++)
    {
        if(a[i]>b[i])
        {
            cout<<"NO"<<endl;
            return;
        }

        LL now=llabs(a[i]-b[i]);
        a[i]=b[i];
        a[i+1]-=now;
    }

    cout<<"YES"<<endl;
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