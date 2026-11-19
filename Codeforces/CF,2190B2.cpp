#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    vector<vector<LL>>f(n+1,vector<LL>(4,0LL)),g(n+1,vector<LL>(4,0LL));
    vector<vector<LL>>nf(n+1,vector<LL>(4,0LL)),ng(n+1,vector<LL>(4,0LL));
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        nf=f,ng=g;

        if(s[i]==')')
        {
            for(int j=1;j<=n;j++)
            {
                for(int col=1;col<=3;col++)
                {
                    nf[j-1][col]=(nf[j-1][col]+f[j][col])%MOD;
                    ng[j-1][col]=(ng[j-1][col]+g[j][col]+f[j][col])%MOD;
                }
                nf[j-1][1]=(nf[j-1][1]+f[j][0])%MOD;
                ng[j-1][1]=(ng[j-1][1]+g[j][0]+f[j][0])%MOD;
            }
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                for(int col=1;col<=3;col++)
                {
                    nf[j+1][min(3,col+1)]=(nf[j+1][min(3,col+1)]+f[j][col])%MOD;
                    ng[j+1][min(3,col+1)]=(ng[j+1][min(3,col+1)]+g[j][col]+f[j][col])%MOD;
                }

                nf[j+1][0]=(nf[j+1][0]+f[j][0])%MOD;
                ng[j+1][0]=(ng[j+1][0]+g[j][0]+f[j][0])%MOD;
            }
        }

        swap(f,nf);
        swap(g,ng);
    }

    cout<<((g[0][3]-2*f[0][3])%MOD+MOD)%MOD<<endl;
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