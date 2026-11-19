#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=4e5,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

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

int n,k;
int a[MAX],maxn[MAX],f[MAX],sz[MAX];
LL fac[MAX],ifac[MAX];

LL C(int n,int m) { return fac[n]*ifac[n-m]%MOD*ifac[m]%MOD; }
LL A(int n,int m) { return fac[n]*ifac[n-m]%MOD; }

void create()
{
    fac[0]=1;
    for(int i=1;i<=LEN;i++)
        fac[i]=fac[i-1]*i%MOD;

    ifac[LEN]=qpow(fac[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        ifac[i]=ifac[i+1]*(i+1)%MOD;
}

void dfs(int ch,int fa,vector<vector<int>>& adj)
{
    maxn[ch]=a[ch];
    f[ch]=fa;
    sz[ch]=1;
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);
        maxn[ch]=max(maxn[ch],maxn[to]);
        sz[ch]+=sz[to];
    }
}

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root=1,global_max=a[root];
    for(int i=2;i<=n;i++)
        if(a[i]>a[root])
        {
            root=i;
            global_max=a[i];
        }
    dfs(root,0,adj);

    LL ans=0,base=qpow(A(n-1,k),MOD-2)*A(k,k)%MOD;
    auto update=[&](int edge_cnt,int max_val)->void
    {
        if(edge_cnt>k) return;

        int rest=n-2-edge_cnt;
        LL p=C(rest,k-edge_cnt)*base%MOD;

        ans=(ans+1LL*max_val*p%MOD)%MOD;
    };

    for(int ch=1;ch<=n;ch++)
    {
        if(ch==root) continue;
        update(sz[ch]-1,maxn[ch]);
        update(n-1-sz[ch],global_max);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}