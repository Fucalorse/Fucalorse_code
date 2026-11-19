#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5e5+90,mod=998244353;

int n;
LL cnt[MAX],s[MAX],num[MAX],g[MAX];
int f[MAX],depth[MAX];
vector<int>p[MAX];

LL cal(LL a,int p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=(ans*a)%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ans;
}

void dfs(int ch,int fa)
{
    f[ch]=fa;
    depth[ch]=depth[fa]+1;
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
    }
    if(ch!=1) cnt[ch]=(depth[ch]+p[ch].size()-2)%mod;
    else cnt[ch]=(depth[ch]+p[ch].size()-1)%mod;
    num[ch]=cal(cnt[ch],mod-2);
}

void find(int pos)
{
    s[pos]=g[f[pos]]*num[pos]%mod;
    g[pos]=(1+g[f[pos]])*num[pos]%mod;
    for(auto &to:p[pos])
    {
        if(to==f[pos]) continue;
        find(to);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    dfs(1,0);
    find(1);
    // for(int i=1;i<=n;i++)
    //     cout<<cnt[i]<<' ';
    // cout<<endl;
    LL C=1,P=0;
    for(int i=1;i<=n;i++)
    {
        C=(C*cnt[i])%mod;
        P=(P+s[i])%mod;
    }
    cout<<(C*P)%mod<<endl;
    return 0;
}