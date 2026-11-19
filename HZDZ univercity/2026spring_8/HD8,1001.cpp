#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=1e9;

int t,n,m;
bool vis[MAX];
int disA[MAX],disK[MAX];
vector<int>p[MAX];

void initial()
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        disA[i]=disK[i]=inf;
        p[i].clear();
    }
}

void bfs1()
{
    queue<int>q;
    q.push(1);
    disA[1]=0;
    while(q.size())
    {
        int pos=q.front();q.pop();
        for(auto &to:p[pos])
            if(disA[to]>disA[pos]+1)
            {
                disA[to]=disA[pos]+1;
                q.push(to);
            }
    }
    q.push(n);
    while(q.size())
    {
        int pos=q.front();q.pop();
        vis[pos]=true;
        for(auto &to:p[pos])
            if(disA[to]==disA[pos]-1) q.push(to);
    }
}

void bfs2()
{
    queue<int>q;
    q.push(n);
    disK[n]=0;
    while(q.size())
    {
        int pos=q.front();q.pop();
        for(auto &to:p[pos])
        {
            if(!vis[to]||(disK[pos]!=disA[to]&&disK[pos]+1!=disA[to]))
            {
                if(disK[to]>disK[pos]+1)
                {
                    disK[to]=disK[pos]+1;
                    q.push(to);
                }
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    initial();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    bfs1();

    if(disA[n]==inf)
    {
        cout<<"Arisa"<<endl;
        return;
    }

    bfs2();
    int ans=disK[1];
    for(int u=1;u<=n;u++)
    {
        if(vis[u]) continue;
        for(auto &v:p[u])
        {
            if(!vis[v]) continue;
            if(disK[u]<=disA[v]) ans=min(ans,2*disA[v]+1);
        }
    }
    if(ans>=2*disA[n]) cout<<"Arisa"<<endl;
    else cout<<"Kasumi"<<' '<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}