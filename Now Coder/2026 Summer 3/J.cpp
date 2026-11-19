#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

struct qwq
{
    int pos,dep;
    bool operator<(const qwq &a)const
    {
        if(dep!=a.dep) return dep>a.dep;
        return pos<a.pos;
    }
};

int n,q;
int depth[MAX],cost[MAX],father[MAX];

void dfs(int ch,int fa,vector<vector<int>> &p)
{
    depth[ch]=depth[fa]+1;

    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,p);
    }
}

void merge(set<qwq> &a,set<qwq> &b,int now_dep)
{
    if(a.size()<b.size()) swap(a,b);

    for(auto it=b.begin();it!=b.end();++it)
        if(it->dep<now_dep) a.insert(*it);

    b.clear();
}

void peach(int ch,int fa,vector<set<qwq>> &st,vector<vector<int>> &p)
{
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        peach(to,ch,st,p);
    }

    if(st[ch].empty()) father[ch]=ch==1?0:1;
    else
    {
        auto it1=st[ch].begin();
        auto [pos,dep]=*it1;
        father[ch]=pos;
        st[ch].erase(it1);

        merge(st[pos],st[ch],depth[pos]);
    }
}

void solve()
{
    cin>>n>>q;

    vector<vector<int>>p(n+1);
    for(int i=2;i<=n;i++)
    {
        int fa;
        cin>>fa;
        p[fa].push_back(i);
    }

    depth[0]=-1;
    dfs(1,0,p);

    vector<set<qwq>>st(n+1);
    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        st[u].insert({v,depth[v]});
    }

    peach(1,0,st,p);

    // for(int i=1;i<=n;i++)
    //     cout<<cost[i]<<" ";
    // cout<<endl;

    LL ans=0;
    for(int i=2;i<=n;i++)
    {
        cost[i]=cost[father[i]]+1;
        ans+=cost[i];
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}