#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct fucalorse
{
    private:
        int n;
        vector<LL>op;
    public:
        fucalorse(int _n)
        {
            n=_n;
            op.assign(n+3,0LL);
        }
        
        void update(int pos,LL k)
        {
            for(int i=pos;i<=n;i+=i&-i)
                op[i]=(op[i]+k)%MOD;
        }

        LL query(int pos)
        {
            LL ans=0;
            for(int i=pos;i;i-=i&-i)
                ans=(ans+op[i])%MOD;
            return ans;
        }

        LL query_range(int l,int r) { return (query(r)-query(l-1)+MOD)%MOD; }
};

int n;
int maxn[MAX],from[MAX];

void dfs(int ch,int fa,vector<vector<int>>& adj)
{
    maxn[ch]=-INF;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        
        if(!fa) from[to]=to;
        else from[to]=from[ch];
        dfs(to,ch,adj);
        maxn[ch]=max(maxn[ch],max(maxn[to],to));
    }
}

void solve()
{
    cin>>n;

    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(n,0,adj);

    int st=1;
    for(int i=1;i<=n;i++)
        if((int)adj[i].size()==1) st=i;

    set<int>op;
    vector<int>other(n+1,INF);
    fucalorse fu(n);
    vector<LL>dp(n+1,0LL);
    dp[st]=1,fu.update(st,dp[st]);

    for(auto &to:adj[n])
        op.insert(max(maxn[to],to));

    for(auto &to:adj[n])
    {
        op.erase(max(maxn[to],to));
        if(op.size()) other[to]=*op.rbegin();
        op.insert(max(maxn[to],to));
    }

    for(int i=st+1;i<n;i++)
    {
        if(i<maxn[i]) continue;
        int l=maxn[i]+1,r=i-1;
        if(l<=r)
        {
            dp[i]=fu.query_range(l,r);
            fu.update(i,dp[i]);

            if(i>other[from[i]]) dp[n]=(dp[n]+dp[i])%MOD;
        }
    }

    if(st!=n&&st>other[from[st]]) dp[n]=(dp[n]+dp[st])%MOD;

    cout<<dp[n]<<endl;
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