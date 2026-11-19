#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m;
int A[MAX],c[MAX],nxt[MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>A[i];
    
    c[0]=0;
    for(int i=1;i<n;i++)
        c[i]=A[i+1]==0?i:c[A[i+1]-1];
    // for(int i=0;i<n;i++)
    //     cout<<c[i]<<' ';
    // cout<<endl;

    nxt[1]=0;
    for(int i=1,j=0;i<n;i++)
    {
        while(j&&c[i]!=c[j]) j=nxt[j];
        if(c[i]==c[j]) ++j;
        nxt[i+1]=j;
    }

    // for(int i=1;i<=n;i++)
    //     cout<<nxt[i]<<' ';
    // cout<<endl;

    for(int i=1;i<=n;i++)
        if(nxt[i]!=A[i])
        {
            cout<<0<<endl;
            return;
        }

    LL ans=1;
    vector<int>f(n+1,0);
    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(A[i]==0)
        {
            int rest=m-f[nxt[i-1]];
            if(rest<=0)
            {
                cout<<0<<endl;
                return;
            }
            // cout<<rest<<endl;
            ans=ans*rest%MOD;
        }
        f[i-1]=f[nxt[i-1]]+(nxt[i]==0);
    }

    // for(int i=1;i<=n;i++)
    //     cout<<f[i]<<' ';
    // cout<<endl;

    cout<<ans<<endl;
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