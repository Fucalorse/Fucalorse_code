#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=4e5+90,LEN=26,MOD=998244353;

int n,m;
int cur[MAX],deg[MAX],ans[MAX];
bool vis_edge[MAX],vis_pos[MAX];
vector<pair<int,int>>p[MAX],path;

void dfs(int u,int edge_id)
{
    while(cur[u]<(int)p[u].size())
    {
        auto [v,id]=p[u][cur[u]++];

        if(vis_edge[id]) continue;
        vis_edge[id]=true;

        dfs(v,id);
    }

    vis_pos[u]=true;
    path.push_back({u,edge_id});
}

void clear()
{
    path.clear();

    for(int i=0;i<=n+1;i++)
    {
        cur[i]=deg[i]=0;
        vis_pos[i]=false;
        p[i].clear();
    }

    for(int i=0;i<=n+m+1;i++)
    {
        vis_edge[i]=false;
        ans[i]=0;
    }
}

void solve()
{
    cin>>n>>m;clear();

    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;

        p[u].push_back({v,i});
        p[v].push_back({u,i});
        deg[u]++,deg[v]++;
    }

    int edge_id=m;
    for(int i=1;i<=n;i++)
        if(deg[i]&1)
        {
            ++edge_id;
            p[i].push_back({n+1,edge_id});
            p[n+1].push_back({i,edge_id});
            deg[i]++,deg[n+1]++;
        }

    int tot=0;

    auto update=[&]()
    {
        vector<int>ste,stv,pos(n+2,-1);
        stv.push_back(path.front().first);
        pos[path.front().first]=0;

        for(int i=1;i<(int)path.size();i++)
        {
            auto [u,id]=path[i];

            // cout<<u<<" "<<pos[u]<<endl;
            if(pos[u]==-1)
            {
                stv.push_back(u);
                ste.push_back(id);
                pos[u]=(int)stv.size()-1;
            }
            else
            {
                int k=pos[u];
                ++tot;
                // cout<<k<<' ';

                for(int j=k;j<(int)ste.size();j++)
                    if(ste[j]<=m) ans[ste[j]]=tot;

                if(id<=m) ans[id]=tot;

                for(int j=k+1;j<(int)stv.size();j++)
                {
                    pos[stv[j]]=-1;
                    // cout<<stv[j]<<' ';
                }
                // cout<<endl<<endl;

                ste.resize(k);
                stv.resize(k+1);
            }
        }
    };
    // cout<<endl;

    for(int i=1;i<=n;i++)
    {
        if(vis_pos[i]) continue;

        path.clear();
        dfs(i,0);
        reverse(path.begin(),path.end());
        update();
    }

    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
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