#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

struct ovo
{
    int u,v;
}edge[MAX];

int n,m;

void solve()
{
    cin>>n>>m;

    vector<int>indeg(n+1,0);
    vector<vector<int>>p(n+1,vector<int>{});
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;

        edge[i]={u,v};
        p[u].push_back(v);
        ++indeg[v];
    }

    auto bfs=[&]()
    {
        queue<int>q;
        vector<int>ans;

        for(int i=1;i<=n;i++)
            if(indeg[i]==0) q.push(i);
        
        while(q.size())
        {
            int u=q.front();q.pop();
            ans.push_back(u);

            for(auto &v:p[u])
                if(--indeg[v]==0) q.push(v);
        }

        return ans;
    };

    vector<int>id=bfs();
    // for(auto &cur:id)
    //     cout<<cur<<' ';
    // cout<<endl;

    if((int)id.size()!=n)
    {
        cout<<2<<endl;
        for(int i=1;i<=n;i++)
            cout<<i<<' ';
        cout<<endl;
        for(int i=n;i>=1;i--)
            cout<<i<<' ';
        cout<<endl;
    }
    else
    {
        cout<<1<<endl;
        for(auto &cur:id)
            cout<<cur<<' ';
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}