#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+10;

int t,n,k;
int sz[MAX],f[MAX];
vector<int>p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

int dfs(int ch,int fa)
{
    f[ch]=fa;
    sz[ch]=1;
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        sz[ch]+=dfs(to,ch);
    }
    return sz[ch];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            p[u].push_back(v);
            p[v].push_back(u);
        }
        dfs(1,0);
        // cout<<endl;
        // for(int i=1;i<=n;i++)
        //     cout<<i<<' '<<sz[i]<<endl;
        // cout<<endl;
        LL ans=n;
        for(int i=1;i<=n;i++)
        {
            if(sz[i]>=k) ans+=n-sz[i];
            for(auto &to:p[i])
            {
                if(to==f[i]) continue;
                if(n-sz[to]>=k) ans+=sz[to];
                // cout<<to<<' '<<sz[to]<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}