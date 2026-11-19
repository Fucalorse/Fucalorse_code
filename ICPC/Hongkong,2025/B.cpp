#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int n;

void solve()
{
    cin>>n;

    LL total=0;
    vector<vector<pair<int,LL>>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        LL val;
        cin>>u>>v>>val;
        total+=2*val;
        adj[u].push_back({v,val});
        adj[v].push_back({u,val});
    }

    int m=2*n-2;
    vector<int>sz(n+1,0);
    vector<vector<LL>>A(n+1,vector<LL>(m+1,-LINF));
    vector<vector<LL>>B(n+1,vector<LL>(m+1,-LINF));
    vector<vector<LL>>C(n+1,vector<LL>(m+1,-LINF));

    auto dfs=[&](auto &&self,int ch,int fa)->void
    {
        A[ch][0]=B[ch][0]=C[ch][0]=0;
        sz[ch]=1;
        for(auto &[to,val]:adj[ch])
        {
            if(to==fa) continue;
            self(self,to,ch);

            int S=2*(sz[ch]-1),T=2*(sz[to]-1);
            vector<LL>oldA=A[ch],oldB=B[ch],oldC=C[ch];
            for(int i=0;i<=S;i++)
            {
                if(oldA[i]!=-LINF) A[ch][i+T+2]=max(A[ch][i+T+2],oldA[i]+A[to][T]+2*val);
                if(oldB[i]!=-LINF) B[ch][i+T+2]=max(B[ch][i+T+2],oldB[i]+A[to][T]+2*val);
                if(oldC[i]!=-LINF) C[ch][i+T+2]=max(C[ch][i+T+2],oldC[i]+A[to][T]+2*val);
            }

            for(int i=0;i<=S;i++)
                for(int j=0;j<=T;j++)
                {
                    if(i+j+1>2*n-2) break;

                    if(oldA[i]!=-LINF&&B[to][j]!=-LINF)
                        B[ch][i+j+1]=max(B[ch][i+j+1],oldA[i]+B[to][j]+val);
                    if(oldB[i]!=-LINF&&B[to][j]!=-LINF)
                        C[ch][i+j+1]=max(C[ch][i+j+1],oldB[i]+B[to][j]+val);
                }

            sz[ch]+=sz[to];
        }
    };
    dfs(dfs,1,0);

    for(int k=0;k<=2*n-2;k++)
    {
        LL maxn=0;
        for(int u=1;u<=n;u++)
            maxn=max(maxn,max({A[u][k],B[u][k],C[u][k]}));
        cout<<total-maxn<<' ';
    }
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