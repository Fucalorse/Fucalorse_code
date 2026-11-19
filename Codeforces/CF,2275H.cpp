#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=1e9+7,INF=2e9;
const LL LINF=1e18;

int n,m;

LL cal(const vector<vector<LL>>& a)
{
    LL ans=0;
    vector<vector<LL>>f(n+1,vector<LL>(m+1,0LL));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j]=(f[i-1][j]+f[i][j-1]-f[i-1][j-1]+MOD)%MOD;
            if((1LL*i*j)&1)
            {
                LL now=a[i][j];
                if((i+j)&1) now=(-now+MOD)%MOD;
                f[i][j]=(f[i][j]+now)%MOD;
            }

            LL nx=n-i+1,ny=m-j+1;
            if((nx*ny)&1)
            {
                LL now=a[i][j];
                if((i+j)&1) now=(-now+MOD)%MOD;
                
                LL con=2*now%MOD*f[i][j]%MOD;
                if((1LL*i*j)&1) con=(con-now*now%MOD+MOD)%MOD;

                ans=(ans+con)%MOD;
            }
        }

    return ans;
}

void solve()
{
    cin>>n>>m;

    vector<vector<LL>>a(n+1,vector<LL>(m+1)),b(n+1,vector<LL>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            a[i][j]=(a[i][j]+MOD)%MOD;
            b[i][m-j+1]=a[i][j];
        }

    LL ans=(cal(a)+cal(b))%MOD;
    vector<vector<LL>>f(n+1,vector<LL>(m+1,0LL)),g(n+1,vector<LL>(m+1,0LL));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j]+=f[i][j-1];
            g[i][j]+=g[i-1][j];

            LL other=0;
            if((1LL*i*j)&1)
            {
                other=a[i][j];
                if((i+j)&1) other=(-other+MOD)%MOD;
            }

            LL nx=n-i+1,ny=m-j+1;
            if((nx*ny)&1)
            {
                LL now=a[i][j];
                if((i+j)&1) now=(-now+MOD)%MOD;
                
                LL con=2*now%MOD*((f[i][j]+g[i][j]+other)%MOD)%MOD;
                if((1LL*i*j)&1) con=(con-now*now%MOD+MOD)%MOD;

                ans=(ans-con+MOD)%MOD;
            }

            f[i][j]=(f[i][j]+other)%MOD;
            g[i][j]=(g[i][j]+other)%MOD;
        }

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