#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+10,inf=2e9;

struct qwq
{
    int pos,id;
    bool operator<(const qwq &a)const { return id>a.id; }
};

int t,n,m;
vector<int>f;
vector<bool>vis;
vector<int>p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

void bfs()
{
    f.assign(n+5,0);
    vis.assign(n+5,false);
    priority_queue<qwq>q;
    for(int i=1;i<=n;i++)
        f[i]=i;
    q.push({1,1});
    while(q.size())
    {
        auto [pos,id]=q.top();q.pop();
        if(vis[pos]) continue;
        // cout<<pos<<' '<<f[pos]<<endl;
        vis[pos]=true;
        for(auto &to:p[pos])
        {
            if(!vis[to])
            {
                f[to]=max(f[to],id);
                q.push({to,f[to]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        clear();
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            // cout<<u<<' '<<v<<endl;
            p[u].push_back(v);
        }
        bfs();
        for(int i=1;i<=n;i++)
            cout<<(vis[i]?f[i]:-1)<<' ';
        cout<<endl;
    }
    return 0;
}