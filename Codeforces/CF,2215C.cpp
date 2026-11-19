#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=29,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int n,s;
int b[MAX];

void solveA()
{
    cin>>n>>s;
    --s;

    vector<int>bit;
    while(s)
    {
        bit.push_back(s&1);
        s>>=1;
    }
    bit.resize(n-1,0);

    b[1]=0;
    for(int i=2;i<=n;i++)
        b[i]=bit[i-2];

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);

        if(b[u]^b[v]) cout<<u<<' '<<v<<endl<<flush;
        else cout<<v<<' '<<u<<endl<<flush;
    }
}

void solveB()
{
    cin>>n;

    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v,col;
        cin>>u>>v;

        if(u<v) col=1;
        else col=0;

        adj[u].push_back({v,col});
        adj[v].push_back({u,col});
    }

    vector<int>bit(n+1,0);
    auto dfs=[&](auto &&self,int ch,int fa)->void
    {
        for(auto &[to,col]:adj[ch])
        {
            if(to==fa) continue;
            bit[to]=bit[ch]^col;
            self(self,to,ch);
        }
    };
    dfs(dfs,1,0);

    int ans=0;
    for(int i=2;i<=n;i++)
        ans|=bit[i]<<(i-2);
    
    cout<<ans+1<<endl<<flush;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int t,q;
    cin>>t>>q;
    while(t--)
    {
        if(q==1) solveA();
        else solveB();
    }

    return 0;
}