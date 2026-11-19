#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
int p[MAX],sz[MAX];
LL cost[MAX],h[MAX];

void dfs_weight(int ch,int fa,vector<vector<int>> &adj)
{
    cost[ch]=0;
    sz[ch]=1;
    priority_queue<LL,vector<LL>,greater<LL>>q;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;

        dfs_weight(to,ch,adj);

        sz[ch]+=sz[to];
        cost[ch]+=cost[to];
        q.push(sz[to]);
    }

    if((int)q.size()==1)
    {
        cost[ch]+=q.top();
        return;
    }

    while((int)q.size()>1)
    {
        LL a=q.top();q.pop();
        LL b=q.top();q.pop();

        cost[ch]+=a+b;
        q.push(a+b);
    }
}

void dfs_height(int ch,int fa,vector<vector<int>> &adj)
{
    h[ch]=0;
    if(adj[ch].empty()) return;

    priority_queue<LL,vector<LL>,greater<LL>>q;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;

        dfs_height(to,ch,adj);
        q.push(h[to]);
    }

    if((int)q.size()==1)
    {
        h[ch]=q.top()+1;
        return;
    }

    while((int)q.size()>1)
    {
        LL a=q.top();q.pop();
        LL b=q.top();q.pop();

        q.push(max(a,b)+1);
    }

    h[ch]=q.top();
}

void solve()
{
    cin>>n;

    vector<vector<int>>adj(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
        adj[p[i]].push_back(i);
    }

    dfs_weight(1,0,adj);
    dfs_height(1,0,adj);

    cout<<h[1]<<' '<<cost[1]<<endl;
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