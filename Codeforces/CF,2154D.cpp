#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n;
int f[MAX],depth[MAX],col[MAX],deg[MAX];
vector<int>p[MAX];

void dfs(int pos,int k)
{
    col[pos]=k;
    for(auto &to:p[pos])
    {
        if(col[to]) continue;
        dfs(to,3-k);
    }
}

void clear()
{
    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        col[i]=depth[i]=deg[i]=0;
    }
}

vector<pair<int,int>> bfs()
{
    queue<int>q;
    vector<pair<int,int>>ans;
    set<int>st;
    for(int i=1;i<=n;i++)
        if(deg[i]==1&&i!=n) q.push(i);
    int now=col[1];
    while(q.size())
    {
        int pos=q.front();q.pop();
        if(pos==n) continue;
        if(col[pos]==now)
        {
            ans.push_back({1,0});
            ans.push_back({2,pos});
            now=3-now;
        }
        else
        {
            ans.push_back({1,0}),ans.push_back({1,0});
            ans.push_back({2,pos});
        }
        st.insert(pos);
        for(auto &to:p[pos])
        {
            if(st.count(to)) continue;
            if(--deg[to]==1) q.push(to);
        }
    }
    return ans;
}

void solve()
{
    cin>>n;
    clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    dfs(1,1);
    // for(int i=1;i<=n;i++)
    //     cout<<col[i]<<' ';
    // cout<<endl;
    vector<pair<int,int>>ans=bfs();
    cout<<ans.size()<<endl;
    for(auto &[opt,v]:ans)
    {
        if(opt==1) cout<<1<<endl;
        else cout<<opt<<' '<<v<<endl;
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}