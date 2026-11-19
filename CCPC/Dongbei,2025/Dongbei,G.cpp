#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

struct edge
{
    int u,v;
}op[MAX];

int n,m;
int deg[MAX];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        deg[u]++,deg[v]++;
    }
    queue<int>q;
    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++)
        if(deg[i]&1) q.push(i);
    while((int)q.size()>=2)
    {
        int a=q.front();q.pop();
        int b=q.front();q.pop();
        ans.push_back({a,b});
    }
    if(q.size()) ans.push_back({q.front(),q.front()});
    cout<<ans.size()<<endl;
    for(auto &[u,v]:ans)
        cout<<u<<' '<<v<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}