#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n,m,k,q;

void solve()
{
    cin>>n>>m>>k>>q;

    set<int>vis;
    vector<set<pair<int,int>>>adj(n+1),st(k+1);

    for(int i=1;i<=m;i++)
    {
        int u,v,k;
        cin>>u>>v>>k;
        adj[u].insert({v,k});
    }

    auto add=[&](int pos)
    {
        if(vis.count(pos)) return;
        vis.insert(pos);

        for(auto &[to,id]:adj[pos])
            st[id].insert({pos,to});
    };
    add(1);

    while(q--)
    {
        int opt;
        cin>>opt;

        if(opt==1)
        {
            int u,v,k;
            cin>>u>>v>>k;

            if(vis.count(u)||vis.count(v)) st[k].insert({u,v});
            else adj[u].insert({v,k});
        }
        else if(opt==2)
        {
            int u,v,k;
            cin>>u>>v>>k;

            if(vis.count(u)||vis.count(v)) st[k].erase({u,v});
            else adj[u].erase({v,k});
        }
        else
        {
            int k;
            cin>>k;

            set<pair<int,int>>cur;
            cur.swap(st[k]);

            for(auto &[u,v]:cur)
                add(v);

            cout<<vis.size()<<endl;
        }
    }
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