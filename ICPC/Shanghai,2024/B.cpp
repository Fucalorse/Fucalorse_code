#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int n,m;
int p[MAX];

void solve()
{
    cin>>n>>m;

    vector<set<int>>adj(n+1);
    vector<vector<int>>g(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
        cin>>p[i];

    int pos=1;
    vector<int>st;
    vector<pair<int,int>>ans;
    st.push_back(p[pos]);

    auto remove=[&](int u)
    {
        for(auto &v:g[u])
            adj[v].erase(u);
    };
    remove(p[1]);

    while(pos<n)
    {
        while(st.size())
        {
            int u=st.back();
            if(adj[u].empty()) st.pop_back();
            else break;
        }

        if(st.empty())
        {
            st.push_back(p[pos+1]);
            remove(p[pos+1]);
            ++pos;
            continue;
        }

        int u=st.back();
        auto it=adj[u].find(p[pos+1]);

        if(it==adj[u].end())
        {
            ans.push_back({u,p[pos+1]});
            st.push_back(p[pos+1]);
            remove(p[pos+1]);
        }
        else
        {
            st.push_back(p[pos+1]);
            remove(p[pos+1]);
        }

        ++pos;
    }

    cout<<ans.size()<<endl;
    for(auto &[u,v]:ans)
        cout<<u<<' '<<v<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ B.cpp -O2 -o out.exe && .\out.exe < in.txt