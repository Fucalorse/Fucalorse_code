#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL M=1e18;

template <typename T>
T __lcm(T a,T b) { return a/__gcd(a,b)*b; }

int n,q;
int f[MAX];
LL l[MAX],depth[MAX];

void dfs_depth(int ch,vector<vector<int>>& adj)
{
    for(auto &to:adj[ch])
    {
        depth[to]=depth[ch]+l[to];
        dfs_depth(to,adj);
    }
}

int dfs(int ch,LL r,LL lcm,vector<vector<int>>& dp,vector<vector<int>>& adj)
{
    if(adj[ch].empty()) return ch;

    if(lcm>M)
    {
        int pos=ch;
        while(adj[pos].size())
        {
            int nxt=(r+depth[pos])%adj[pos].size();
            pos=adj[pos][nxt];
        }
        return pos;
    }

    if(lcm%adj[ch].size()==0)
    {
        int to=(r+depth[ch])%adj[ch].size();
        return dfs(adj[ch][to],r,lcm,dp,adj);
    }
    else
    {
        int g=__gcd(lcm,(LL)adj[ch].size());
        int s=(int)adj[ch].size()/g;

        i128 val=(i128)lcm*s;
        LL nxt_lcm=val>M?M+1:(LL)val;

        for(int k=0;k<s;k++)
        {
            i128 nr=(i128)r+(i128)k*lcm;
            if(nr>M) break;

            int to=(r+k*lcm+depth[ch])%adj[ch].size();
            LL nxt_r=(LL)nr;
            dp[ch][to]=dfs(adj[ch][to],nxt_r,nxt_lcm,dp,adj);
        }
    }

    return ch;
}

void solve()
{
    cin>>n>>q;

    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>f[i];
        adj[f[i]].push_back(i);
    }

    for(int i=2;i<=n;i++)
        cin>>l[i];

    vector<vector<int>>dp(n+1);
    for(int i=1;i<=n;i++)
        dp[i].assign((int)adj[i].size(),0);

    dfs_depth(1,adj);
    int st=dfs(1,0,1,dp,adj);
    while(q--)
    {
        LL m;
        cin>>m;

        int pos=st;
        while(adj[pos].size())
        {
            int nxt=(m+depth[pos])%adj[pos].size();
            pos=dp[pos][nxt];
        }

        cout<<pos<<' ';
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