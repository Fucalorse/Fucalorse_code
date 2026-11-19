#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=1e7,MOD=998244353;
const LL INF=1e18;

int n;
LL a[MAX];

void dfs(int ch,int fa,vector<vector<int>>& p,vector<multiset<LL>>& st)
{
    if(p[ch].empty())
    {
        st[ch].insert(a[ch]);
        return;
    }

    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        dfs(to,ch,p,st);
        
        if(st[ch].size()<st[to].size()) swap(st[ch],st[to]);
        for(auto &cur:st[to])
            st[ch].insert(cur);
        st[to].clear();
    }

    auto it=st[ch].begin();
    LL now=max(*it,a[ch]);
    st[ch].erase(it);
    st[ch].insert(now);
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<vector<int>>p(n+1);
    vector<multiset<LL>>st(n+1);
    for(int i=2;i<=n;i++)
    {
        int fa;
        cin>>fa;
        p[fa].push_back(i);
    }

    dfs(1,0,p,st);

    int leaf=0;
    multiset<LL,greater<LL>>op;
    vector<LL>ans(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(p[i].empty()) ++leaf;
        op.insert(a[i]);
    }

    LL con_st=0;
    for(auto &cur:st[1])
    {
        con_st+=cur;
        auto it=op.find(cur);
        op.erase(it);
    }

    ans[leaf]=con_st;
    for(int i=leaf+1;i<=n;i++)
    {
        auto it=op.begin();
        ans[i]=ans[i-1]+*it;
        op.erase(it);
    }

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