#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3090,MOD=998244353,LEN=3000;

int T,n;
int dist[MAX][MAX];
LL C[MAX][MAX],D[MAX],f[MAX];

void create()
{
    D[0]=1,D[1]=0;
    for(int i=2;i<=LEN;i++)
        D[i]=1LL*(i-1)*(D[i-1]+D[i-2])%MOD;

    C[0][0]=1;
    for(int i=1;i<=LEN;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }

    for(int i=0;i<=LEN;i++)
        for(int j=0;j<=i;j++)
        {
            LL now=C[i][j]*D[j+2]%MOD;
            f[i]=(f[i]+now)%MOD;
        }

    // for(int i=0;i<=10;i++)
    //     cout<<f[i]<<' ';
    // cout<<endl;
}

void dfs(int root,int ch,int fa,vector<vector<int>>& p)
{
    dist[root][ch]=dist[root][fa]+1;

    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        dfs(root,to,ch,p);
    }
}

void solve()
{
    cin>>n;

    vector<vector<int>>p(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;

        p[u].push_back(v);
        p[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        dist[i][0]=-1;
        dfs(i,i,0,p);
    }

    LL ans=1;
    for(int u=1;u<=n;u++)
        for(int v=u+1;v<=n;v++)
        {
            LL now=f[dist[u][v]-1];
            ans=(ans+now)%MOD;
        }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    cin>>T;
    while(T--) solve();

    return 0;
}