#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n,m,d;
LL p[MAX],r[MAX],f[MAX];

void solve()
{
    cin>>n>>m>>d;

    for(int i=1;i<=m;i++)
    {
        cin>>p[i]>>r[i];
        f[i]=f[i-1]+r[i];
    }

    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
        {
            LL tar=p[i]+p[j]+1;
            LL x=tar%n,y=tar/n;

            int pos=upper_bound(p+1,p+m+1,x)-p-1;
            LL now=f[i]+f[j]-f[pos]-d-y*f[m];
            if(now>0)
            {
                cout<<"YES"<<endl;
                return;
            }
        }

    cout<<"NO"<<endl;
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