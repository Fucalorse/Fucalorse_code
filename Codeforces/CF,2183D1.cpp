#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n,maxn;
int f[MAX],depth[MAX];
vector<int>p[MAX],op[MAX];

void clear()
{
    maxn=0;
    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        op[i].clear();
    }
}

void dfs(int ch,int fa)
{
    f[ch]=fa;
    depth[ch]=depth[fa]+1;
    op[depth[ch]].push_back(ch);
    maxn=max(maxn,depth[ch]);
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
    }
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
    }
    dfs(1,0);
    int ans=1;
    for(int i=1;i<=maxn;i++)
    {
        set<int>st;
        for(auto &to:op[i])
            st.insert(f[to]);
        if(st.size()>=2) ans=max(ans,(int)op[i].size());
        else ans=max(ans,(int)op[i].size()+1);
    }
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