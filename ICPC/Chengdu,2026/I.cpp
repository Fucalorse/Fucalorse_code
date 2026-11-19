#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m,timer;
int a[MAX],b[MAX],pos[MAX];

void clear()
{
    for(int i=1;i<=2*n;i++)
    {
        a[i]=b[i]=0;
        pos[i]=0;
    }
}

void dfs(int ch,int fa,vector<vector<int>>& adj)
{
    a[ch]=++timer;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,adj);
    }

    ++timer;
}

void solve1()
{
    cin>>n>>m;clear();

    vector<vector<int>>adj(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    timer=0;
    for(int i=1;i<=n;i++)
        if(!a[i]) dfs(i,0,adj);

    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}

void solve2()
{
    cin>>n;clear();

    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        pos[b[i]]=i;
    }

    vector<int>st;
    vector<pair<int,int>>edge;
    for(int i=1;i<=2*n;i++)
    {
        if(pos[i]!=0) st.push_back(pos[i]);
        else
        {
            int ch=st.back();st.pop_back();
            if(st.size())
            {
                int fa=st.back();
                edge.push_back({fa,ch});
            }
        }
    }

    cout<<edge.size()<<endl;
    for(auto &[u,v]:edge)
        cout<<u<<' '<<v<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    string s;
    cin>>s;

    if(s=="cat")
    {
        int T=1;
        cin>>T;
        while(T--) solve1();
    }
    else
    {
        int T;
        cin>>T;
        while(T--) solve2();
    }

    return 0;
}