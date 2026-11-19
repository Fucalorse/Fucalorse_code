#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n,m;
int c1,c2;
bool f;
vector<int>col;
vector<int>p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

void dfs(int pos,int c)
{
    col[pos]=c;
    if(c==1) c1++;
    else c2++;
    for(auto &to:p[pos])
    {
        if(col[to]==c) f=false;
        if(!col[to]) dfs(to,3-c);
    }
}

void solve()
{
    cin>>n>>m;
    clear();
    col.assign(n+3,0);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<':';
    //     for(auto &to:p[i])
    //         cout<<to<<' ';
    //     cout<<endl;
    // }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(!col[i])
        {
            c1=c2=0;
            f=true;
            dfs(i,1);
            if(f) ans+=max(c1,c2);
        }
    // for(int i=1;i<=n;i++)
    //     cout<<col[i]<<' ';
    // cout<<endl;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}