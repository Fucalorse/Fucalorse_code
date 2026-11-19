#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;

int T,n,ans=0;
int cnt[MAX],deg[MAX],f[MAX];
vector<int>p[MAX],leave;

void clear()
{
    ans=0;
    leave.clear();

    for(int i=1;i<=n;i++)
    {
        cnt[i]=deg[i]=f[i]=0;
        p[i].clear();
    }
}

void dfs(int ch,int fa)
{
    cnt[ch]=deg[ch]==1?1:0;

    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
        cnt[ch]+=cnt[to];
    }

    if((cnt[ch]&1)&&fa) ++ans;
}

void get_path(int ch,int fa)
{
    if(fa)
    {
        f[ch]=f[fa];
        if(cnt[ch]&1) f[ch]--;
        else f[ch]++;
    }

    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        get_path(to,ch);
    }
}

void solve()
{
    cin>>n;clear();

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);

        ++deg[u],++deg[v];
    }

    for(int i=1;i<=n;i++)
        if(deg[i]==1) leave.push_back(i);    

    dfs(1,0);
    // cout<<ans<<endl;

    if(leave.size()&1)
    {
        get_path(1,0);

        int dx=inf;
        for(auto &cur:leave)
            dx=min(dx,f[cur]);

        // cout<<ans<<' '<<dx<<endl;
        cout<<ans+dx<<endl;
    }
    else cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}