#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=5090,LEN=5000,G=3,MOD=998244353,INF=2e9;

LL qpow(LL a,LL p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ans;
}

int n;
int sz[MAX],pre_id[MAX],suf_id[MAX];
LL dp[MAX][MAX],pre_sum[MAX],suf_sum[MAX],W[MAX][MAX],L[MAX];
LL fac[MAX],inv[MAX];

void create()
{
    fac[0]=1;
    for(int i=1;i<=LEN;i++)
        fac[i]=fac[i-1]*i%MOD;

    inv[LEN]=qpow(fac[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL C(int n,int m)
{
    if(n<0||m<0||n<m) return 0;
    else return fac[n]*inv[n-m]%MOD*inv[m]%MOD;
}
LL A(int n,int m)
{
    if(n<0||m<0||n<m) return 0;
    else return fac[n]*inv[n-m]%MOD;
}

void dfs_first(int ch,int fa,vector<vector<int>>& adj)
{
    L[ch]=1;
    sz[ch]=1;
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs_first(to,ch,adj);
        sz[ch]+=sz[to];
        L[ch]=L[ch]*(L[to]*inv[sz[to]]%MOD)%MOD;
    }
    L[ch]=L[ch]*fac[sz[ch]-1]%MOD;

    int pre=0;
    pre_sum[0]=suf_sum[0]=1;
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        pre_sum[to]=pre_sum[pre]*L[to]%MOD*inv[sz[to]]%MOD;
        pre_id[to]=pre;
        pre=to;
    }

    pre=0;
    for(auto it=adj[ch].rbegin();it!=adj[ch].rend();++it)
    {
        int to=*it;
        if(to==fa) continue;
        suf_sum[to]=suf_sum[pre]*L[to]%MOD*inv[sz[to]]%MOD;
        suf_id[to]=pre;
        pre=to;
    }

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        int t=sz[ch]-1-sz[to];
        W[ch][to]=fac[t]*pre_sum[pre_id[to]]%MOD*suf_sum[suf_id[to]]%MOD;
    }
}

void dfs_second(int ch,int fa,vector<vector<int>>& adj)
{
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        
        LL sum=0;
        int t=sz[ch]-sz[to]-1;
        for(int k=1;k<=n-sz[to]+1;k++)
        {
            dp[to][k]=sum;
            LL now;
            if(n-sz[to]-k<t) now=0;
            else now=dp[ch][k]*W[ch][to]%MOD*C(n-sz[to]-k,t)%MOD;
            sum=(sum+now)%MOD;
        }

        dfs_second(to,ch,adj);
    }
}

void solve()
{
    cin>>n;

    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++)
    {
        int fa;
        cin>>fa;
        adj[i].push_back(fa);
        adj[fa].push_back(i);
    }

    dfs_first(1,0,adj);
    dp[1][1]=1;
    dfs_second(1,0,adj);

    for(int i=1;i<=n;i++)
    {
        if(n-i+1>=sz[i])
        {
            LL ans=dp[i][i]*C(n-i,sz[i]-1)%MOD*L[i]%MOD;
            cout<<ans<<' ';
        }
        else cout<<0<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}