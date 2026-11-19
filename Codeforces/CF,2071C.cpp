#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

struct qwq
{
    int pos,dep;
    bool operator<(const qwq &a)const { return dep>a.dep; }
};

int T,n,st,ed;
int depth[MAX],f[MAX];
vector<int>p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

void dfs(int ch,int fa,vector<qwq> &op)
{
    f[ch]=fa;
    depth[ch]=depth[fa]+1;
    op.push_back({ch,depth[ch]});
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,op);
    }
}

void solve()
{
    cin>>n>>st>>ed;clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }

    vector<qwq>ans;
    dfs(ed,0,ans);
    sort(ans.begin(),ans.end());
    
    for(auto &[pos,dep]:ans)
        cout<<pos<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}