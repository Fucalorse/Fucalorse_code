#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90;

int t,n,m;
bool galgame[MAX];
int cnt[MAX];
LL pre[MAX];
vector<pair<int,LL>>p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        cnt[i]=0,pre[i]=0;
        galgame[i]=false;
    }
}

void dfs(int ch,int fa)
{
    for(auto &[to,val]:p[ch])
    {
        if(to==fa) continue;
        pre[to]=val;
        dfs(to,ch);
        cnt[ch]+=cnt[to];
    }
    // cout<<ch<<' '<<cnt[ch]<<' ';
    if(galgame[ch]||(int)p[ch].size()==1) cnt[ch]=1;
    // cout<<cnt[ch]<<endl;
}

void solve()
{
    cin>>n>>m;
    clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        LL val;
        cin>>u>>v>>val;
        p[u].push_back({v,val});
        p[v].push_back({u,val});
    }
    for(int i=1;i<=m;i++)
    {
        int u;
        cin>>u;
        galgame[u]=true;
    }
    dfs(1,0);
    LL ans=0;
    // for(int i=1;i<=n;i++)
    //     cout<<cnt[i]<<' ';
    // cout<<endl;
    for(int i=2;i<=n;i++)
        ans+=max(0,cnt[i]-1)*pre[i];
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}