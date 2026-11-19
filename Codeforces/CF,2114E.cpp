#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;
const LL inf=1e15;

int t,n;
int f[MAX];
LL a[MAX],minn[MAX],maxn[MAX];
vector<int>p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

void dfs(int ch,int fa)
{
    f[ch]=fa;
    maxn[ch]=minn[ch]=a[ch];
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        maxn[ch]=max(maxn[ch],a[ch]-minn[fa]);
        minn[ch]=min(minn[ch],a[ch]-maxn[fa]);
        dfs(to,ch);
    }
}

void solve()
{
    cin>>n;
    clear();
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    dfs(1,0);
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<maxn[i]<<' '<<minn[i]<<endl;
    for(int u=1;u<=n;u++)
        cout<<max(a[u],a[u]-minn[f[u]])<<" ";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}