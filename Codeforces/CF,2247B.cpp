#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7;
const LL INF=1e15;

int n,k,m;
LL a[MAX];

void solve()
{
    cin>>n>>k>>m;

    if(k>m)
    {
        cout<<"NO"<<endl;
        return;
    }

    LL rest=m;
    for(int i=1;i<k;i++)
        a[i]=1,--rest;
    a[k]=rest;
    for(int i=k+1;i<=n;i++)
        a[i]=1;

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
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