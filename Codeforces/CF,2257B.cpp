#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n,m;
LL a[MAX],b[MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];

    LL numa=0,numb=0;
    for(int i=1;i<n;i++)
        numa+=a[i]-a[i+1]+1;
    for(int i=1;i<m;i++)
        numb+=b[i]-b[i+1]+1;
    
    numa+=a[n],numb+=b[m];
    
    // cout<<numa<<' '<<numb<<endl;

    if(numa>=numb) cout<<1<<endl;
    else cout<<2<<endl;
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