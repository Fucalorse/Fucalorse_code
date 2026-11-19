#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,mod=998244353;

int t,n;
LL a[MAX],ans[MAX],f[MAX],g[MAX],s[MAX];
vector<int>p[MAX];

void dfs(int ch,int fa)
{
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
        g[ch]=(g[ch]+f[ch]*s[to]%mod)%mod;
        f[ch]=(f[ch]+s[ch]*s[to]%mod)%mod;
        s[ch]=(s[ch]+s[to])%mod;
        ans[ch]=(ans[ch]+ans[to])%mod;
    }
    s[ch]+=a[ch];
    ans[ch]=(ans[ch]+g[ch]+f[ch]*a[ch]%mod)%mod;
}

void clear()
{
    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        ans[i]=s[i]=g[i]=f[i]=0;
    }
}

void solve()
{
    cin>>n;
    clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0);
    cout<<ans[1]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}