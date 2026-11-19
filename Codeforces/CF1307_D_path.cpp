#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ovo;
const int MAX=2e5+90,inf=2e9;

struct qwq
{
    int pos,val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

bool cmp(const ovo &a,const ovo &b) { return a.second<b.second; }

int n,m,k;
int op[MAX];
bool vis[MAX];
vector<int>f,g;
vector<int>p[MAX];
vector<ovo>rest;

void bfs(const int &st,vector<int>&dist)
{
    memset(vis,false,sizeof(bool)*(n+10));
    dist.assign(n+10,inf);
    dist[st]=0;
    priority_queue<qwq>q;
    q.push({st,0});
    while(q.size())
    {
        auto [pos,val]=q.top();q.pop();
        if(vis[pos]) continue;
        vis[pos]=true;
        for(auto &to:p[pos])
        {
            if(dist[to]>dist[pos]+1)
            {
                dist[to]=dist[pos]+1;
                if(!vis[to]) q.push({to,dist[to]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
        cin>>op[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    bfs(1,f),bfs(n,g);
    for(int i=1;i<=k;i++)
        rest.emplace_back(op[i],f[op[i]]-g[op[i]]);
    sort(rest.begin(),rest.end(),cmp);
    int ans=0,maxn=-2e9;
    for(auto &[pos,val]:rest)
    {
        ans=max(ans,maxn+g[pos]+1);
        maxn=max(maxn,f[pos]);
    }
    cout<<min(ans,f[n])<<'\n';
    return 0;
}