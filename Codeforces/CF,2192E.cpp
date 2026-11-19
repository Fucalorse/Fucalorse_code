#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct Edge
{
    int to,id;
    bool inv;
};

int n;
int a[MAX],b[MAX];

void solve()
{
    cin>>n;

    vector<vector<Edge>>adj(n+1);
    vector<int>cnt(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        adj[a[i]].push_back({b[i],i,false});
        adj[b[i]].push_back({a[i],i,true});
        ++cnt[b[i]];
    }

    for(int i=1;i<=n;i++)
        if(cnt[i]&1)
        {
            cout<<-1<<endl;
            return;
        }

    vector<int>ans,cur(n+1,0);
    vector<bool>vis(n+1,false);
    for(int pos=1;pos<=n;pos++)
    {
        int u=pos;
        while(cur[u]<(int)adj[u].size())
        {
            auto [to,id,inv]=adj[u][cur[u]++];
            if(vis[id]) continue;
            vis[id]=true;
            if(inv) ans.push_back(id);
            u=to;
        }
    }

    cout<<ans.size()<<endl;
    for(auto &id:ans)
        cout<<id<<' ';
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