#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,d;
int ans[MAX],depth[MAX];

void remove(set<int>& st,int up,const int &dep_cur)
{
    auto it_ed=st.lower_bound(up);
    for(auto it=it_ed;it!=st.end();++it)
        ans[*it]=depth[*it]-dep_cur;
    st.erase(it_ed,st.end());
}

void merge(set<int>& a,set<int>& b)
{
    if(a.size()<b.size()) swap(a,b);
    a.merge(b);
}

void dfs(int ch,int fa,vector<set<int>>& st,vector<vector<int>>& adj)
{
    depth[ch]=depth[fa]+1;
    if(adj[ch].empty()) return;

    int cL=adj[ch].front(),cR=adj[ch].back();
    dfs(cL,ch,st,adj);
    dfs(cR,ch,st,adj);

    int maxL=*st[cL].rbegin(),maxR=*st[cR].rbegin();
    remove(st[cL],maxR+d,depth[ch]),remove(st[cR],maxL+d,depth[ch]);
    merge(st[ch],st[cL]),merge(st[ch],st[cR]);

    // cout<<ch<<endl;
    // for(auto &cur:st[ch])
    //     cout<<cur<<' ';
    // cout<<endl;
}

void solve()
{
    cin>>n>>d;

    vector<set<int>>st(2*n+1);
    vector<vector<int>>adj(2*n+1);
    for(int round=n+1;round<=2*n-1;round++)
    {
        int u,v;
        cin>>u>>v;

        adj[round].push_back(u);
        adj[round].push_back(v);
    }

    for(int i=1;i<=n;i++)
        st[i].insert(i);

    int root=2*n-1;
    dfs(root,0,st,adj);
    for(auto &cur:st[root])
        ans[cur]=depth[cur]-1;

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}