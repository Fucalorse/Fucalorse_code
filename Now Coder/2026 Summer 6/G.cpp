#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

int n,m,k;
int a[MAX];

void solve()
{
    cin>>n>>m>>k;

    vector<vector<int>>p(n+1);
    vector<bool>special(n+1,false);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }

    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        special[a[i]]=true;
    }

    auto bfs=[&]()
    {
        queue<int>q;
        vector<int>ans,cnt(n+1,0);
        vector<bool>vis(n+1,false);

        for(int i=1;i<=k;i++)
        {
            q.push(a[i]);
            vis[a[i]]=true;
        }

        while(q.size())
        {
            int u=q.front();q.pop();

            for(auto &v:p[u])
            {
                if(vis[v]) continue;

                if(++cnt[v]==2)
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }

        for(int i=1;i<=n;i++)
            if(!special[i]&&cnt[i]>=1) ans.push_back(i);

        return ans;
    };

    vector<int>ans=bfs();
    
    cout<<ans.size()<<endl;
    for(auto &cur:ans)
        cout<<cur<<' ';
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