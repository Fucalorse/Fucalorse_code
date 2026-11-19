#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int n,m;
int indeg[MAX],cnt[MAX];
double dp[MAX];
vector<pair<int,int>>p[MAX];
queue<int>q;

void bfs()
{
    q.push(n);
    while(q.size())
    {
        int u=q.front();q.pop();
        for(auto &[v,val]:p[u])
        {
            dp[v]+=(double)(dp[u]+val)/cnt[v];
            if(--indeg[v]==0) q.push(v);
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        p[v].push_back({u,val});
        indeg[u]++;
        cnt[u]++;
    }
    bfs();
    cout<<fixed<<setprecision(2)<<dp[1]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}