#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,INF=2e9;

int n,m;
int x[MAX],s[MAX],depth[MAX],ans[MAX];

void dfs_depth(int ch,int fa,vector<vector<int>> &adj)
{
    depth[ch]=depth[fa]+1;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs_depth(to,ch,adj);
    }
}

void dfs(int ch,int fa,vector<map<int,vector<int>>> &f,vector<vector<int>> &adj)
{
    set<int>st;
    auto &cur=f[ch];

    for(auto &[pos,vec]:cur)
        if((int)vec.size()>=2) st.insert(pos);

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,f,adj);

        auto &pre=f[to];
        if(cur.size()<pre.size()) swap(cur,pre);

        for(auto &[pos,vec]:pre)
        {
            int len=cur[pos].size()+vec.size();
            if(len>=2) st.insert(pos);
            else
            {
                for(auto &val:vec)
                    cur[pos].push_back(val);
            }
        }
    }

    for(auto &del_id:st)
        cur[del_id].clear();
}

void solve()
{
    cin>>n>>m;

    vector<map<int,vector<int>>>f(n+1);
    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_depth(1,0,adj);

    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>s[i];
        int now=depth[x[i]]+s[i];
        f[x[i]][now].push_back(i);
    }

    dfs(1,0,f,adj);

    for(auto &[pos,vec]:f[1])
        for(auto &survive:vec)
            ans[survive]=1;

    for(int i=1;i<=m;i++)
        cout<<ans[i];
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ D.cpp -o out && ./out < in.txt