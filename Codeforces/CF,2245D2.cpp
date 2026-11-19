#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9,LEN=30;

struct qwq
{
    int to,opt;
};

int T,n,m;
int a[MAX],ans[MAX];

void solve()
{
    cin>>n>>m;

    vector<vector<qwq>>p(n+1);
    vector<array<int,3>>deg(n+1);
    for(int i=1;i<=m;i++)
    {
        int opt,u,v;
        cin>>opt>>u>>v;
        p[u].push_back({v,opt});
        p[v].push_back({u,opt});
        deg[u][opt]++,deg[v][opt]++;
    }

    int cnt=0,tot=n;
    queue<pair<int,int>>q;
    vector<bool>vis(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(deg[i][1]==0) q.push({i,2}),vis[i]=true;
        else if(deg[i][2]==0) q.push({i,1}),vis[i]=true;
    }

    while(q.size())
    {
        auto [u,opt]=q.front();q.pop();

        if(opt==1) ans[u]=tot;
        else ans[u]=-tot;
        ++cnt,--tot;

        for(auto &[v,nopt]:p[u])
        {
            --deg[v][nopt];
            if(!vis[v])
            {
                if(deg[v][1]==0) q.push({v,2}),vis[v]=true;
                else if(deg[v][2]==0) q.push({v,1}),vis[v]=true;
            }
        }
    }

    if(cnt!=n)
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}