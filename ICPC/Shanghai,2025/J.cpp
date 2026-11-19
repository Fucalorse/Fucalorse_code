#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

struct Node
{
    int nxt[9],fa,dep;
    vector<pair<int,int>>state;
    Node()
    {
        memset(nxt,0,sizeof(nxt));
        fa=dep=0;
    }
};

int n,m,k;

void solve()
{
    cin>>n>>m>>k;

    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        adj[u].push_back({v,val});
    }

    for(int i=1;i<=n;i++)
        sort(adj[i].begin(),adj[i].end(),[&](const pair<int,int>& a,const pair<int,int>& b){
            return a.second<b.second;
        });

    vector<Node>op;
    op.emplace_back();

    auto update=[&](int pos,int u,int val,int vec_id)
    {
        if(!op[pos].nxt[val])
        {
            int id=op.size();
            op.emplace_back();
            op[pos].nxt[val]=id;
            op[op[pos].nxt[val]].fa=pos;
            op[op[pos].nxt[val]].dep=op[pos].dep+1;
        }
        op[op[pos].nxt[val]].state.push_back({u,vec_id});
    };

    for(int u=1;u<=n;u++)
        if(adj[u].size()) update(0,u,adj[u][0].second,0);

    int total=0;
    auto dfs=[&](auto &&self,int ch)->void
    {
        if(total==k) return;

        for(int i=0;i<(int)op[ch].state.size();i++)
        {
            auto [u,pos]=op[ch].state[i];
            int v=adj[u][pos].first;

            if(pos+1<(int)adj[u].size())
                update(op[ch].fa,u,adj[u][pos+1].second,pos+1);
            if(adj[v].size())
                update(ch,v,adj[v][0].second,0);

            ++total;
            cout<<op[ch].dep<<endl;
            if(total==k) return;
        }

        for(int val=1;val<=8;val++)
            if(op[ch].nxt[val]) self(self,op[ch].nxt[val]);
    };
    dfs(dfs,0);

    for(int i=total+1;i<=k;i++)
        cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}