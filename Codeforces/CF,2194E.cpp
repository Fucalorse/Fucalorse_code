#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m;

void print(const vector<vector<LL>>& op)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<op[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}

void solve()
{
    cin>>n>>m;

    vector<vector<LL>>a(n+1,vector<LL>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];

    vector<vector<LL>>f(n+3,vector<LL>(m+3,-LINF)),g(n+3,vector<LL>(m+3,-LINF));
    f[0][1]=f[1][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i==1) f[i][j]=f[i][j-1]+a[i][j];
            else if(j==1) f[i][j]=f[i-1][j]+a[i][j];
            else f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
        }

    g[n][m+1]=g[n+1][m]=0;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
        {
            if(i==n) g[i][j]=g[i][j+1]+a[i][j];
            else if(j==m) g[i][j]=g[i+1][j]+a[i][j];
            else g[i][j]=max(g[i+1][j],g[i][j+1])+a[i][j];
        }

    vector<LL>max1(n+m+1,-LINF),max2(n+m+1,-LINF);
    vector<pair<int,int>>pos(n+m+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int k=i+j;
            LL now=f[i][j]+g[i][j]-a[i][j];
            if(now>max1[k])
            {
                max2[k]=max1[k];
                max1[k]=now;
                pos[k]={i,j};
            }
            else if(now>max2[k]) max2[k]=now;
        }

    LL ans=LINF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            LL now=(f[i][j]+g[i][j]-a[i][j]==max1[i+j])?max2[i+j]:max1[i+j];
            now=max(now,f[i][j]+g[i][j]-3*a[i][j]);
            ans=min(ans,now);
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