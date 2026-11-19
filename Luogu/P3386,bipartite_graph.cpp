#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=510;

int n,m,e;
int match[MAX];
bool vis[MAX];
vector<int>p[MAX];

bool dfs(int pos)
{
    if(vis[pos]) return false;
    vis[pos]=true;
    for(auto &to:p[pos])
        if(!match[to]||dfs(match[to]))
        {
            match[to]=pos;
            return true;
        }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>e;
    for(int i=1;i<=e;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(vis,false,sizeof(bool)*(n+3));
        if(dfs(i)) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}