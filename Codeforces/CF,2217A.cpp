#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=2e5,MOD=1e9+7,INF=2e9;

int n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;

    int total=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        total+=a[i];
    }

    if(total&1) cout<<"YES"<<endl;
    else
    {
        if((n*k)&1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
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