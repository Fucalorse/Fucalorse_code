#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=18,INF=2e9;

int T,n;
int fa[MAX],sz[MAX],a[MAX];
set<int>pre[MAX],to[MAX];

int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

void clear()
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i,sz[i]=1;
        pre[i].clear(),to[i].clear();
    }
}

void bfs()
{
    queue<pair<int,int>>q;
    for(int i=1;i<=n;i++)
        if((int)pre[i].size()==1) q.push({i,*pre[i].begin()});

    auto merge=[&](int x,int y)
    {
        x=find(x),y=find(y);

        if(x==y) return;

        if((int)to[x].size()>(int)to[y].size())
        {
            swap(x,y);
            swap(pre[x],pre[y]);
        }

        fa[x]=y;
        sz[y]+=sz[x];

        for(auto &cur:to[x])
        {
            int v=find(cur);
            if(v==y) continue;

            pre[v].erase(x);
            pre[v].insert(y);
            to[y].insert(v);

            if((int)pre[v].size()==1) q.push({v,*pre[v].begin()});
        }

        to[y].erase(x);
    };

    while(q.size())
    {
        auto [u,v]=q.front();q.pop();
        merge(u,v);
    }
}

void solve(int ID)
{
    cin>>n;clear();

    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;

        for(int j=1;j<=k;j++)
        {
            cin>>a[j];
            pre[i].insert(a[j]);
            to[a[j]].insert(i);
        }
    }

    bfs();

    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,sz[find(i)]);

    printf("Case #%d: %d\n",ID,ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    for(int i=1;i<=T;i++)
        solve(i);

    return 0;
}