#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

istream& operator>>(istream &in,i128 &x)
{
    string s;
    in>>s;

    x=0;
    int f=1;

    for(auto &cur:s)
    {
        if(cur=='-') f=-1;
        else x=x*10+cur-'0';
    }

    if(f<0) x=-x;

    return in;
}

ostream& operator<<(ostream &out,i128 x)
{
    if(!x)
    {
        out<<0;
        return out;
    }

    if(x<0)
    {
        out<<'-';
        x=-x;
    }

    string s;
    while(x)
    {
        s.push_back(x%10+'0');
        x/=10;
    }

    reverse(s.begin(),s.end());
    out<<s;

    return out;
}

int n;
int a[MAX],sz[MAX];
i128 f2[MAX],f3[MAX];

void dfs(int ch,int fa,vector<vector<int>> &adj)
{
    f2[ch]=f3[ch]=0;
    sz[ch]=1;

    vector<int>rest;
    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);
        sz[ch]+=sz[to];
        rest.push_back(sz[to]);
    }
    if(n-sz[ch]) rest.push_back(n-sz[ch]);

    i128 total=0;
    for(auto &cur:rest)
    {
        f3[ch]+=(i128)f2[ch]*cur;
        f2[ch]+=(i128)total*cur;
        total+=cur;
    }
}

void solve()
{
    cin>>n;

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

    dfs(1,0,adj);

    i128 ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=sqrt(a[i]);
        if(x*x==a[i]) ans+=f2[i]+f3[i];
    }

    cout<<ans<<endl;
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