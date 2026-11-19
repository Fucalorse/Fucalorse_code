#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353;
const LL INF=1e18;

int n,m;
LL k;

vector<vector<LL>> bfs(vector<vector<int>>& p)
{
    queue<pair<int,int>>q;
    vector<vector<LL>>dist(n+1,vector<LL>(2,INF));
    q.push({1,0}),dist[1][0]=0;

    while(q.size())
    {
        auto [pos,col]=q.front();q.pop();

        for(auto &to:p[pos])
            if(dist[to][col^1]>dist[pos][col]+1)
            {
                dist[to][col^1]=dist[pos][col]+1;
                q.push({to,col^1});
            }
    }

    return dist;
}

void solve()
{
    cin>>n>>m>>k;

    vector<vector<int>>p(n+1);
    vector<bool>loop(n+1,false);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);

        if(u==v) loop[u]=true;
    }

    auto dist=bfs(p);

    for(int i=1;i<=n;i++)
    {
        LL d0=dist[i][0],d1=dist[i][1],ans=INF;
        // cout<<d0<<' '<<d1<<endl;
        
        if(d0!=INF)
        {
            LL con0=(d0+k-1)/k*k;
            if((con0-d0)&1) con0+=k;
            ans=min(ans,con0);
        }

        if(d1!=INF&&(k&1))
        {
            LL con1=(d1+k-1)/k*k;
            if((con1-d1)&1) con1+=k;
            ans=min(ans,con1);
        }

        if(loop[i])
        {
            if(d0!=INF)
            {
                LL con0=(d0+k-1)/k*k;
                ans=min(ans,con0);
            }
            if(d1!=INF)
            {
                LL con1=(d1+k-1)/k*k;
                ans=min(ans,con1);
            }
        }

        if(ans==INF) cout<<-1<<' ';
        else cout<<ans<<' ';
    }
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