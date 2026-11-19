#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    vector<int>f(n+3);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        LL l=1LL*i*a[i],r=1LL*(a[i]+1)*i-1;
        if(l<=n)
        {
            ++f[l];
            --f[min(r+1,1LL*n+1)];
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(i) f[i]+=f[i-1];
        if(!f[i]) ++cnt;
    }

    cout<<cnt<<endl;
    for(int i=0;i<n;i++)
        if(!f[i]) cout<<i<<' ';
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