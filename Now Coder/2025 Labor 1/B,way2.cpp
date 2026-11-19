#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=610,LEN=300;

int T,n,m;
LL C[MAX][MAX],f[MAX],S[MAX][MAX],g[MAX][MAX];

void create()
{
    C[0][0]=1;
    for(int i=1;i<=n*2;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%m;
    }

    S[0][0]=S[1][1]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            S[i][j]=(j*S[i-1][j]%m+S[i-1][j-1])%m;

    f[0]=1;
    for(int i=1;i<=n*2;i++)
        f[i]=f[i-1]*i%m;

    g[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            g[i][j]=S[i][j]*f[j]%m*C[n][i]%m;
}

void solve()
{
    cin>>n>>m;
    create();

    LL ans=f[2*n];
    for(int k=1;k<2*n;k++)
        for(int A=max(0,k-n);A<=min(k,n);A++)
        {
            int B=k-A;

            for(int c=1;c<=min(A,B);c++)
            {
                LL con1=g[A][c]*g[B][c]*2%m;
                LL con2=(g[A][c]*g[B][c+1]+g[A][c+1]*g[B][c])%m;
                LL now=(con1+con2)*f[2*n-k]%m;
                ans=(ans+now)%m;
            }

            LL now=(g[A][0]*g[B][1]+g[A][1]*g[B][0])%m*f[2*n-k]%m;
            ans=(ans+now)%m;
        }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}